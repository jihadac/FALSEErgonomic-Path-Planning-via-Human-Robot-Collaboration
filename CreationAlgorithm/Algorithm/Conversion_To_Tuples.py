def convert_txt_to_tuples(directory):
	list_unreachable_points_robot = []
	with open(directory + '/unreachable_points.txt', 'r') as f:
		for line in f:
			point = line.split()
			z = float(point[2])  # Float is necessary to convert string into float
			x = -float(point[1]) # x-coordinate in FABRIK corresponds to opposite of y-coordinate in RViz
			point_as_tuple = (x,z)
			
			list_unreachable_points_robot.append(point_as_tuple)	
				
	return list_unreachable_points_robot
    
