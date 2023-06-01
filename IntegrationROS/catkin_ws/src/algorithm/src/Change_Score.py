def change_score_unreachable_points(list_unreachable_points_robot,REBA_tuple_dictionary,colors):
	with open('/home/mainuser/Jihad/catkin_ws/src/algorithm/src/unreachable_points.txt', 'r') as f:
		for point in list_unreachable_points_robot:
			# For each point in list_unreachable_points_robot change the REBA score to hundred
			REBA_tuple_dictionary.update({point:100})
			
			# Change color
			index_point = list(REBA_tuple_dictionary.keys()).index(point)
			colors[index_point] = '#00FFFF'
			
			
	return REBA_tuple_dictionary, colors
    
