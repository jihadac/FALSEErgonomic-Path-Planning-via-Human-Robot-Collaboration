import math
import timeit

def A_Star_Algorithm_Comparison(graph,start_node,goal_node,M,REBA_scores,tuples,choice): # Choice takes a value of 1, 2 or 3 to determine which heuristic to use
    
    number_node_expansions = 0

    heuristic_function = selector(choice)
    
    start_time = timeit.default_timer()
    # Initialize the open and closed sets
    open_set = set([start_node])
    closed_set = set([])
    
    # Create three dictionaries to store the parent nodes and the values of g (the cost) and f (= g+h)
    g_score = {start_node: 0} # Cost of start node is equal to zero
    f_score = {start_node: heuristic_function(start_node,goal_node,REBA_scores)} # Or you could start with f start_node = 0
    parent = {}
    
    while open_set: # While open_set is not empty
    
        # Current node corresponds to node with lowest f score
        current_node = min(open_set, key = lambda node: f_score[node]) # Will the very first time be start_node
        
        # After selecting the node, remove it from open set and place it in closed one
        open_set.remove(current_node) 
        closed_set.add(current_node)
        number_node_expansions += 1
        
        # First verify if current node corresponds to goal node, if so --> reconstruct path
        if current_node == goal_node:
            end_time = timeit.default_timer()
            runtime = end_time - start_time
            path = reconstruction_path(current_node,start_node,parent)
            return path, runtime, number_node_expansions
        
        # Find the neighbors/successors of current node
        neighbors = list(graph.neighbors(current_node))
        
        for neighbor in neighbors:
            
            # First check if neighbor node is already in closed set --> if so omit it
            if neighbor in closed_set:
                    continue
            
            # Calculate the g score of the considered neighbor
            g_score_neighbor = g_score[current_node] + cost(current_node, neighbor, tuples, M)
            
            # Neighbor is either not yet present in open set --> add it
            if neighbor not in open_set:
                open_set.add(neighbor)
            # Neighbor is already present in open set, but with lower score than what computed now --> omit it
            elif g_score_neighbor >= g_score[neighbor]:
                continue
            
            parent[neighbor] = current_node # The parent of the neighbor corresponds to the current node
            g_score[neighbor] = g_score_neighbor
            h_neighbor = heuristic_function(neighbor, goal_node, REBA_scores)
            
            f_score[neighbor] = g_score[neighbor] + h_neighbor
                
    return None # No path has been found

def heuristic_function1(node_i,goal_node,REBA_scores): # Current node i, the goal node goal, a weight w (between 0 and 1)
    
    h = abs(REBA_scores[node_i]-REBA_scores[goal_node])
    
    return h

def heuristic_function2(node_i,goal_node,REBA_scores): # Current node i, the goal node goal, a weight w (between 0 and 1)
    
    w = 0.3
    h = w * math.dist(node_i, goal_node) + (1-w) * abs(REBA_scores[node_i]-REBA_scores[goal_node])
    
    return h

def heuristic_function3(node_i,goal_node,REBA_scores): # Current node i, the goal node goal, a weight w (between 0 and 1)
    
    k = 0.1
    h = math.exp(k*abs(REBA_scores[node_i]-REBA_scores[goal_node]))-1
    
    return h

def selector(choice):
    if choice == 1:
        return heuristic_function1
    elif choice == 2:
        return heuristic_function2
    elif choice == 3:
        return heuristic_function3

def reconstruction_path(current_node,start_node,parent):
    path = [current_node]
    
    while current_node != start_node:
        current_node = parent[current_node]
        path.append(current_node)
    
    path.reverse()
    
    return path


def cost(from_node,to_node,tuples,M):
    F = tuples.index(from_node)
    T = tuples.index(to_node)
    return M[F][T]

#path = A_Star_Algorithm(G,(0.2,1.0),(0.0,0.8))
    
