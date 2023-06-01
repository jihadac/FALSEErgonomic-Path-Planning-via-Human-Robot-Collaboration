#include <ros/ros.h>
#include <ros/time.h>

#include <memory>
#include <string>
#include <vector>

#include <chrono>
#include <ctime>
#include <thread>
#include <armadillo>

#include <controller_interface/multi_interface_controller.h>
#include <hardware_interface/joint_command_interface.h>
#include <hardware_interface/robot_hw.h>
#include <hardware_interface/hardware_interface.h>
#include <ros/node_handle.h>
#include <ros/time.h>

#include <franka_hw/franka_cartesian_command_interface.h>
#include <franka_hw/franka_model_interface.h>
#include <franka_hw/franka_state_interface.h>

#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit/planning_scene_monitor/planning_scene_monitor.h>

#include <moveit/robot_model_loader/robot_model_loader.h>
#include <moveit/robot_state/robot_state.h>
#include <moveit/robot_state/conversions.h>

#include <moveit_msgs/PlanningScene.h>
#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/GetStateValidity.h>
#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/ApplyPlanningScene.h>
#include <moveit_msgs/DisplayTrajectory.h>
#include <moveit_msgs/CollisionObject.h>

#include <moveit_visual_tools/moveit_visual_tools.h>

#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

#include <Eigen/Dense>
#include <Eigen/QR>
#include <Eigen/Geometry>

#include <franka_planner_control/JointStates.h>
#include <franka_planner_control/DistanceToConstraints.h>
#include <franka_planner_control/TrajectoryPredictions.h>
#include <franka_planner_control/DSM.h>
#include <franka_planner_control/ComputationalTime.h>

/* required for visualization */
#include <visualization_msgs/Marker.h>
#include <geometry_msgs/TransformStamped.h>
#include <erg_visualization.h>
#include <zed_interfaces/ObjectsStamped.h>

