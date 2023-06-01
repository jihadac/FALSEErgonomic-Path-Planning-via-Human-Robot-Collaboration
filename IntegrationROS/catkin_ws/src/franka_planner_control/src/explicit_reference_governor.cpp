#include <franka_planner_control/explicit_reference_governor.h>

#include "pseudo_inversion.h"

using namespace std;
namespace franka_planner_control {

void ExplicitReferenceGovernor::setReferences(std::array<double,7> &q_r_arg, std::array<double,7> &q_v_arg){
	for(int i=0; i<7; i++){
    q_r_[i] = q_r_arg[i];
	  q_v_[i] = q_v_arg[i];
  }
}

geometry_msgs::Pose ExplicitReferenceGovernor::transformFromJointToTaskSpace(std::array<double,7> &q){
  Eigen::Matrix<double, 3,3 > rotationmatrix_ee;
  for(int i=0; i<3; i++){
    rotationmatrix_ee(0,i) = model_handle_->getPose(franka::Frame::kEndEffector, q, state_handle_->getRobotState().F_T_EE , state_handle_->getRobotState().EE_T_K)[4*i];
    rotationmatrix_ee(1,i) = model_handle_->getPose(franka::Frame::kEndEffector, q, state_handle_->getRobotState().F_T_EE , state_handle_->getRobotState().EE_T_K)[4*i+1];
    rotationmatrix_ee(2,i) = model_handle_->getPose(franka::Frame::kEndEffector, q, state_handle_->getRobotState().F_T_EE , state_handle_->getRobotState().EE_T_K)[4*i+2];
  }
  Eigen::Quaterniond quat_ee = Eigen::Quaterniond(rotationmatrix_ee);
  Eigen::Matrix<double, 3, 1> p_ee;
  for(int i=0; i<3; i++){
    p_ee[i] = model_handle_->getPose(franka::Frame::kEndEffector, q, state_handle_->getRobotState().F_T_EE , state_handle_->getRobotState().EE_T_K)[12+i];
  }

  geometry_msgs::Pose x_ee; 
  x_ee.position.x = p_ee[0];
  x_ee.position.y = p_ee[1];
  x_ee.position.z = p_ee[2];
  x_ee.orientation.x = quat_ee.coeffs()[0];
  x_ee.orientation.y = quat_ee.coeffs()[1];
  x_ee.orientation.z = quat_ee.coeffs()[2];
  x_ee.orientation.w = quat_ee.coeffs()[3];

  return x_ee;
}

void ExplicitReferenceGovernor::addSkeletonsToObstaclesInERG(){
  // ROS_INFO_STREAM("in addSkeletonsToObstaclesInERG");

  int i_sphere = number_of_spheres_ /*+ number_of_moveit_spheres_*/;
  int i_cylinder = number_of_cylinders_ /*+ number_of_moveit_cylinders_*/;
  
  double obst_sphere_radius;
  Eigen::Matrix<double, 3, 1> obst_sphere_center; 

  double obst_cylinder_radius;
  Eigen::Matrix<double, 3, 1> obst_cylinder_startpoint;
  Eigen::Matrix<double, 3, 1> obst_cylinder_endpoint; 
  
  for(int j=0; j<skeleton_joint_positions_.size(); j++){
    
    /* add spheres */ 
    for(int k=0; k<3; k++){
      if(k==0){ // head
        obst_sphere_radius = (skeleton_joint_positions_[j][0] - skeleton_joint_positions_[j][1]).norm(); 
        obst_sphere_center = (skeleton_joint_positions_[j][16] - skeleton_joint_positions_[j][17])/2;
      }
      if(k==1){ // right hand
        obst_sphere_radius = 0.07;
        obst_sphere_center = skeleton_joint_positions_[j][4] + obst_sphere_radius* (skeleton_joint_positions_[j][4] - skeleton_joint_positions_[j][3])/(skeleton_joint_positions_[j][4] - skeleton_joint_positions_[j][3]).norm();
      }
      if(k==2){ // left hand
        obst_sphere_radius = 0.07;
        obst_sphere_center = skeleton_joint_positions_[j][7] + obst_sphere_radius* (skeleton_joint_positions_[j][7] - skeleton_joint_positions_[j][6])/(skeleton_joint_positions_[j][7] - skeleton_joint_positions_[j][6]).norm();
      }
      sphere_centers_.block(0,i_sphere,3,1) = obst_sphere_center;
      sphere_radii_(i_sphere) = obst_sphere_radius;

      i_sphere++; 
    }

    /* add cylinders */
    for(int k=0; k<5; k++){
      if(k==0){ // body
        obst_cylinder_radius = (skeleton_joint_positions_[j][8]-skeleton_joint_positions_[j][11]).norm()/2; 
        obst_cylinder_startpoint = skeleton_joint_positions_[j][1]; 
        obst_cylinder_endpoint = (skeleton_joint_positions_[j][8]+skeleton_joint_positions_[j][11])/2; 
      }
      if(k==1){ // upper right arm
        obst_cylinder_radius = 0.05; 
        obst_cylinder_startpoint = skeleton_joint_positions_[j][2]; 
        obst_cylinder_endpoint = skeleton_joint_positions_[j][3];
      }
      if(k==2){ // lower right arm
        obst_cylinder_radius = 0.05; 
        obst_cylinder_startpoint = skeleton_joint_positions_[j][3]; 
        obst_cylinder_endpoint = skeleton_joint_positions_[j][4]; 
      }
      if(k==3){ // upper left arm
        obst_cylinder_radius = 0.05; 
        obst_cylinder_startpoint = skeleton_joint_positions_[j][5]; 
        obst_cylinder_endpoint = skeleton_joint_positions_[j][6]; 
      }
      if(k==4){ // lower left arm
        obst_cylinder_radius = 0.05; 
        obst_cylinder_startpoint = skeleton_joint_positions_[j][6]; 
        obst_cylinder_endpoint = skeleton_joint_positions_[j][7]; 
      }
      cylinder_startendpoints_.block(0,i_cylinder,3,1) = obst_cylinder_startpoint; 
      cylinder_startendpoints_.block(3,i_cylinder,3,1) = obst_cylinder_endpoint; 
      cylinder_radii_(i_cylinder) = obst_cylinder_radius;

      i_cylinder++; 
    }
  }
}

std::array<double, 7> ExplicitReferenceGovernor::referenceSelector(int start_index){
  /* initialize planning scene and robot model for collision detection 
  --------------------------------------------------------------------- */
  planning_scene_monitor::LockedPlanningSceneRW psm_rw(psm_); // RW = READ-WRITE
  psm_rw->getCurrentStateNonConst().update();
  planning_scene::PlanningScenePtr scene = psm_rw->diff();
  scene->decoupleParent(); 

  robot_model::RobotModelConstPtr robot_model = scene->getRobotModel();
  const robot_state::JointModelGroup* joint_model_group = robot_model->getJointModelGroup("panda_arm");
  robot_state::RobotState predicted_applied_robot_state = scene->getCurrentStateNonConst();  
  const std::vector<int>& idx = joint_model_group->getVariableIndexList();


  /* if new MoveIt trajectory received 
  ------------------------------------ */
  if (size_trajectory_ >0){
    trajectory_index_ = start_index; //3; //0;
    end_traj_time_ = robot_trajectory_.joint_trajectory.points[size_trajectory_-1].time_from_start.toSec();
    
    size_trajectory_ = 0; // reset trajectory size 
  }

  /* loop over trajectory till the end 
  ------------------------------------- */ 
  if(trajectory_index_ < robot_trajectory_.joint_trajectory.points.size()){
    q_v_pred_ = q_v_; // initialize q_v_pred_ to the current q_v_ 
    for(int i=0; i<7; i++){
      q_r_next_[i] = robot_trajectory_.joint_trajectory.points[trajectory_index_].positions[i]; 
    }
    
    /* transform to Eigen to compute norm */
    Eigen::Matrix<double,7,1> q_r_next;
    Eigen::Matrix<double,7,1> q_v_pred;
    for(int i=0; i<7; i++){
      q_r_next[i] = q_r_next_[i];
      q_v_pred[i] = q_v_pred_[i];
    }

    if(trajectory_index_==0){
      q_r_ = q_r_next_;
      trajectory_index_ += 1;
    }
    else{
      int iteration = 0;
      while((q_r_next-q_v_pred).norm()>0.01){
        /* simulate system kinematics of the applied reference */
        dq_v_pred_  = kappa_selector_*(q_r_next - q_v_pred);
        q_v_pred = q_v_pred + dq_v_pred_*pred_sampling_time_selector_;
        
        /* check for collisions between q_v_pred and static obstacles */
        for(int i=0; i<idx.size(); i++){
          predicted_applied_robot_state.setVariablePosition(idx[i],q_v_pred[i]);
          // std::array<double,7> q = state_handle_->getRobotState().q;
          // predicted_applied_robot_state.setVariablePosition(idx[i],q[i]);
        }
        predicted_applied_robot_state.update(true);
        collision_result_.clear();
        psm_rw->checkCollision(collision_request_,collision_result_,predicted_applied_robot_state);
        if(collision_result_.collision){
          ROS_INFO_STREAM("Given state is " << (collision_result_.collision ? "in" : "not in") << " collision");
          break;
        }
        /* if q_v_pred not in collision and close to q_r_next, then send q_r_next_ to ERG */
        if((q_r_next-q_v_pred).norm()<0.01){
          q_r_ = q_r_next_;
          trajectory_index_ += 1;
        }
        iteration +=1;
      }
    }    
    // ROS_INFO_STREAM("trajectory_index_ : " << trajectory_index_);
  }
  return q_r_;
}

std::array<double, 7> ExplicitReferenceGovernor::referenceEndTrajectoryFromMoveIt(){
  /* if new MoveIt trajectory received 
  ------------------------------------ */
  if (size_trajectory_ >0){
    trajectory_index_ = size_trajectory_-1; 
    for(int i=0; i<7; i++){
      q_r_next_[i] = robot_trajectory_.joint_trajectory.points[trajectory_index_].positions[i]; 
    }  
    q_r_ = q_r_next_;  
    size_trajectory_ = 0; // reset trajectory size 
  }
  return q_r_;
}


void ExplicitReferenceGovernor::navigationField(){
  /* start the chrono */
	start_NF_ = std::chrono::system_clock::now(); 

  /* joint space reference and applied joint space reference are known
  because of setReferences done before calling the navigationField function */

	/* compute joint positions of applied robot configuration */
  panda_q_v_positions_ = getJointPositions(q_v_);

  /* compute attraction field */
  Eigen::Matrix<double,7,1> q_r;
  Eigen::Matrix<double,7,1> q_v;
  for(int i=0; i<7; i++){
    q_r[i] = q_r_[i];
    q_v[i] = q_v_[i];
  }
  rho_att_ = (q_r-q_v)/std::max((q_r-q_v).norm(),eta_);

  /* compute joint angle repulsion field (q) */
  for(int i=0; i<7; i++){
    rho_rep_q_[i] = std::max((zeta_q_-std::abs(q_v_[i]-q_lowerlimit_[i]))/(zeta_q_-delta_q_),0.0) - std::max((zeta_q_-std::abs(q_v_[i]-q_upperlimit_[i]))/(zeta_q_-delta_q_),0.0);
  }

  /* compute pseudo inverse Jacobians */
  getPseudoInvJacQv();

  /* compute wall repulsion field (w) */
  if(number_of_walls_ >0){
    getRhoWall(); // updates rho_rep_wall_
  }

  /* compute spherical obstacle repulsion field (s) */
  if((number_of_spheres_ + 3*skeleton_joint_positions_.size() ) >0){
    lambda_q_v_ = getLambda(panda_q_v_positions_);
    Pij_q_v_ = getPij(panda_q_v_positions_, lambda_q_v_);
    getRhoSphere(); // updates rho_rep_sphere_
  }

  /* compute cylindrical repulsion field (c) */
  if((number_of_cylinders_ + 5*skeleton_joint_positions_.size() ) >0){
    std::tie(Sij_q_v_,Tij_q_v_,mu_q_v_) = getMuSijTij(panda_q_v_positions_);
    getRhoCylinder();  // updates rho_rep_cylinder_
  }

  /* total navigation field */
  rho_ = rho_att_ + rho_rep_q_;
  if(number_of_walls_ >0){
    rho_ += rho_rep_wall_;
  }
  if((number_of_spheres_ + 3*skeleton_joint_positions_.size() ) >0){
    rho_ += rho_rep_sphere_;
  }
  if((number_of_cylinders_ + 5*skeleton_joint_positions_.size() ) >0){
    rho_ += rho_rep_cylinder_;
  }

  /* end the chrono and compute the NF computational time */
	end_NF_ = std::chrono::system_clock::now(); 
  computationaltime_NF_ = end_NF_ - start_NF_;
	computationaltime_msg_.NF = computationaltime_NF_.count();
}


void ExplicitReferenceGovernor::trajectoryBasedDSM(){
  /* initialize trajectory predictions computational message */ 
  computationaltime_msg_.trajectory_predictions = 0.0;
  
  /* start the chrono */
  start_DSM_ = std::chrono::system_clock::now(); 

  /* save the time stamp of the DSM, trajectory predictions, and distance to constraints messages */
  DSM_msg_.time = elapsed_time_.toSec();
  trajpred_msg_.time = elapsed_time_.toSec();
  disttoconstr_msg_.time = elapsed_time_.toSec();

  /* initialization */
  q_pred_ = state_handle_->getRobotState().q;
  dq_pred_ = state_handle_->getRobotState().dq;
  I_total_pred_ = state_handle_->getRobotState().I_total;
  m_total_pred_ = state_handle_->getRobotState().m_total;
  F_x_Ctotal_pred_ = state_handle_->getRobotState().F_x_Ctotal;
  mass_pred_ = model_handle_->getMass(q_pred_,I_total_pred_,m_total_pred_,F_x_Ctotal_pred_);
  coriolis_pred_= model_handle_->getCoriolis(q_pred_,dq_pred_,I_total_pred_,m_total_pred_,F_x_Ctotal_pred_);
  gravity_pred_ = model_handle_->getGravity(q_pred_,m_total_pred_,F_x_Ctotal_pred_);

  /* compute and save the current distance to constraints */
  std::array<double, 7> tau;
  for(int i=0; i<7;i++){
    tau[i] = state_handle_->getRobotState().tau_J[i];
  }
  distance_to_tau_ = DSMtau(tau);
  distance_to_dotq_ = DSMdotq(dq_pred_);
  distance_to_q_ = DSMq(q_pred_);
  distance_to_dotp_EE_ = DSMdotpEE(q_pred_, dq_pred_);
  DSMwall();      // updates DSM_wall_sample_
  distance_to_wall_ = DSM_wall_sample_; 
  DSMsphere();    // updates DSM_sphere_sample_
  distance_to_sphere_ = DSM_sphere_sample_;
  DSMcylinder();  // updates DSM_cylinder_sample_
  distance_to_cylinder_ = DSM_cylinder_sample_;

  /* compute trajectory prediction thread to compute "next" prediction sample 
  and save "current" prediction variables */
  getTrajectoryPrediction();
  q_pred_ = q_pred_next_;
  dq_pred_ = dq_pred_next_; 
  ddq_pred_ = ddq_pred_next_;
  tau_pred_ = tau_pred_next_;
  gravity_pred_ = gravity_pred_next_;

  for(int k=0; k<pred_samples_; k++){
    /* save "current" prediction variables */
    for (size_t i = 0; i < 7; ++i) {
      int index = i+7*k;
      trajpred_msg_.q_pred[index] = q_pred_[i];
      trajpred_msg_.dotq_pred[index] = dq_pred_[i];
      trajpred_msg_.ddotq_pred[index] = ddq_pred_[i];
      trajpred_msg_.tau_pred[index] = tau_pred_[i];
    }

    /* compute DSM tau */
    double DSM_tau_element = DSMtau(tau_pred_);
    if (k==0){
      DSM_tau_ = kappa_tau_*DSM_tau_element;
    }
    else{
      DSM_tau_ = std::min(DSM_tau_,kappa_tau_*DSM_tau_element);
    }

    /* compute DSM dotq */
    double DSM_dotq_element = DSMdotq(dq_pred_);
    if (k==0){
      DSM_dotq_ = kappa_dotq_*DSM_dotq_element;
    }
    else{
      DSM_dotq_ = std::min(DSM_dotq_,kappa_dotq_*DSM_dotq_element);
    }

    /* compute DSM q */
    double DSM_q_element = DSMq(q_pred_);
    if (k==0){
      DSM_q_ = kappa_q_*DSM_q_element;
    }
    else{
      DSM_q_ = std::min(DSM_q_,kappa_q_*DSM_q_element);
    }

    /* compute DSM cartesian velocity (end-effector) constraint */
    double DSM_dotp_EE_element = DSMdotpEE(q_pred_, dq_pred_);
    if (k==0){
      DSM_dotp_EE_ = kappa_dotp_EE_*DSM_dotp_EE_element;
    }
    else{
      DSM_dotp_EE_ = std::min(DSM_dotp_EE_,kappa_dotp_EE_*DSM_dotp_EE_element);
    }

    /* compute DSM wall  */ 
    if((number_of_walls_ /*+ number_of_moveit_walls_*/) >0){
      DSMwall();
      if (k==0){
        DSM_wall_ = kappa_wall_*DSM_wall_sample_;
      }
      else{
        DSM_wall_ = std::min(DSM_wall_,kappa_wall_*DSM_wall_sample_);
      }
    }

    /*  DSM sphere */ 
    if((number_of_spheres_ /*+ number_of_moveit_spheres_  */+ 3*skeleton_joint_positions_.size() ) >0){
      DSMsphere();
      if (k==0){
        DSM_sphere_ = kappa_sphere_*DSM_sphere_sample_;
      }
      else{
        DSM_sphere_ = std::min(DSM_sphere_,kappa_sphere_*DSM_sphere_sample_);
      }
    }
    /* DSM cylinder */ 
    if((number_of_cylinders_ /*+ number_of_moveit_cylinders_*/ + 5*skeleton_joint_positions_.size() ) >0){
      DSMcylinder();
      if (k==0){
        DSM_cylinder_ = kappa_cylinder_*DSM_cylinder_sample_;
      }
      else{
        DSM_cylinder_ = std::min(DSM_cylinder_,kappa_cylinder_*DSM_cylinder_sample_);
      }
    }

    /* compute "next" prediction sample and save "current" prediction variables */
    if (0<=k<pred_samples_-1){
      getTrajectoryPrediction();
      q_pred_ = q_pred_next_;
      dq_pred_ = dq_pred_next_; 
      ddq_pred_ = ddq_pred_next_;
      tau_pred_ = tau_pred_next_;
      gravity_pred_ = gravity_pred_next_;
    }

    /* compute terminal energy constraint */
    if (k == pred_samples_-1){
      terminalenergy_ = getClosedLoopEnergy();
      distance_to_terminalenergy_ = energy_limit_-terminalenergy_;
      DSM_terminalenergy_ = kappa_energy_*distance_to_terminalenergy_;
    }
  }
  /* compute total DSM */
  DSM_ = std::min(DSM_tau_,DSM_dotq_);
  DSM_ = std::min(DSM_,DSM_q_);
  DSM_ = std::min(DSM_,DSM_dotp_EE_);
  DSM_ = std::min(DSM_,DSM_terminalenergy_);
  if((number_of_walls_ /*+ number_of_moveit_walls_*/)>0){     
    DSM_ = std::min(DSM_,DSM_wall_);
  }
  if((number_of_spheres_ /*+ number_of_moveit_spheres_ */+ 3*skeleton_joint_positions_.size())>0){     
    DSM_ = std::min(DSM_,DSM_sphere_);
  }
  if((number_of_cylinders_ /*+ number_of_moveit_cylinders_*/ + 5*skeleton_joint_positions_.size())>0){     
    DSM_ = std::min(DSM_,DSM_cylinder_);
  }
  DSM_ = std::max(DSM_,0.0);

  /* end the chrono and compute the DSM computational time */
  end_DSM_ = std::chrono::system_clock::now();
  computationaltime_DSM_ = end_DSM_ - start_DSM_;
  computationaltime_msg_.DSM = computationaltime_DSM_.count();

  /* DSM message */ 
  DSM_msg_.tau = DSM_tau_;
  DSM_msg_.dotq = DSM_dotq_;
  DSM_msg_.q = DSM_q_;
  DSM_msg_.dotp_EE = DSM_dotp_EE_;
  DSM_msg_.terminalenergy = DSM_terminalenergy_;
  DSM_msg_.wall = DSM_wall_;
  DSM_msg_.sphere = DSM_sphere_;
  DSM_msg_.cylinder = DSM_cylinder_;
  DSM_msg_.DSM = DSM_;
  DSM_publisher_.publish(DSM_msg_);

  /* TrajectoryPredictions message */
  trajpredictions_publisher_.publish(trajpred_msg_); 

  /* DistanceToConstraints message */
  disttoconstr_msg_.tau = distance_to_tau_;
  disttoconstr_msg_.dotq = distance_to_dotq_;
  disttoconstr_msg_.q = distance_to_q_;
  disttoconstr_msg_.dotp_EE = distance_to_dotp_EE_;
  disttoconstr_msg_.terminal_energy = distance_to_terminalenergy_;
  disttoconstr_msg_.wall = distance_to_sphere_;
  disttoconstr_msg_.sphere = distance_to_wall_;
  disttoconstr_msg_.cylinder = distance_to_cylinder_;
  distancetoconstraints_publisher_.publish(disttoconstr_msg_); 
}

/* The function getJointPositions returns the Cartesian positions (x,y,z) of 6 joints
  for the joint configuration q_argument */
Eigen::Matrix<double, 3, 4> ExplicitReferenceGovernor::getJointPositions(std::array<double,7>& q_argument){
  Eigen::Matrix<double, 3,4 > panda_jointpositions;
  /* the function getPose returns the homogeneous transformation matrix (4x4) in column format (16x1)
  	 for the joint positions we only need the 12th, 13th, and 14th element of this column */
  for(int i=0; i<3; i++){
    /* here we need kJoint1 to compute lambda between kJoint1 and kJoint3 in next steps
    no kJoint2 because position kJoint2 = position kJoint1
    no kJoint4 because will be taken into account in radius of link from kJoint3 to kJoint5
    no kJoint6 because position kJoint6 = position kJoint5
    no kJoint7 because will be taken into account in radius of link from kJoint6 to kEndEffector */
    panda_jointpositions(i,0) = model_handle_->getPose(franka::Frame::kJoint1, q_argument, state_handle_->getRobotState().F_T_EE , state_handle_->getRobotState().EE_T_K)[12+i];
    panda_jointpositions(i,1) = model_handle_->getPose(franka::Frame::kJoint3, q_argument, state_handle_->getRobotState().F_T_EE , state_handle_->getRobotState().EE_T_K)[12+i];
    panda_jointpositions(i,2) = model_handle_->getPose(franka::Frame::kJoint5, q_argument, state_handle_->getRobotState().F_T_EE , state_handle_->getRobotState().EE_T_K)[12+i];
    panda_jointpositions(i,3) = model_handle_->getPose(franka::Frame::kEndEffector, q_argument, state_handle_->getRobotState().F_T_EE , state_handle_->getRobotState().EE_T_K)[12+i];
  }
  return panda_jointpositions;
}

/* The function getLambda returns the parametrization factor lambda for link i wrt spherical obstacle j */
Eigen::Matrix<double, 3, 10> ExplicitReferenceGovernor::getLambda(Eigen::Matrix<double, 3 ,4>& panda_jointpositions){
  Eigen::Matrix<double, 3, 10> lambda;  // size =(#links, #spheres)
  for (int i=0; i<panda_jointpositions.cols()-1;i++) { // #joints-1 (-1, because in code +1 to denote next joint)
    double denum = (panda_jointpositions.col(i+1) - panda_jointpositions.col(i)).dot(panda_jointpositions.col(i+1) - panda_jointpositions.col(i));
    for (int j=0; j<(number_of_spheres_ /*+ number_of_moveit_spheres_ */+ 3*skeleton_joint_positions_.size()); j++) {  // #spĥeres   
      // NOTE: in case two consecutive frames are at the same position, lambda = NaN due to division by zero  
      // add if (denum <= 0.001) { lambda(i,j) = 0; }
      // here frames are chosen such that their positions cannot be the same
      lambda(i,j) = (panda_jointpositions.col(i+1)-panda_jointpositions.col(i)).dot(sphere_centers_.col(j)-panda_jointpositions.col(i))/denum;
      if (lambda(i,j) < 0) {
        lambda(i,j) = 0;
      }
      else if(lambda(i,j) >1) {
        lambda(i,j) = 1;
      }
    }       
  }
  return lambda; 
}

/* The function getPij returns the position on link i that is closest to the center of sphere j */
Eigen::Matrix<double, 9, 10> ExplicitReferenceGovernor::getPij(Eigen::Matrix<double, 3, 4>& panda_jointpositions, Eigen::Matrix<double, 3, 10>& lambda){
  Eigen::Matrix<double, 9, 10> Pij; 
  for (int j=0; j<(number_of_spheres_ /*+ number_of_moveit_spheres_ */+ 3*skeleton_joint_positions_.size()); j++){ // #spheres
    for (int i=0; i<panda_jointpositions.cols()-1;i++){ // #links
      Pij.block(3*i,j,3,1) = panda_jointpositions.col(i) + lambda(i,j) * (panda_jointpositions.col(i+1)-panda_jointpositions.col(i)); 
    }
  }
  return Pij;
}

/* The function getMuSijTij returns the parametrization factor mu for link i wrt cylindrical obstacle j 
and returns the positions of the closest distance between link i and cylinder j */
std::tuple<Eigen::Matrix<double,9,20>,Eigen::Matrix<double,9,20>,Eigen::Matrix<double,3,20>> ExplicitReferenceGovernor::getMuSijTij(Eigen::Matrix<double, 3, 4>& panda_jointpositions){
  Eigen::Matrix<double, 9, 20> Sij; 
  Eigen::Matrix<double, 9, 20> Tij;
  Eigen::Matrix<double, 3, 20> mu_final;

  double mu;  
  double nu;
  Eigen::Matrix<double, 3, 1> a;
  Eigen::Matrix<double, 3, 1> b;
  Eigen::Matrix<double, 3, 1> c_0;
  Eigen::Matrix<double, 3, 1> c_1;
  Eigen::Matrix<double, 3, 1> cylinder_start;
  Eigen::Matrix<double, 3, 1> cylinder_end;

  for (int i=0; i<panda_jointpositions.cols()-1;i++) {// #joints-1 (-1, because in code +1 to denote next joint)
    a = panda_jointpositions.col(i+1)-panda_jointpositions.col(i); 
    for (int j=0; j<(number_of_cylinders_ /*+ number_of_moveit_cylinders_ */+ 5*skeleton_joint_positions_.size() ); j++){ // # obstacles
      cylinder_start = cylinder_startendpoints_.block(0,j,3,1); 
      cylinder_end = cylinder_startendpoints_.block(3,j,3,1); 

      b = cylinder_end - cylinder_start;
      c_0 = cylinder_start - panda_jointpositions.col(i);
      c_1 = cylinder_end - panda_jointpositions.col(i);

      // CASE OF PARALLEL SEGMENTS 
      if ( ((a/a.norm()).cross(b/b.norm())).norm() < 0.001 ) 
      {
        double d_0 = (a/a.norm()).dot(c_0); 
        double d_1 = (a/a.norm()).dot(c_1);

        if(d_0<=0.0 && d_1<=0.0) // cylinder before link in z-direction (viewpoint of panda_jointpositions.col(i) to panda_jointpositions.col(i+1))
        {
          mu = 0.0; // mu = 0, Sij = panda_jointpositions.col(i) 
          if (std::abs(d_0) < std::abs(d_1))
          {
            nu = 0.0; // nu = 0, Tij = cylinder_start 
          }
          else if(std::abs(d_0) > std::abs(d_1))
          {
            nu = 1.0; // nu = 1, Tij = cylinder_end 
          }
        }
        else if(d_0>=a.norm() && d_1>=a.norm()) // cylinder after link in z-direction (viewpoint of panda_jointpositions.col(i) to panda_jointpositions.col(i+1))
        {
          mu = 1.0; // mu = 1, Sij = panda_jointpositions.col(i+1) 
          if (std::abs(d_0)<std::abs(d_1))
          {
            nu = 0.0; // nu = 0, Tij = cylinder_start 
          }
          else if(std::abs(d_0)>std::abs(d_1))
          {
            nu = 1.0; // nu = 1, Tij = cylinder_end 
          }
        }
        else // cylinder and link (partly) overlapping in z-direction
        {
          double nu_parallel = (b.dot((panda_jointpositions.col(i)+panda_jointpositions.col(i+1))/2-cylinder_start))/(b.dot(b));
          if (0.0<=nu_parallel && nu_parallel <=1.0) 
          { 
            mu = 0.5; // mu =0.5, Sij = (panda_jointpositions.col(i)+panda_jointpositions.col(i+1))/2
            nu = nu_parallel; // nu computed as in point-line case
          }
          else if(0.0<=d_0 && d_0<=a.norm()) // = if nu_parallel < 0
          {
            if (d_1>a.norm())
            {
              mu = 1.0; // mu = 1, Sij = panda_jointpositions.col(i+1) 
              nu = (b.dot(panda_jointpositions.col(i+1)-cylinder_start))/(b.dot(b)); // nu computed as in point-line case
            }
            else if(d_1 < 0.0)
            {
              mu = 0.0; // mu = 0, Sij = panda_jointpositions.col(i) 
              nu = (b.dot(panda_jointpositions.col(i)-cylinder_start))/(b.dot(b)); // nu computed as in point-line case
            }
          }
          else if (0.0<=d_1 && d_1<=a.norm()) // % = if nu_parallel > 1
          {
            if (d_0>a.norm())
            {
              mu = 1.0; // mu = 1, Sij = panda_jointpositions.col(i+1) 
              nu = (b.dot(panda_jointpositions.col(i+1)-cylinder_start))/(b.dot(b)); // nu computed as in point-line case
            }
            else if (d_0 < 0.0)
            {
              mu = 0.0; // mu = 0, Sij = panda_jointpositions.col(i) 
              nu = (b.dot(panda_jointpositions.col(i)-cylinder_start))/(b.dot(b)); // nu computed as in point-line case
            }
          }                 
        }
        Sij.block(3*i,j,3,1) = panda_jointpositions.col(i) + mu * (panda_jointpositions.col(i+1)-panda_jointpositions.col(i));
        Tij.block(3*i,j,3,1) = cylinder_start + nu * (cylinder_end-cylinder_start);  
      }

      // CASE OF NON-PARALLEL SEGMENTS (SKEW/CUTTING)
      else {
        mu = (b.dot(b)*c_0.dot(a)-c_0.dot(b)*b.dot(a))/(b.dot(b)*a.dot(a)-a.dot(b)*b.dot(a)); // mu computed for skew line-line case
        nu = (a.dot(a)/b.dot(a)) * (b.dot(b)*c_0.dot(a)-c_0.dot(b)*b.dot(a))/(b.dot(b)*a.dot(a)-b.dot(a)*b.dot(a))-(c_0.dot(a)/b.dot(a)); // nu computed for skew line-line case
        if ( (mu >=0.0 && mu<=1.0) && (nu>=0.0 && nu<=1.0) ){ // mu in [0,1] and nu in [0,1]
          Sij.block(3*i,j,3,1) = panda_jointpositions.col(i) + mu * (panda_jointpositions.col(i+1)-panda_jointpositions.col(i));
          Tij.block(3*i,j,3,1) = cylinder_start + nu * (cylinder_end-cylinder_start);
        }
        else if ( (mu<0.0 || mu>1.0) && (nu>=0.0 && nu<=1.0) ){ // mu not in [0,1] and nu in [0,1]
          if (mu<0.0){
            mu = 0.0;
          }
          else if (mu>1.0){
            mu = 1.0; 
          }
          Sij.block(3*i,j,3,1) = panda_jointpositions.col(i) + mu * (panda_jointpositions.col(i+1)-panda_jointpositions.col(i));
          Eigen::Matrix<double, 3, 1> Sij_vec = Sij.block(3*i,j,3,1);
          nu = (b.dot(Sij_vec-cylinder_start))/(b.dot(b)); // nu computed as in point-line case   
          if(nu<0.0){
            nu = 0.0;
          }
          else if (nu>1.0){
            nu = 1.0;
          }
          Tij.block(3*i,j,3,1) = cylinder_start + nu * (cylinder_end-cylinder_start);
        }
        else if ( (mu >=0.0 && mu<=1.0) && (nu<0.0 || nu>1.0) ){ // mu in [0,1] and nu not in [0,1]
          if (nu<0.0){
            nu = 0.0;
          }
          else if (nu>1.0){
            nu = 1.0;
          }
          Tij.block(3*i,j,3,1) = cylinder_start + nu * (cylinder_end-cylinder_start);
          Eigen::Matrix<double, 3, 1> Tij_vec = Tij.block(3*i,j,3,1);
          mu = (a.dot(Tij_vec-panda_jointpositions.col(i)))/(a.dot(a)); // mu computed as in point-line case
          Sij.block(3*i,j,3,1) = panda_jointpositions.col(i) + mu * (panda_jointpositions.col(i+1)-panda_jointpositions.col(i));
        }
        else { // mu not in [0,1] and nu not in [0,1]
          double nu_for_mu0 = (b.dot(panda_jointpositions.col(i)-cylinder_start))/(b.dot(b)); // nu computed as in point-line case 
          double nu_for_mu1 = (b.dot(panda_jointpositions.col(i+1)-cylinder_start))/(b.dot(b)); // nu computed as in point-line case   
          if(nu_for_mu0<0.0){
            nu_for_mu0 = 0.0;
          }
          else if(nu_for_mu0>1.0){
            nu_for_mu0 = 1.0;
          }
          if(nu_for_mu1<0.0){
            nu_for_mu1 = 0.0;
          }
          else if(nu_for_mu1>1.0){
            nu_for_mu1 = 1.0;
          }    
          Eigen::Matrix<double, 3, 1> Tij_for_mu0 = cylinder_start + nu_for_mu0 * (cylinder_end-cylinder_start);
          Eigen::Matrix<double, 3, 1> Tij_for_mu1 = cylinder_start + nu_for_mu1 * (cylinder_end-cylinder_start);
          if( (panda_jointpositions.col(i)-Tij_for_mu0).norm() < (panda_jointpositions.col(i+1)-Tij_for_mu1).norm() ){
            mu = 0.0;
            Sij.block(3*i,j,3,1) = panda_jointpositions.col(i);
            Tij.block(3*i,j,3,1) = Tij_for_mu0;
          }
          else{
            mu = 1.0;
            Sij.block(3*i,j,3,1) = panda_jointpositions.col(i+1);
            Tij.block(3*i,j,3,1) = Tij_for_mu1;
          }
        }
      }
      mu_final(i,j) = mu;
    }
  }
  return {Sij, Tij, mu_final}; 
}

/* The function getPseudoInvJacQv updates the pseudo inverse of the Jacobians computed for configuration q_v */
void ExplicitReferenceGovernor::getPseudoInvJacQv(){ 
  // compute the Jacobinas of frame 3, 4, 5, 7, end-effector
  // we don't compute the Jacobian of frame 1 and 2 since no joints can influence the positions of frame 1 and 2
  // we don't compute the Jacobian of frame 6 because same as (position) Jacobian of frame 5
  // we don't need the orientations of the joints, we only need the positions and so only position part of Jacobianlook 
  std::array<double, 42> joint3_jacobian_array =
      model_handle_->getZeroJacobian(franka::Frame::kJoint3, q_v_, state_handle_->getRobotState().F_T_EE, state_handle_->getRobotState().EE_T_K);
  std::array<double, 42> joint4_jacobian_array =
      model_handle_->getZeroJacobian(franka::Frame::kJoint4, q_v_, state_handle_->getRobotState().F_T_EE, state_handle_->getRobotState().EE_T_K);
  std::array<double, 42> joint5_jacobian_array =
      model_handle_->getZeroJacobian(franka::Frame::kJoint5, q_v_, state_handle_->getRobotState().F_T_EE, state_handle_->getRobotState().EE_T_K);
  std::array<double, 42> joint6_jacobian_array =
      model_handle_->getZeroJacobian(franka::Frame::kJoint6, q_v_, state_handle_->getRobotState().F_T_EE, state_handle_->getRobotState().EE_T_K);
  std::array<double, 42> joint7_jacobian_array =
      model_handle_->getZeroJacobian(franka::Frame::kJoint7, q_v_, state_handle_->getRobotState().F_T_EE, state_handle_->getRobotState().EE_T_K);
  std::array<double, 42> endeffector_jacobian_array =
      model_handle_->getZeroJacobian(franka::Frame::kEndEffector, q_v_, state_handle_->getRobotState().F_T_EE, state_handle_->getRobotState().EE_T_K);

  // transform jacobian (42 x 1) array to (6 x7 )matrix form 
  Eigen::Map<Eigen::Matrix<double, 6, 7> > joint3_jacobian(joint3_jacobian_array.data());
  Eigen::Map<Eigen::Matrix<double, 6, 7> > joint4_jacobian(joint4_jacobian_array.data());
  Eigen::Map<Eigen::Matrix<double, 6, 7> > joint5_jacobian(joint5_jacobian_array.data());
  Eigen::Map<Eigen::Matrix<double, 6, 7> > joint6_jacobian(joint6_jacobian_array.data());
  Eigen::Map<Eigen::Matrix<double, 6, 7> > joint7_jacobian(joint7_jacobian_array.data());
  Eigen::Map<Eigen::Matrix<double, 6, 7> > endeffector_jacobian(endeffector_jacobian_array.data());
  
  // compute pseudo inverse Jacobians
  // // method 1
  // Eigen::Matrix<double, 7, 6> pinv_joint3_jacobian = joint3_jacobian.block(0,0,6,7).completeOrthogonalDecomposition().pseudoInverse();
  // // method 2
  pseudoInverse(joint3_jacobian, joint3_jacobian_pinv_);
  pseudoInverse(joint4_jacobian, joint4_jacobian_pinv_);
  pseudoInverse(joint5_jacobian, joint5_jacobian_pinv_);
  pseudoInverse(joint6_jacobian, joint6_jacobian_pinv_);
  pseudoInverse(joint7_jacobian, joint7_jacobian_pinv_);
  pseudoInverse(endeffector_jacobian, endeffector_jacobian_pinv_);
}

/* The function getRhoWall updates rho_rep_wall_ */ 
void ExplicitReferenceGovernor::getRhoWall(){
  Eigen::Matrix<double,7,1> num; 
  double denum; 
  Eigen::Matrix<double,7,1> rho_ij_unit; 
  Eigen::Matrix<double,7,1> rho_ij; 
  rho_ij_unit.setZero();
  rho_ij.setZero();
  rho_rep_wall_.setZero();
  for (int j=0; j<(number_of_walls_/*+number_of_moveit_walls_*/); j++){ // # walls
    // compute the repulsion field in task space
    // v_wall_ij = - wall_normal -> already integrated in computation rho_ij_unit
    Eigen::Matrix<double, 3, 1> wall_normal = wall_normals_.block(0,j,3,1);  

    int i = 1; // kJoint3
    num = joint3_jacobian_pinv_.block(0,0,7,3)*(-wall_normal);  // transform the repulsion field in task space to joint space 
    denum = std::max(num.norm(),0.001); // transform the repulsion field in task space to joint space
    rho_ij_unit = num/denum; // direction in joint space with amplitude 1
    rho_ij = std::max((zeta_wall_-((wall_distances_(j)-panda_link_radii_(i-1))-wall_normal.transpose().dot(panda_q_v_positions_.col(i))))/(zeta_wall_-delta_wall_),0.0) * rho_ij_unit;  // direction in joint space with amplitude [0,1] ~ [zeta,delta]
    rho_rep_wall_ += rho_ij; // sum over links i and because of for loop over spheres j

    i = 2; // kJoint5
    num = joint5_jacobian_pinv_.block(0,0,7,3)*(-wall_normal);  // transform the repulsion field in task space to joint space 
    denum = std::max(num.norm(),0.001); // transform the repulsion field in task space to joint space
    rho_ij_unit = num/denum; // direction in joint space with amplitude 1
    rho_ij = std::max((zeta_wall_-((wall_distances_(j)-panda_link_radii_(i-1))-wall_normal.transpose().dot(panda_q_v_positions_.col(i))))/(zeta_wall_-delta_wall_),0.0) * rho_ij_unit;  // direction in joint space with amplitude [0,1] ~ [zeta,delta]
    rho_rep_wall_ += rho_ij; // sum over links i and because of for loop over spheres j

    i = 3; // kEndEffector
    num = endeffector_jacobian_pinv_.block(0,0,7,3)*(-wall_normal);  // transform the repulsion field in task space to joint space 
    denum = std::max(num.norm(),0.001); // transform the repulsion field in task space to joint space
    rho_ij_unit = num/denum; // direction in joint space with amplitude 1
    rho_ij = std::max((zeta_wall_-((wall_distances_(j)-panda_link_radii_(i-1))-wall_normal.transpose().dot(panda_q_v_positions_.col(i))))/(zeta_wall_-delta_wall_),0.0) * rho_ij_unit;  // direction in joint space with amplitude [0,1] ~ [zeta,delta]
    rho_rep_wall_ += rho_ij; // sum over links i and because of for loop over spheres j

    // if (rho_rep_wall_.norm() >0){
    //   ROS_INFO_STREAM("norm of rep wall: " << rho_rep_wall_.norm());
    //   i=1;
    //   ROS_INFO_STREAM("kJoint3: " << std::max((zeta_wall_-((wall_distances_(j)-panda_link_radii_(i-1))-wall_normal.transpose().dot(panda_q_v_positions_.col(1))))/(zeta_wall_-delta_wall_),0.0));
    //   i=2;
    //   ROS_INFO_STREAM("kJoint5: " << std::max((zeta_wall_-((wall_distances_(j)-panda_link_radii_(i-1))-wall_normal.transpose().dot(panda_q_v_positions_.col(2))))/(zeta_wall_-delta_wall_),0.0));
    //   i=3;
    //   ROS_INFO_STREAM("kEndEffector: " << std::max((zeta_wall_-((wall_distances_(j)-panda_link_radii_(i-1))-wall_normal.transpose().dot(panda_q_v_positions_.col(3))))/(zeta_wall_-delta_wall_),0.0) << "\n");
    // }
  }
}

/* The function getRhoSphere updates rho_rep_sphere_ */ 
void ExplicitReferenceGovernor::getRhoSphere(){
  // ROS_INFO_STREAM("number of skeletons in getRhoSphere: " << skeleton_joint_positions_.size());

  Eigen::Matrix<double, 3, 1> pijmincj;
  Eigen::Matrix<double,7,1> num; 
  double denum; 
  Eigen::Matrix<double,7,1> rho_ij_unit; 
  Eigen::Matrix<double,7,1> rho_ij; 
  rho_ij_unit.setZero();
  rho_ij.setZero();
  rho_rep_sphere_.setZero();

  /* don't take into account the MoveIt spheres */
  for (int j=0/*number_of_moveit_spheres_*/; j<(number_of_spheres_ + /*number_of_moveit_spheres_*/ + 3*skeleton_joint_positions_.size() ); j++){ // #spheres
  
    int i = 0; // link between kJoint1 and kJoint3
    pijmincj = Pij_q_v_.block(3*i,j,3,1) - sphere_centers_.block(0,j,3,1);  // compute repulsion field in task space
    num = lambda_q_v_(i,j) * joint3_jacobian_pinv_.block(0,0,7,3) * pijmincj;  // transform the repulsion field in task space to joint space 
    denum = std::max(num.norm(),0.001); // transform the repulsion field in task space to joint space
    rho_ij_unit = num/denum; // direction in joint space with amplitude 1
    rho_ij = std::max((zeta_sphere_-(pijmincj.norm()-sphere_radii_(j)-panda_link_radii_(i)))/(zeta_sphere_-delta_sphere_),0.0) * rho_ij_unit;  // direction in joint space with amplitude [0,1] ~ [zeta,delta]
    rho_rep_sphere_ += rho_ij; // sum over links i and because of for loop over spheres j

    i = 1; // link between kJoint3 and kJoint5
    pijmincj = Pij_q_v_.block(3*i,j,3,1) - sphere_centers_.block(0,j,3,1); 
    num = ((1-lambda_q_v_(i,j)) * joint3_jacobian_pinv_.block(0,0,7,3) + lambda_q_v_(i,j) * joint5_jacobian_pinv_.block(0,0,7,3))*pijmincj;
    denum = std::max(num.norm(),0.001);
    rho_ij_unit = num/denum; 
    rho_ij = std::max((zeta_sphere_-(pijmincj.norm()-sphere_radii_(j)-panda_link_radii_(i)))/(zeta_sphere_-delta_sphere_),0.0) * rho_ij_unit; 
    rho_rep_sphere_ += rho_ij;

    i = 2; // link between kJoint5 and kEndEffector 
    pijmincj = Pij_q_v_.block(3*i,j,3,1) - sphere_centers_.block(0,j,3,1); 
    num = ((1-lambda_q_v_(i,j)) * joint5_jacobian_pinv_.block(0,0,7,3) + lambda_q_v_(i,j) * endeffector_jacobian_pinv_.block(0,0,7,3))*pijmincj;
    denum = std::max(num.norm(),0.001);
    rho_ij_unit = num/denum; 
    rho_ij = std::max((zeta_sphere_-(pijmincj.norm()-sphere_radii_(j)-panda_link_radii_(i)))/(zeta_sphere_-delta_sphere_),0.0) * rho_ij_unit; 
    rho_rep_sphere_ += rho_ij;

    // if (rho_rep_sphere_.norm() >0){
    //   ROS_INFO_STREAM("norm of rep sphere: " << rho_rep_sphere_.norm());
    //   i=0;
    //   pijmincj = Pij_q_v_.block(3*i,j,3,1) - sphere_centers_.block(0,j,3,1); 
    //   ROS_INFO_STREAM("pijmincj: " << pijmincj.norm());
    //   ROS_INFO_STREAM("pij: \n" << Pij_q_v_.block(3*i,j,3,1));
    //   ROS_INFO_STREAM("cj: \n" << sphere_centers_.block(0,j,3,1));
    //   ROS_INFO_STREAM("zeta-delta: " << zeta_sphere_-delta_sphere_);
    //   ROS_INFO_STREAM(" pijmincj - rj - rlink: " << pijmincj.norm()-sphere_radii_(j)-panda_link_radii_(i));
    //   ROS_INFO_STREAM("kJoint1-kJoint3: " << std::max((zeta_sphere_-(pijmincj.norm()-sphere_radii_(j)-panda_link_radii_(i)))/(zeta_sphere_-delta_sphere_),0.0) << "\n");
    //   pijmincj = Pij_q_v_.block(3*1,j,3,1) - sphere_centers_.block(0,j,3,1); 
    //   i=1;
    //   ROS_INFO_STREAM("kJoint3-kJoint5: " << std::max((zeta_sphere_-(pijmincj.norm()-sphere_radii_(j)-panda_link_radii_(i)))/(zeta_sphere_-delta_sphere_),0.0));
    //   pijmincj = Pij_q_v_.block(3*2,j,3,1) - sphere_centers_.block(0,j,3,1); 
    //   i=2;
    //   ROS_INFO_STREAM("kJoint5-kEndEffector: " << std::max((zeta_sphere_-(pijmincj.norm()-sphere_radii_(j)-panda_link_radii_(i)))/(zeta_sphere_-delta_sphere_),0.0) << "\n");
    // }
  } 
}

/* The function getRhoCylinder updates rho_rep_sphere_ */ 
void ExplicitReferenceGovernor::getRhoCylinder(){
  // ROS_INFO_STREAM("number of skeletons in getRhoCylinder: " << skeleton_joint_positions_.size());

  Eigen::Matrix<double, 3, 1> sijmintij;
  Eigen::Matrix<double,7,1> num; 
  double denum; 
  Eigen::Matrix<double,7,1> rho_ij_unit; 
  Eigen::Matrix<double,7,1> rho_ij; 
  Eigen::Matrix<double,7,1> rho_rep_percylinder;
  rho_ij_unit.setZero();
  rho_ij.setZero();
  rho_rep_cylinder_.setZero();

  /* don't take into account the MoveIt cylinders */
  for (int j=0/*number_of_moveit_cylinders_*/; j<(number_of_cylinders_ /*+ number_of_moveit_cylinders_ */+  5*skeleton_joint_positions_.size() ); j++){ // #cylinders
    rho_rep_percylinder.setZero();

    int i = 0; // link between kJoint1 and kJoint3
    sijmintij = Sij_q_v_.block(3*i,j,3,1) - Tij_q_v_.block(3*i,j,3,1);  // compute repulsion field in task space
    num = mu_q_v_(i,j) * joint3_jacobian_pinv_.block(0,0,7,3) * sijmintij;  // transform the repulsion field in task space to joint space 
    denum = std::max(num.norm(),0.001); // transform the repulsion field in task space to joint space
    rho_ij_unit = num/denum; // direction in joint space with amplitude 1
    rho_ij = std::max((zeta_cylinder_-(sijmintij.norm()-cylinder_radii_(j)-panda_link_radii_(i)))/(zeta_cylinder_-delta_cylinder_),0.0) * rho_ij_unit;  // direction in joint space with amplitude [0,1] ~ [zeta,delta]
    rho_rep_percylinder += rho_ij;
    rho_rep_cylinder_ += rho_ij; // sum over links i and because of for loop over spheres j

    i = 1; // link between kJoint3 and kJoint5
    sijmintij = Sij_q_v_.block(3*i,j,3,1) - Tij_q_v_.block(3*i,j,3,1);  
    num = ((1-mu_q_v_(i,j)) * joint3_jacobian_pinv_.block(0,0,7,3) + mu_q_v_(i,j) * joint5_jacobian_pinv_.block(0,0,7,3))*sijmintij;
    denum = std::max(num.norm(),0.001);
    rho_ij_unit = num/denum; 
    rho_ij = std::max((zeta_cylinder_-(sijmintij.norm()-cylinder_radii_(j)-panda_link_radii_(i)))/(zeta_cylinder_-delta_cylinder_),0.0) * rho_ij_unit; 
    rho_rep_percylinder += rho_ij;
    rho_rep_cylinder_ += rho_ij;

    i = 2; // link between kJoint5 and kEndEffector 
    sijmintij = Sij_q_v_.block(3*i,j,3,1) - Tij_q_v_.block(3*i,j,3,1);  
    num = ((1-mu_q_v_(i,j)) * joint5_jacobian_pinv_.block(0,0,7,3) + mu_q_v_(i,j) * endeffector_jacobian_pinv_.block(0,0,7,3))*sijmintij;
    denum = std::max(num.norm(),0.001);
    rho_ij_unit = num/denum; 
    rho_ij = std::max((zeta_cylinder_-(sijmintij.norm()-cylinder_radii_(j)-panda_link_radii_(i)))/(zeta_cylinder_-delta_cylinder_),0.0) * rho_ij_unit;
    rho_rep_percylinder += rho_ij;
    rho_rep_cylinder_ += rho_ij;

    double cylindrical_circulationgain = 1.0; //0.0; //1.0;
    num = joint6_jacobian_pinv_.block(0,3,7,1); // same as pinv(J_EE)*{0,0,1}^{T}
    denum = std::max(num.norm(),0.001);
    rho_ij_unit = num/denum;
    // if (rho_rep_percylinder.norm()>0){
    //   rho_ij = cylindrical_circulationgain * rho_ij_unit;
    // }
    rho_ij = cylindrical_circulationgain * rho_rep_percylinder.norm() * rho_ij_unit;
    rho_ij[4] = 0.0;
    rho_rep_cylinder_ += rho_ij;

    // if (rho_rep_cylinder_.norm() >0){
    //   ROS_INFO_STREAM("norm of rep cylinder: " << rho_rep_cylinder_.norm());
    //   i=0;
    //   sijmintij = Sij_q_v_.block(3*i,j,3,1) - Tij_q_v_.block(3*i,j,3,1);  
    //   ROS_INFO_STREAM("kJoint1-kJoint3: " << std::max((zeta_cylinder_-(sijmintij.norm()-cylinder_radii_(j)-panda_link_radii_(i)))/(zeta_cylinder_-delta_cylinder_),0.0));
    //   i=1;
    //   sijmintij = Sij_q_v_.block(3*i,j,3,1) - Tij_q_v_.block(3*i,j,3,1);  
    //   ROS_INFO_STREAM("kJoint3-kJoint5: " << std::max((zeta_cylinder_-(sijmintij.norm()-cylinder_radii_(j)-panda_link_radii_(i)))/(zeta_cylinder_-delta_cylinder_),0.0));
    //   i=2;
    //   sijmintij = Sij_q_v_.block(3*i,j,3,1) - Tij_q_v_.block(3*i,j,3,1);  
    //   ROS_INFO_STREAM("kJoint5-kEndEffector: " << std::max((zeta_cylinder_-(sijmintij.norm()-cylinder_radii_(j)-panda_link_radii_(i)))/(zeta_cylinder_-delta_cylinder_),0.0) << "\n");
    // }
  } 
}

void ExplicitReferenceGovernor::getTrajectoryPrediction(){
  start_pred_ = std::chrono::system_clock::now(); 

  mass_pred_ = model_handle_->getMass(q_pred_,I_total_pred_,m_total_pred_,F_x_Ctotal_pred_);
  coriolis_pred_= model_handle_->getCoriolis(q_pred_,dq_pred_,I_total_pred_,m_total_pred_,F_x_Ctotal_pred_);
  gravity_pred_next_ = model_handle_->getGravity(q_pred_,m_total_pred_,F_x_Ctotal_pred_);

  for(int i=0; i<7;i++){
    tau_pred_next_[i] = Kp_[i]*(q_v_[i]-q_pred_[i]) - Kd_[i]*dq_pred_[i] + gravity_pred_next_[i];
    // adding computed friction or inertial torque gives unstable predictions -- PROBLEM!!
    // tau_pred_[i] = Kp_[i]*(q_r_[i]-q_pred_[i]) - Kd_[i]*dq_pred_[i] + gravity_pred_[i] + friction_pred_[i]; 
    // tau_pred_[i] = Kp_[i]*(q_r_[i]-q_pred_[i]) - Kd_[i]*dq_pred_[i] + gravity_pred_[i] + inertialtorque_pred_[i];
  }
    
  arma_mass_pred_ = stdToArmaMatrix(mass_pred_);
  arma_coriolis_pred_ = stdToArmaVector(coriolis_pred_);
  arma_gravity_pred_ = stdToArmaVector(gravity_pred_next_);
  arma_tau_pred_ = stdToArmaVector(tau_pred_next_);

  arma_ddq_pred_ = arma::solve(arma_mass_pred_, arma_tau_pred_-arma_coriolis_pred_-arma_gravity_pred_, arma::solve_opts::likely_sympd + arma::solve_opts::fast);
  ddq_pred_next_ = armaToStdVector(arma_ddq_pred_);

  /* Simplectic Euler */
  for(int i=0; i<7; i++){
    dq_pred_next_[i] = dq_pred_[i] + ddq_pred_next_[i]*pred_samplingtime_;
    q_pred_next_[i] = q_pred_[i] + dq_pred_next_[i]*pred_samplingtime_;
  }

  end_pred_ = std::chrono::system_clock::now();
  computationaltime_pred_ = end_pred_ - start_pred_;
  computationaltime_msg_.trajectory_predictions += computationaltime_pred_.count();
}

double ExplicitReferenceGovernor::getClosedLoopEnergy(){
  double closed_loop_energy;

  Eigen::Map<Eigen::Matrix<double, 7, 7> > mass_matrix_eigen(mass_pred_.data());
  Eigen::Map<Eigen::Matrix<double, 7, 1> > dotq_eigen(dq_pred_.data());
  Eigen::Map<Eigen::Matrix<double, 7, 1> > q_eigen(q_pred_.data());
  Eigen::Map<Eigen::Matrix<double, 7, 1> > q_v_eigen(q_v_.data());
  Eigen::Matrix<double,7,7> Kp_matrix;
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 7; j++) {
      if(i==j){
        Kp_matrix(i,j) = Kp_[i];
      }
      else{
        Kp_matrix(i,j) = 0.0;
      }
    }
  } 

  closed_loop_energy = 0.5*dotq_eigen.transpose()*mass_matrix_eigen*dotq_eigen;
  closed_loop_energy += 0.5*(q_v_eigen-q_eigen).transpose()*Kp_matrix*(q_v_eigen-q_eigen);

  return closed_loop_energy;
}

