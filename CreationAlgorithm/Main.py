# Running this file will execute the entire algorithm

import Candidate_Points as points
import Score_Candidate_Points as scores
import Results as draw_results
import Graph as graph
import A_Star as a_star
import Drawing_Graph as circle_path
import Post_Processing as postp
import Conversion_To_Tuples as conversion
import Reachable_Points_Robot as reachable_points
import Change_Score as change_score
import Brute_Force_Search as bfs
import numpy as np
import math
import random


directory = 'C:/Users/jihad/Documents/VUB/Master 2/Master Thesis/Code'

# Parameters ellipsoid
a = 0.855
b = 0.855
c = 0.857

step = 0.15	                   # Distance between the candidate points
height_circle = 0.333	       # Height centre point circle with respect to origin
distance_circle = 0.33         # Distance in y direction with respect to origin --> determines how far circle is from human

# Define booleans for plots
plotScoresWCircle = True
plotHuman = False
plotPath = False
    
# Compute the x- and z-coordinates of the candidate points inside the circle
tuples, a_new, c_new = points.candidatePoints(a,b,c,distance_circle,height_circle,step)	
length = len(tuples)
	
# Compute the REBA score of each candidate point
    # colors is a list of colors, to every point a color is associated depending on the corresponding REBA score
    # REBA_scores_list is a list containing the REBA score of every candidate point
    # results_fabrik_list is a list containing the result of FABRIK for each candidate point
colors, REBA_scores_list, results_fabrik_list, error = scores.computeScores(tuples,distance_circle)

# Create a dictionary to associate each tuple to the corresponding REBA score
REBA_tuple_dictionary = dict() 
for i in range(length):
	REBA_tuple_dictionary.update({tuples[i]:REBA_scores_list[i]}) # Dictionary that stores for every tuple (point) the corresponding REBA score
	
# Convert .txt file of unreachable points into list of tuples unreachable by robot
list_unreachable_points_robot = conversion.convert_txt_to_tuples(directory)
	
# Redefine REBA_tuple_dictionary by associating a REBA score of hundrerd to tuples not reachable by robot
REBA_tuple_dictionary, colors = change_score.change_score_unreachable_points(list_unreachable_points_robot,REBA_tuple_dictionary,colors)
	
# Extract list of tuples containing only the points reachable by robot
list_reachable_points_robot = reachable_points.extract_reachable_points_robot(tuples,list_unreachable_points_robot)

# Plot the results
if plotHuman == True:
	draw_results.plotHumanConfiguration(colors, results_fabrik_list, a, b, c, step, length, height_circle, distance_circle)
if plotScoresWCircle == True: 
	draw_results.plotCircle(colors, a_new, b, c_new, REBA_tuple_dictionary, length, height_circle)

# Compute the adjacancy matrix necessary to create the graph
    # M represents the adjacency matrix
    # tuples is a list of tuples, representing the x and z coordinate of each candidate point (x,z)
M = graph.createAdjacencyMatrix(tuples, step, length, REBA_scores_list)

# Create graph
G = graph.createGraph(M, tuples, length)
	
# Create random starting node
start_node = random.choice(list_reachable_points_robot)

	
# Find the goal node, which is necessary to compute the most ergonomic path
min_score = min(REBA_tuple_dictionary.values())
possible_goal_nodes = [node for node, score in REBA_tuple_dictionary.items() if score == min_score]
	
# If multiple candidate points have the same lowest REBA score, define goal_node as the one closest to start_node
goal_node = min(possible_goal_nodes, key = lambda t: math.dist(t, start_node))

if start_node in tuples:
	pass        # If start_node corresponds to a candidate point, nothing has to be changed
else:               # Find the candidate point that is closest to the given start_node
	start_node = min(tuples, key = lambda t: math.dist(t, start_node))

# Execute the A* algorithm
path = a_star.A_Star_Algorithm(G, start_node, goal_node, M, REBA_tuple_dictionary, tuples)

# Add the y-coordinate and rotate the points
corrected_path = postp.post_process(path,distance_circle)
	
with open(directory+'/paths/path' + '.txt','w') as f:
	np.savetxt(f, corrected_path)

#corrected_tuples = postp.post_process(tuples,distance_circle)
corrected_reachable_points_robot = postp.post_process(list_reachable_points_robot,distance_circle)
		
# Write tuples to file
#with open(directory+'/tuples.txt', 'w') as f:
	#np.savetxt(f, corrected_tuples)
# Write tuples to file
#with open(directory+'/reachable_tuples.txt', 'w') as f:
	#np.savetxt(f, corrected_reachable_points_robot)

# Draw path on circle
if plotPath == True:
	circle_path.drawPath(path, REBA_tuple_dictionary, colors, a_new, b, c_new, length, height_circle)
		
    
#ergonomic_path, path_score = bfs.brute_force_search(tuples, list_starting_nodes[9], goal_node, G, REBA_tuple_dictionary)

