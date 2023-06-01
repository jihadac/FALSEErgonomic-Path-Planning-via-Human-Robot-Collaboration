# Script to determine which values of height_circle and distance_circle give the most low REBA score (1,2,3)

# height_circle = Height centre point circle with respect to origin
# distance_circle = Distance in y direction with respect to origin --> determines how far circle is from human

import Score_Candidate_Points as scores
import Candidate_Points as points
import numpy as np


# Define variables
radius = 0.855#0.2 #0.855     # Radius of circle
step = 0.25#0.1 #0.25         # Distance between the candidate points

counter = 0
number_of_low_REBA = []
best_combination = (100,100,100)
best_combination_multiple = []


for i in np.arange(0, 1.02, 0.02):
    height_circle = i
    for j in np.arange(0,1.02,0.02):
        distance_circle = j
        # Compute the x- and z-coordinates of the candidate points inside the circle
        tuples = points.candidatePoints(radius,step,height_circle)
        length = len(tuples)
        
        # Compute the REBA score of each candidate point
        colors, REBA_scores_list, results_fabrik_list, error = scores.computeScores(tuples,distance_circle)
        
        if error == True:
            continue
        
        for score in REBA_scores_list:
            if score == 3 or score == 2 or score == 1:
                counter += 1
        
        number_of_low_REBA.append(counter)
        
        if counter > max(number_of_low_REBA):
            best_combination = (i,j,counter)
        elif counter == max(number_of_low_REBA):
            best_combination_multiple.append((i,j,counter))
            
        counter = 0
        
        print(i,j)
        
    
print(best_combination)
            
        
                




