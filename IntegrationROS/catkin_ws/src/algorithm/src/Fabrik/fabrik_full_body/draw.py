import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import axes3d, Axes3D
import numpy as np
import util as util
import Candidate_Points as points

#import Score_Candidate_Points as ScoresAndPoints 



class Draw:
    def __init__(self, joints, target, first_pos, rightArmIndex, leftArmIndex, upperChain, lowerChain, rightLeg,
                 leftLeg, neck, head):
        self.joints = joints
        self.first_pose = first_pos
        self.target = target
        self.right_arm_index = rightArmIndex
        self.left_arm_index = leftArmIndex
        self.upper_chain_index = upperChain
        self.lower_chain_index = lowerChain
        self.right_leg_index = rightLeg
        self.left_leg_index = leftLeg
        self.neck_index = neck
        self.head_index = head

    def set_axes_radius(self, ax, origin, radius):
        ax.set_xlim3d([origin[0] - radius, origin[0] + radius])
        ax.set_ylim3d([origin[1] - radius, origin[1] + radius])
        ax.set_zlim3d([origin[2] - radius, origin[2] + radius])

    def set_axes_equal(self, ax):
        limits = np.array([
            ax.get_xlim3d(),
            ax.get_ylim3d(),
            ax.get_zlim3d(),
        ])

        origin = np.mean(limits, axis=1)
        radius = 0.5 * np.max(np.abs(limits[:, 1] - limits[:, 0]))
        self.set_axes_radius(ax, origin, radius)

    def fill_array(self, body_part_index, joints):
        w, h = 3, len(body_part_index)
        coordinate = [[0 for x in range(w)] for y in range(h)]
        # coordinate =[][len(body_part_index)]
        x = []
        y = []
        z = []
        for i in range(len(body_part_index)):
            x.append(joints[body_part_index[i]][0])
            y.append(joints[body_part_index[i]][1])
            z.append(joints[body_part_index[i]][2])
        coordinate[0][:] = x
        coordinate[1][:] = y
        coordinate[2][:] = z
        return coordinate

    def draw_final(self,counter,colors,a,b,c,step,height_circle,distance_circle):
        # The Second Pose
        coordinate = self.fill_array(self.right_arm_index, self.joints)
        x_prime_right_arm = coordinate[0]
        y_prime_right_arm = coordinate[1]
        z_prime_right_arm = coordinate[2]

        coordinate = self.fill_array(self.left_arm_index, self.joints)
        x_primeLArm = coordinate[0]
        y_primeLArm = coordinate[1]
        z_primeLArm = coordinate[2]

        coordinate = self.fill_array([0, 1, 5,0], self.joints)
        x_primeU = coordinate[0]
        y_primeU = coordinate[1]
        z_primeU = coordinate[2]

        coordinate = self.fill_array(self.lower_chain_index, self.joints)
        x_primeL = coordinate[0]
        y_primeL = coordinate[1]
        z_primeL = coordinate[2]

        coordinate = self.fill_array(self.right_leg_index, self.joints)
        x_primeRLeg = coordinate[0]
        y_primeRLeg = coordinate[1]
        z_primeRLeg = coordinate[2]

        coordinate = self.fill_array(self.left_leg_index, self.joints)
        x_primeLLeg = coordinate[0]
        y_primeLLeg = coordinate[1]
        z_primeLLeg = coordinate[2]
        
        # coordinate = self.fill_array(self.neck_index, self.joints)
        # x_primeNeck = coordinate[0]
        # y_primeNeck = coordinate[1]
        # z_primeNeck = coordinate[2]
        
        # coordinate = self.fill_array(self.head_index, self.joints)
        # x_primeHead = coordinate[0]
        # y_primeHead = coordinate[1]
        # z_primeHead = coordinate[2]

        # # ...............................................................................................
        coordinate = self.fill_array(self.right_arm_index, self.first_pose)
        x_RArm = coordinate[0]
        y_RArm = coordinate[1]
        z_RArm = coordinate[2]

        coordinate = self.fill_array(self.left_arm_index, self.first_pose)
        x_LArm = coordinate[0]
        y_LArm = coordinate[1]
        z_LArm = coordinate[2]

        coordinate = self.fill_array([0, 1, 5,0], self.first_pose)
        x_U = coordinate[0]
        y_U = coordinate[1]
        z_U = coordinate[2]

        coordinate = self.fill_array(self.lower_chain_index, self.first_pose)
        x_L = coordinate[0]
        y_L = coordinate[1]
        z_L = coordinate[2]

        coordinate = self.fill_array(self.right_leg_index, self.first_pose)
        x_RLeg = coordinate[0]
        y_RLeg = coordinate[1]
        z_RLeg = coordinate[2]

        coordinate = self.fill_array(self.left_leg_index, self.first_pose)
        x_LLeg = coordinate[0]
        y_LLeg = coordinate[1]
        z_LLeg = coordinate[2]
        
        # coordinate = self.fill_array(self.neck_index, self.first_pose)
        # x_Neck = coordinate[0]
        # y_Neck = coordinate[1]
        # z_Neck = coordinate[2]
        
        # coordinate = self.fill_array(self.head_index, self.first_pose)
        # x_Head = coordinate[0]
        # y_Head = coordinate[1]
        # z_Head = coordinate[2]
        
        theta = np.linspace(0, 2*np.pi, 150)
        distance = [distance_circle]
        u = a * np.cos(theta)
        v = c * np.sin(theta)+height_circle
        y = distance * 150
        
        tuples = points.candidatePoints(a,b,c,distance_circle,height_circle,step) #Give as argument value of radius. X and Z are the arrays of x- and z-coordinates of the points indicated in the circle.
        list_c = colors
        current_candidate_point = counter #Takes values from 0 --> len(X)-1
        
        
         

        fig = plt.figure()
        ax = fig.gca(projection='3d')
        
        ax.plot3D(u,y,v)

        ax.plot3D(x_RArm, y_RArm, z_RArm, color='red')
        ax.plot3D(x_LArm, y_LArm, z_LArm, color='red')
        ax.plot3D(x_U, y_U, z_U, color='red')
        ax.plot3D(x_L, y_L, z_L, color='red')
        ax.plot3D(x_RLeg, y_RLeg, z_RLeg, color='red')
        ax.plot3D(x_LLeg, y_LLeg, z_LLeg, color='red')
        # ax.plot3D(x_Neck, y_Neck, z_Neck, color='red')
        # ax.plot3D(x_Head, y_Head, z_Head, color='red')

        ax.plot3D(x_prime_right_arm, y_prime_right_arm,
                  z_prime_right_arm, color='green')
        ax.plot3D(x_primeLArm, y_primeLArm, z_primeLArm, color='green')
        ax.plot3D(x_primeU, y_primeU, z_primeU, color='green')
        ax.plot3D(x_primeL, y_primeL, z_primeL, color='green')
        ax.plot3D(x_primeRLeg, y_primeRLeg, z_primeRLeg, color='green')
        ax.plot3D(x_primeLLeg, y_primeLLeg, z_primeLLeg, color='green')
        # ax.plot3D(x_primeNeck, y_primeNeck, z_primeNeck, color='green')
        # ax.plot3D(x_primeHead, y_primeHead, z_primeHead, color='green')

        # FrightUpperArmLength = distance_calculation(joints[0], joints[9])
        # LrightUpperArmLength = distance_calculation(first_pos[0], first_pos[9])
        #
        # # ax.scatter3D(joints[head[1]][0], joints[head[1]][1], joints[head[1]][2],edgecolors='green')
        
        for i in range(len(tuples)): # Plot all possible candidate points in standard blue
            x = tuples[i][0]
            y = distance_circle
            z = tuples[i][1]
            ax.scatter3D(x,y,z, color = 'blue')
            
        if current_candidate_point == 0:
            ax.scatter3D(tuples[current_candidate_point][0],distance_circle,tuples[current_candidate_point][1],color = list_c[current_candidate_point]) #Plot current candidate point in color corresponding to REBA score
        else: #To color previous points with correct color, corresponding to REBA score
            for i in range(current_candidate_point+1):
                ax.scatter3D(tuples[i][0],distance_circle,tuples[i][1],color = list_c[i]) #Plot current candidate point in color corresponding to REBA score
            

        #ax.scatter3D(self.target[0], self.target[1], self.target[2])
        #
        self.set_axes_equal(ax)
        ax.view_init(20, -70)
        
        plt.show()