namespace franka_planner_control {

class ExplicitReferenceGovernor : public controller_interface::MultiInterfaceController<
                                                  franka_hw::FrankaModelInterface,
                                                  hardware_interface::EffortJointInterface,
                                                  franka_hw::FrankaStateInterface>{
  public:
    void setReferences(std::array<double,7> &q_r_arg, std::array<double,7> &q_v_arg);
    void navigationField();
    void trajectoryBasedDSM();

    geometry_msgs::Pose transformFromJointToTaskSpace(std::array<double,7> &q);

    Eigen::Matrix<double,7,1> rho_;
    double DSM_;

    /* ROS durations */
    ros::Duration elapsed_time_;
    ros::Duration elapsed_time_trajpred_;

    /* chrono */  
    std::chrono::time_point<std::chrono::system_clock> start_ERG_, end_ERG_;
    std::chrono::time_point<std::chrono::system_clock> start_NF_, end_NF_;
    std::chrono::time_point<std::chrono::system_clock> start_DSM_, end_DSM_;
    std::chrono::time_point<std::chrono::system_clock> start_pred_, end_pred_;
    std::chrono::duration<double> computationaltime_ERG_, computationaltime_NF_, computationaltime_DSM_, computationaltime_pred_;

    /* ROS messages */  
    franka_planner_control::JointStates jointstates_msg_;
    franka_planner_control::DistanceToConstraints disttoconstr_msg_;
    franka_planner_control::TrajectoryPredictions trajpred_msg_;
    franka_planner_control::DSM DSM_msg_;
    franka_planner_control::ComputationalTime computationaltime_msg_;

    /* ROS data publishers */
    ros::Publisher jointstates_publisher_;
    ros::Publisher distancetoconstraints_publisher_;
    ros::Publisher trajpredictions_publisher_;
    ros::Publisher DSM_publisher_;
    ros::Publisher computationaltime_publisher_;

    /* RViz visualization */
    ERGVisualization rviz_visualization;
    ros::Publisher marker_array_publisher_;

    /* Skeleton joint positions */
    std::vector<std::vector<Eigen::Matrix<double, 3, 1>>> skeleton_joint_positions_;
    void addSkeletonsToObstaclesInERG();

    /* select reference out of MoveIt robot trajectory */
    std::array<double, 7> referenceSelector(int start_index);
    std::array<double, 7> referenceEndTrajectoryFromMoveIt();
    moveit_msgs::RobotTrajectory robot_trajectory_;
    int size_trajectory_;
    double end_traj_time_; 
    int trajectory_index_;

    /* selector */
    double kappa_selector_ = 10.0;
    double pred_sampling_time_selector_ = 0.01; 
	  std::array<double,7> q_r_next_;
    std::array<double,7> q_v_pred_;
    Eigen::Matrix<double,7,1> dq_v_pred_;

    const std::string ROBOT_DESCRIPTION_{ "robot_description" };
    moveit::planning_interface::PlanningSceneInterface planning_scene_interface_;
    planning_scene_monitor::PlanningSceneMonitorPtr psm_ = std::make_shared<planning_scene_monitor::PlanningSceneMonitor>(ROBOT_DESCRIPTION_);

    collision_detection::CollisionRequest collision_request_;
    collision_detection::CollisionResult collision_result_;

  protected:
    // /* franka hardware parameters */
    std::unique_ptr<franka_hw::FrankaStateHandle> state_handle_;
    std::unique_ptr<franka_hw::FrankaModelHandle> model_handle_;
    std::vector<hardware_interface::JointHandle> joint_handles_;

    /* comptue closest points from robot to obstacles */ 
    Eigen::Matrix<double, 3, 4> getJointPositions(std::array<double,7>& q_argument);
    Eigen::Matrix<double, 3, 10> getLambda(Eigen::Matrix<double, 3, 4>& panda_jointpositions); // 3 x #spheres
    Eigen::Matrix<double, 9, 10> getPij(Eigen::Matrix<double, 3, 4>& panda_jointpositions, Eigen::Matrix<double, 3, 10>& lambda); // 9 x #spheres
    std::tuple<Eigen::Matrix<double,9,20>,Eigen::Matrix<double,9,20>,Eigen::Matrix<double,3,20>>getMuSijTij(Eigen::Matrix<double, 3, 4>& panda_jointpositions);

    /* NF functions */
    void getPseudoInvJacQv(); // only for q_v
    void getRhoWall();
    void getRhoSphere();
    void getRhoCylinder();

    /* DSM functions */
    void getTrajectoryPrediction();
    double getClosedLoopEnergy();
    double DSMtau(std::array<double, 7>& tau_pred);
    double DSMdotq(std::array<double, 7>& dotq_pred);
    double DSMq(std::array<double, 7>& q_pred);
    double DSMdotpEE(std::array<double, 7>& q_pred, std::array<double, 7>& dotq_pred);
    void DSMwall();
    void DSMsphere();
    void DSMcylinder();

    /* panda link radii used in controller */ 
    Eigen::Matrix<double, 3, 1> panda_link_radii_ = {0.11, 0.13, 0.07};  // between kJoint1-kJoint3, kJoint3-kJoint5, kJoint5-kEndEffector;
  
    /* control parameters given via yaml */
    std::vector<double> Kp_;
    std::vector<double> Kd_;
    std::vector<double> joint_friction_1_;
    std::vector<double> joint_friction_2_;
    std::vector<double> joint_friction_3_;

    /* ERG parameters given via yaml */
    double pred_samples_;
    double pred_samplingtime_;
    double pred_interval_;

    std::vector<double> tau_limit_;
    double kappa_tau_;
    double delta_tau_;

    std::vector<double> dotq_limit_;
    double kappa_dotq_;
    double delta_dotq_;

    std::vector<double> q_lowerlimit_;
    std::vector<double> q_upperlimit_;
    std::array<double,7> q_upperlimit_array_;
    std::array<double,7> q_lowerlimit_array_;
    double kappa_q_;
    double delta_q_;
    double eta_;
    double zeta_q_;

    std::vector<double> dotp_EE_limit_;
    double kappa_dotp_EE_;
    double delta_dotp_EE_;

    double kappa_energy_;
    double energy_;
    double terminalenergy_;
    double energy_limit_; 

    double zeta_wall_;  
    double kappa_wall_;  
    double delta_wall_; 

    double kappa_sphere_;
    double delta_sphere_;
    double zeta_sphere_;

    double kappa_cylinder_;
    double delta_cylinder_;
    double zeta_cylinder_;

    /* Walls : matrix now defined for max 10 walls */
    int number_of_walls_;             // for NF and DSM
    int number_of_moveit_walls_;      // only for DSM
    Eigen::Matrix<double, 3, 10> wall_normals_;
    Eigen::Matrix<double, 1, 10> wall_distances_;
    Eigen::Matrix<double, 1, 10> wall_heights_;
    Eigen::Matrix<double, 1, 10> wall_lengths_;
    Eigen::Matrix<double, 1, 10> wall_widths_;
    Eigen::Matrix<double, 4, 10> wall_quaternions_;

    /* Spherical obstacles : matrix now defined for max 10 spheres */
    int number_of_spheres_;           // for NF and DSM
    int number_of_moveit_spheres_;    // only for DSM
    Eigen::Matrix<double, 3, 10> sphere_centers_;
    Eigen::Matrix<double, 1, 10> sphere_radii_;

    /* Cylindrical obstacles : matrix now defined for max 20 cylinders */ 
    int number_of_cylinders_ ;        // for NF and DSM
    int number_of_moveit_cylinders_;  // only for DSM
    Eigen::Matrix<double, 3, 20> cylinder_centers_; 
    Eigen::Matrix<double, 6, 20> cylinder_startendpoints_; 
    Eigen::Matrix<double, 1, 20> cylinder_radii_;
    Eigen::Matrix<double, 1, 20> cylinder_heights_; 
    Eigen::Matrix<double, 4, 20> cylinder_quaternions_;

  private:
    arma::mat stdToArmaMatrix(std::array<double, 49>& stdMatrix);
    arma::vec stdToArmaVector(std::array<double, 7>& stdVector);
    std::array<double, 7> armaToStdVector(arma::vec& armaVector);

    /* joint states */
    std::array<double,7> q_r_;  // std::array<double,7> since this is required input for libfranka functions
    std::array<double,7> q_v_; 

    /* joint cartesian positions and their pseudoinverse jacobians */
    Eigen::Matrix<double, 3, 4> panda_q_v_positions_;
    Eigen::Matrix<double, 3, 4> panda_q_pred_positions_;

    Eigen::MatrixXd joint3_jacobian_pinv_;
    Eigen::MatrixXd joint4_jacobian_pinv_;
    Eigen::MatrixXd joint5_jacobian_pinv_;
    Eigen::MatrixXd joint6_jacobian_pinv_;
    Eigen::MatrixXd joint7_jacobian_pinv_;
    Eigen::MatrixXd endeffector_jacobian_pinv_;

    /* NF output */
    Eigen::Matrix<double,7,1> rho_att_;
    Eigen::Matrix<double,7,1> rho_rep_q_;
    Eigen::Matrix<double,7,1> rho_rep_wall_;
    Eigen::Matrix<double,7,1> rho_rep_sphere_;
    Eigen::Matrix<double,7,1> rho_rep_cylinder_;

    /* DSM output */
    double DSM_tau_;
    double DSM_dotq_;
    double DSM_q_;
    double DSM_dotp_EE_;
    double DSM_terminalenergy_;
    double DSM_wall_;
    double DSM_wall_sample_;
    double DSM_sphere_;
    double DSM_sphere_sample_;
    double DSM_cylinder_;
    double DSM_cylinder_sample_;

    /* distance to constraints */
    double distance_to_tau_;
    double distance_to_dotq_;
    double distance_to_q_;
    double distance_to_dotp_EE_;
    double distance_to_terminalenergy_;
    double distance_to_wall_;
    double distance_to_sphere_;
    double distance_to_cylinder_;

    /* DSM trajectory prediction parameters */
    std::array<double,7> q_pred_;
    std::array<double,7> dq_pred_; 
    std::array<double,9> I_total_pred_; 
    double m_total_pred_; 
    std::array<double,3> F_x_Ctotal_pred_; 
    std::array<double, 700> q_pred_list_; //unsigned int pred_list_length = 7*pred_samples_;
    std::array<double, 700> dotq_pred_list_;
    std::array<double, 700> tau_pred_list_;
    std::array<double, 49> mass_pred_;
    std::array<double, 7> coriolis_pred_;
    std::array<double, 7> gravity_pred_;
    std::array<double, 7> tau_pred_;
    arma::mat arma_mass_pred_; 
    arma::vec arma_coriolis_pred_;
    arma::vec arma_gravity_pred_;
    arma::vec arma_tau_pred_;
    arma::vec arma_ddq_pred_;
    std::array<double, 7> ddq_pred_;

    std::array<double,7> q_pred_next_;
    std::array<double,7> dq_pred_next_; 
    std::array<double,7> ddq_pred_next_;
    std::array<double,7> tau_pred_next_;
    std::array<double,7> gravity_pred_next_;

    /* Spherical obstacles */  
    Eigen::Matrix<double, 3, 10> lambda_q_v_;
    Eigen::Matrix<double, 3, 10> lambda_q_pred_;
    Eigen::Matrix<double, 9, 10> Pij_q_v_;
    Eigen::Matrix<double, 9, 10> Pij_q_pred_;

    /* Cylindrical obstacles */ 
    Eigen::Matrix<double, 3, 20> mu_q_v_;
    Eigen::Matrix<double, 3, 20> nu_q_v_;
    Eigen::Matrix<double, 3, 20> mu_q_pred_;
    Eigen::Matrix<double, 3, 20> nu_q_pred_;
    Eigen::Matrix<double, 9, 20> Sij_q_v_;
    Eigen::Matrix<double, 9, 20> Tij_q_v_;
    Eigen::Matrix<double, 9, 20> Sij_q_pred_;
    Eigen::Matrix<double, 9, 20> Tij_q_pred_;
};

}  // namespace franka_planner_control