#!/usr/bin/env python3

# Running this file will execute the entire algorithm

import sys
import os
import rospy
from std_msgs.msg import String


import Candidate_Points as points
import Score_Candidate_Points as scores
import Results as draw_results
import Adjacency_Matrix as adjancency_matrix
import Graph as graph
import A_Star as a_star
import Drawing_Graph as circle_path
import Post_Processing as postp
import Conversion_To_Tuples as conversion
import Reachable_Points_Robot as reachable_points
import Change_Score as change_score
import numpy as np
import math
import random

# Add the package to the Python path
package_path = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(package_path, '..'))


def main():

	directory = '/home/mainuser/Jihad/catkin_ws/src/algorithm/src'

	# Parameters ellipsoid
	a = 0.855
	b = 0.855
	c = 0.857

	step = 0.15	               # Distance between the candidate points
	height_circle = 0.333	       # Height centre point circle with respect to origin
	distance_circle = 0.33         # Distance in y direction with respect to origin --> determines how far circle is from human

	# Define booleans for plots
	plotScoresWCircle = False
	plotHuman = False
	plotPath = True
    
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
	    	# A dictionary associates to a key a certain value
	
	# Convert .txt file of unreachable points into list of tuples unreachable by robot
	list_unreachable_points_robot = conversion.convert_txt_to_tuples(directory)
	
	# Redefine REBA_tuple_dictionary by associating a REBA score of hundrerd to tuples not reachable by robot
	REBA_tuple_dictionary, colors = change_score.change_score_unreachable_points(list_unreachable_points_robot,REBA_tuple_dictionary,colors)
	
	# Extract list of tuples containing only the points reachable by robot
	list_reachable_points_robot = reachable_points.extract_reachable_points_robot(tuples,list_unreachable_points_robot)

	# Plot the results
	if plotHuman == True:
		draw_results.plotHumanConfiguration(colors, results_fabrik_list, a_new, b, c_new, step, length, height_circle, distance_circle)
	if plotScoresWCircle == True: 
		draw_results.plotCircle(colors, a_new, b, c_new, REBA_tuple_dictionary, length, height_circle)

	# Compute the adjacancy matrix necessary to create the graph
	    # M represents the adjacency matrix
	    # tuples is a list of tuples, representing the x and z coordinate of each candidate point (x,z)
	M = adjancency_matrix.createAdjacencyMatrix(tuples, step, length, REBA_scores_list)

	# Create graph
	G = graph.createGraph(M, tuples, length)
	
	# Create a list of random starting nodes
		# Repetition defines the number of paths will be generated for different random initial nodes
		# number_of_paths is a counter to keep track of the number of paths already found
		# directory represents the directory where the paths will be saved
	repetition = 10 
	list_starting_nodes = random.sample(list_reachable_points_robot,repetition)
	number_of_paths = 1
	
	# Find the goal node, which is necessary to compute the most ergonomic path
	min_score = min(REBA_tuple_dictionary.values())
	possible_goal_nodes = [node for node, score in REBA_tuple_dictionary.items() if score == min_score]
	
	for start_node in list_starting_nodes: # Start node only necessary for A* algorithm

		# If multiple candidate points have the same lowest REBA score, define goal_node as the one closest to start_node
		goal_node = min(possible_goal_nodes, key = lambda t: compute_distance(t, start_node))
	
		if start_node in tuples:
			pass        # If start_node corresponds to a candidate point, nothing has to be changed
		else:               # Find the candidate point that is closest to the given start_node
			start_node = min(tuples, key = lambda t: compute_distance(t, start_node))

		# Execute the A* algorithm
		path = a_star.A_Star_Algorithm(G, start_node, goal_node, M, REBA_tuple_dictionary, tuples)

		# Add the y-coordinate and rotate the points
		corrected_path = postp.post_process(path,distance_circle)
	
		# Write path to file
		with open(directory+'/path.txt', 'w') as f:
			np.savetxt(f, corrected_path)
		
		with open(directory+'/paths/path' + str(number_of_paths) + '.txt','w') as f:
			np.savetxt(f, corrected_path)

		#corrected_tuples = postp.post_process(tuples,distance_circle)
		corrected_reachable_points_robot = postp.post_process(list_reachable_points_robot,distance_circle)
		
		# Write tuples to file
		#with open(directory+'/tuples.txt', 'w') as f:
			#np.savetxt(f, corrected_tuples)

		# Write tuples to file
		with open(directory+'/reachable_tuples.txt', 'w') as f:
			np.savetxt(f, corrected_reachable_points_robot)

		# Draw path on circle
		if plotPath == True:
			circle_path.drawPath(path, REBA_tuple_dictionary, colors, a_new, b, c_new, length, height_circle)
		
		number_of_paths+=1
	
	print('End of script is reached')
	
	# Publish the path as a ROS topic --> necessary to make it work with ros
	path_pub = rospy.Publisher('ergonomic_path', String, queue_size=10)
	#rate = rospy.Rate(10) # 10hz
	#while not rospy.is_shutdown():
		#path_pub.publish(str(path))
		#rate.sleep()

def compute_distance(tuple1,tuple2):
    return math.sqrt((tuple2[0] - tuple1[0])**2 + (tuple2[1] - tuple1[1])**2)

if __name__ == '__main__':
	try:
		rospy.init_node('ergonomic_path_planning')
		main()
		rospy.signal_shutdown('Finished')
	except rospy.ROSInterruptException:
		pass

exit()

    
    


