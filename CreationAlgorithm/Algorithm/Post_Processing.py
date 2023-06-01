import numpy as np

def post_process(path,distance_circle):

    # Add the y-coordinate to all the points
    path_new = [] #Define an empty list, which will contain the path, including the y coordinate for each point
    for point in path: 
        point_as_list = list(point) # Convert considered point (= tuple with two coordinates) to a list
        point_as_list.insert(1,distance_circle) # Add the y-coordinate of the points to the list
        new_tuple = tuple(point_as_list) # Convert list, including now the y-coordinate, back to a tuple. Tuple contains now x, y and z coordinate
        path_new.append(new_tuple)

    # Rotate the points (vectors) -90° around the z-axis --> this is necessary since the frames in FABRIK and in ROS are defined differently
    # Define rotation matrix
    R = [[0,1,0],[-1,0,0],[0,0,1]]
    rotated_path = []

    for point in path_new:
        rotated_point = np.matmul(R,point)
        rotated_path.append(tuple(rotated_point))

    return rotated_path

path = [(6.502999999999999892e-01,2.049999999999999878e-01),(4.953000000000000180e-01,3.599999999999999867e-01),(3.402999999999999914e-01,3.599999999999999867e-01)]
distance_circle = 0.42

post_process(path,distance_circle)