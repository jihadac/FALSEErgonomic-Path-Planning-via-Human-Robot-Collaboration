import FabrikRobot.Robot as IKrobot
import Candidate_Points as points
import numpy as np


radius = 1
X, Z = points.candidatePoints(radius) #Give as argument value of radius. X and Y are the arrays of x- and y-coordinates of the points indicated in the circle.
length = len(X)

possible_pointsX = [] #Feasible for robot
possible_pointsZ = []
list_angles = []

for i in range(length):
    x = X[i]
    y = 0.45
    z = Z[i]
    default_target_position = [x, y, z]
    default_target_orientation = [0.71, 0, 0, 0.71]
    
    chain = IKrobot.Franka_robot_definition(default_target_position, default_target_orientation)
    base_bone = IKrobot.FRANKA_base_bone()
    angles = IKrobot.solve_fabrik_for_Robot(base_bone, chain, default_target_position, default_target_orientation)
    
    if angles:
        possible_pointsX.append(x)
        possible_pointsZ.append(z)
        list_angles.append(angles)

l = len(list_angles)
list_angles_degrees = []

for i in range(l):
    d = [x*(180/np.pi) for x in list_angles[i]]
    list_angles_degrees.append(d)

        
        