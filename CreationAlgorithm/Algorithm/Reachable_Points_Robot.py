def extract_reachable_points_robot(tuples,list_unreachable_points_robot):
	list_tuples = list(tuples)
	for point in list_unreachable_points_robot:
		list_tuples.remove(point)
	return list_tuples
    