double ExplicitReferenceGovernor::DSMtau(std::array<double, 7>& tau_pred){
  double DSM_tau;
  for(int i=0; i<7; i++){
    double DSM_tau_lowerlimit = tau_pred[i] - (1.0+delta_tau_)*(-tau_limit_[i]);
    double DSM_tau_upperlimit = (1.0-delta_tau_)*tau_limit_[i] - tau_pred[i];
    double DSM_tau_temp = std::min(DSM_tau_lowerlimit,DSM_tau_upperlimit);
    if (i==0){
      DSM_tau = DSM_tau_temp;
    }
    else{
      DSM_tau = std::min(DSM_tau,DSM_tau_temp);
    }
  }
  return DSM_tau;
}

double ExplicitReferenceGovernor::DSMdotq(std::array<double, 7>& dotq_pred){
  double DSM_dotq;
  for(int i=0; i<7; i++){
    double DSM_dotq_lowerlimit = dotq_pred[i] - (1.0+delta_dotq_)*(-dotq_limit_[i]);
    double DSM_dotq_upperlimit = (1.0-delta_dotq_)*dotq_limit_[i] - dotq_pred[i];
    double DSM_dotq_temp = std::min(DSM_dotq_lowerlimit,DSM_dotq_upperlimit);
    if (i==0){
      DSM_dotq = DSM_dotq_temp;
    }
    else{
      DSM_dotq = std::min(DSM_dotq,DSM_dotq_temp);
    }
  }
  return DSM_dotq;
}

