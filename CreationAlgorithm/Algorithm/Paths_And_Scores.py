# Python program to print all paths from a source to destination.
import networkx as nx
import copy



'''A recursive function to print all paths from 'u' to 'd'.
	visited[] keeps track of vertices in current path.
	path[] stores actual vertices and path_index is current
	index in path[]'''
    


def generate_all_paths(current_node, goal_node, visited, path, tuples, graph, list_all_paths):

    visited[tuples.index(current_node)]= True # Mark current node as visited 
    path.append(current_node)                 # Store current node in path

    if current_node == goal_node:             # If current node is same as goal, then print current path[]
        copy_path = copy.deepcopy(path)       # Necessary, because otherwise pop() removes elements from list_all_paths as well 
        list_all_paths.append(copy_path)
        print (path)
    else:
        
        neighbors = list(graph.neighbors(current_node)) # Find the neighbors/successors of current node
        for neighbor in neighbors: # Recur for all the nodes adjacent to this node
            if visited[tuples.index(neighbor)]== False:
                generate_all_paths(neighbor, goal_node, visited, path, tuples, graph, list_all_paths)
					

    path.pop() # Remove current node from path[] and mark it as unvisited
    visited[tuples.index(current_node)]= False
    
    return list_all_paths


def compute_score_path(path,scores):
    # path is a list containing all the visisted points
    # scores is a dictionary associating to every point a score
    total_score = 0                  # Store the total score associated to the entire path
    for point in path:
        score = scores[point]
        total_score += score
        
    return total_score



   

