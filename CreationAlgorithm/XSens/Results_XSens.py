from openpyxl import load_workbook
import XSens.REBA_Scores_XSens as scores_XSens
import Candidate_Points as points
import matplotlib.pyplot as plt
import numpy as np
import copy


def readReachablePoints():
    path = 'C:/Users/jihad/Documents/VUB/Master 2/Master Thesis/Code/reachable_tuples.txt'
    reachable_points = []

    with open(path,'r') as reachable_points_robot:
        for line in reachable_points_robot:
            # Split the line into individual coordinates
            coordinates_point = line.split()
        
            # Convert each coordinate to a float and append to the reachable_points list
            coordinates_float = [float(coord) for coord in coordinates_point]
            reachable_points.append(coordinates_float)
    return reachable_points

def readUnreachablePoints():
    path = 'C:/Users/jihad/Documents/VUB/Master 2/Master Thesis/Code/unreachable_points.txt'
    unreachable_points = []

    with open(path,'r') as unreachable_points_robot:
        for line in unreachable_points_robot:
            # Split the line into individual coordinates
            coordinates_point = line.split()
    
            # Convert each coordinate to a float and append to the reachable_points list
            coordinates_float = [float(coord) for coord in coordinates_point]
            unreachable_points.append(coordinates_float)
    return unreachable_points

def adaptPointsForFabrik(points): # points represents a list of points, where each point has 3 coordinates
    # The reachable and unreachable points are defined in ROS' frame. However, to compare plots, we need it in FABRIK's frame
    R = [[0,-1,0],[1,0,0],[0,0,1]] # Rotation around z-axis over 90°
    
    rotated_points = []
    points_fabrik = []
    
    for point in points:
        rotated_point = np.matmul(R,point).tolist()
        rotated_points.append(rotated_point)
        
    # Remove the y-coordinate of the rotated points 
    r_points = copy.deepcopy(rotated_points)
    for point in r_points:
        point.pop(1) # pop(i) removes the element at index i from the list point
        points_fabrik.append(point)
        
    return points_fabrik

def computeScoresXSens(worksheet):
    REBA_scores_XSens = []

    for row in range(2,69): # The joint angles for each frame are listed between rows 2 and 68 in the Excel file
        REBA_score = scores_XSens.rebaCalculation_XSens(worksheet,row)
        REBA_scores_XSens.append(REBA_score)
    
    return REBA_scores_XSens
        
def determineColor(REBA_Scores_XSens):
    
    colors = []
    
    for REBA_score in REBA_Scores_XSens:
        if REBA_score >= 11:
            REBA_color = '#8B1A1A'
        elif REBA_score == 8 or REBA_score == 9 or REBA_score == 10:
            REBA_color = '#FF3030'
        elif REBA_score == 4 or REBA_score == 5 or REBA_score == 6 or REBA_score == 7:
            REBA_color = '#FF8C00'
        elif REBA_score == 2 or REBA_score == 3:
            REBA_color = '#FFD700'
        else:
            REBA_color = '#76EE00'
        colors.append(REBA_color)
        
    return colors
        
def plotScoresXSens(REBA_scores,colors,reachable_points,unreachable_points):
    a = 0.855
    b = 0.855
    c = 0.857
    
    step = 0.15
    height_circle = 0.333         # Height centre point circle with respect to origin
    distance_circle = 0.33
    
    # Compute the x- and z-coordinates of the candidate points inside the circle
    tuples, a_new, c_new = points.candidatePoints(a,b,c,distance_circle,height_circle,step)

    theta = np.linspace(0, 2*np.pi, 150)
    u = a_new * np.cos(theta)
    v = c_new * np.sin(theta)+height_circle

    figure, axes = plt.subplots(1)
    axes.plot(u,v)
    axes.set_aspect(1) #Same scale for x and z
    
    i = 0
    
    for point in reachable_points:    
        plt.scatter(point[0], point[1], color=colors[i])
        axes.text(point[0]+0.04,point[1]-0.025,REBA_scores[i])
        i += 1
    
    for point in unreachable_points:
        plt.scatter(point[0], point[1], color='#00FFFF')

    
    plt.title('REBA scores obtained with XSens''\n' 'Distance 3')
    plt.grid(True)
    plt.show()
                                                           