double ExplicitReferenceGovernor::DSMq(std::array<double, 7>& q_pred){
  double DSM_q;
  for(int i=0; i<6; i++){ // don't take into account end-effector joint
    double DSM_q_lowerlimit = q_pred[i] - (1.0+delta_q_)*q_lowerlimit_[i];
    double DSM_q_upperlimit = (1.0-delta_q_)*q_upperlimit_[i] - q_pred[i];
    double DSM_q_temp = std::min(DSM_q_lowerlimit,DSM_q_upperlimit);
    if (i==0){
      DSM_q = DSM_q_temp;
    }
    else{
      DSM_q = std::min(DSM_q,DSM_q_temp);
    }
  }
  return DSM_q;
}

double ExplicitReferenceGovernor::DSMdotpEE(std::array<double, 7>& q_pred, std::array<double, 7>& dotq_pred){
  double DSM_dotp_EE;
  double DSM_dotp_EE_lowerlimit;
  double DSM_dotp_EE_upperlimit;
  
  std::array<double, 42> endeffector_jacobian_array =
      model_handle_->getZeroJacobian(franka::Frame::kEndEffector, q_pred, state_handle_->getRobotState().F_T_EE, state_handle_->getRobotState().EE_T_K);
  Eigen::Map<Eigen::Matrix<double, 6, 7> > endeffector_jacobian(endeffector_jacobian_array.data());
  Eigen::Map<Eigen::Matrix<double, 7, 1> > dotq_pred_eigen(dotq_pred.data());
  Eigen::Matrix<double,6,1> dotp_EE = endeffector_jacobian*dotq_pred_eigen;
  for(int i=0; i<6; i++){
    if(i<3){
      DSM_dotp_EE_lowerlimit = dotp_EE(i) - (1.0+delta_dotp_EE_)*(-dotp_EE_limit_[0]);
      DSM_dotp_EE_upperlimit = (1.0+delta_dotp_EE_)*dotp_EE_limit_[0] - dotp_EE(i) ;  
    }
    else{
      DSM_dotp_EE_lowerlimit = dotp_EE(i) - (1.0+delta_dotp_EE_)*(-dotp_EE_limit_[1]);
      DSM_dotp_EE_upperlimit = (1.0+delta_dotp_EE_)*dotp_EE_limit_[1] - dotp_EE(i) ;  
    }
    double DSM_dotp_EE_temp = std::min(DSM_dotp_EE_lowerlimit,DSM_dotp_EE_upperlimit);
    if (i==0){
      DSM_dotp_EE = DSM_dotp_EE_temp;
    }
    else{
      DSM_dotp_EE = std::min(DSM_dotp_EE,DSM_dotp_EE_temp);
    }
  }
  return DSM_dotp_EE;
}

void ExplicitReferenceGovernor::DSMwall(){
  double DSM_wall_temp; 
  panda_q_pred_positions_ = getJointPositions(q_pred_);
  for (int j=0; j<(number_of_walls_/*+number_of_moveit_walls_*/); j++) { 
    for(int i=0; i<panda_q_pred_positions_.cols()-1; i++){
      Eigen::Matrix<double, 3, 1> wall_normal = wall_normals_.block(0,j,3,1); 
      DSM_wall_temp = (wall_distances_(j)-panda_link_radii_(i))-wall_normal.transpose().dot(panda_q_pred_positions_.col(i+1)); 
      if (i==0 && j==0){
        DSM_wall_sample_ = DSM_wall_temp;
      }
      else{
        DSM_wall_sample_ = std::min(DSM_wall_sample_,DSM_wall_temp);
      }
    }
  }
}

void ExplicitReferenceGovernor::DSMsphere(){
  panda_q_pred_positions_ = getJointPositions(q_pred_);
  lambda_q_pred_ = getLambda(panda_q_pred_positions_);
  Pij_q_pred_ = getPij(panda_q_pred_positions_, lambda_q_pred_);

  for(int i=0; i<Pij_q_pred_.rows()/3; i++){
    for (int j=0; j<(number_of_spheres_ /*+ number_of_moveit_spheres_ */+ 3*skeleton_joint_positions_.size() ); j++) { 
      // double DSM_sphere_temp = (Pij_q_pred_.block(3*i,j,3,1)-obst_sphere1_center_).norm() - (1+delta_sphere_)*obst_sphere1_radius_;
      double DSM_sphere_temp = (Pij_q_pred_.block(3*i,j,3,1)-sphere_centers_.block(0,j,3,1)).norm() - sphere_radii_(j)- panda_link_radii_(i);
      if (i==0 && j==0){
        DSM_sphere_sample_ = DSM_sphere_temp;
      }
      else{
        DSM_sphere_sample_ = std::min(DSM_sphere_sample_,DSM_sphere_temp);
      }
    }
  }
}

void ExplicitReferenceGovernor::DSMcylinder(){
  panda_q_pred_positions_ = getJointPositions(q_pred_);
  std::tie(Sij_q_pred_,Tij_q_pred_,mu_q_pred_) = getMuSijTij(panda_q_pred_positions_);
  for(int i=0; i<Sij_q_pred_.rows()/3; i++){
    for (int j=0; j<(number_of_cylinders_ /*+ number_of_moveit_cylinders_ */+ 5*skeleton_joint_positions_.size() ); j++) { 
      double DSM_cylinder_temp = (Sij_q_pred_.block(3*i,j,3,1)-Tij_q_pred_.block(3*i,j,3,1)).norm() - cylinder_radii_(j) - panda_link_radii_(i);
      if (i==0 && j==0){
        DSM_cylinder_sample_ = DSM_cylinder_temp;
      }
      else{
        DSM_cylinder_sample_ = std::min(DSM_cylinder_sample_,DSM_cylinder_temp);
      }
    }
  }
}


arma::mat ExplicitReferenceGovernor::stdToArmaMatrix(std::array<double, 49>& stdMatrix){
  arma::mat armaMatrix;
  armaMatrix  = arma::zeros<arma::mat>(7,7);
    for (int i = 0; i < 7; i++)
    {
      for (int j = 0; j < 7; j++)
      {
        armaMatrix(i,j) = stdMatrix[i+j*7];
      }
    } 
    return armaMatrix;
}

arma::vec ExplicitReferenceGovernor::stdToArmaVector(std::array<double, 7>& stdVector){
  arma::vec armaVector;
  armaVector = arma::zeros<arma::vec>(7);
  for(int i=0; i<7; i++){
    armaVector[i] = stdVector[i];
  }
  return armaVector;
}

std::array<double, 7> ExplicitReferenceGovernor::armaToStdVector(arma::vec& armaVector){
  std::array<double, 7> stdVector;
  for(int i=0; i<7; i++){
    stdVector[i] = armaVector[i];
  }
  return stdVector;
}


}  // namespace franka_planner_control

