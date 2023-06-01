import math

def A_Star_Algorithm(graph,start_node,goal_node,M,REBA_scores,tuples):
    
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
        
        # First verify if current node corresponds to goal node, if so --> reconstruct path
        if current_node == goal_node:
            path = reconstruction_path(current_node,start_node,parent)
            return path
        
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
                


def heuristic_function(node_i,goal_node,REBA_scores): # Current node i, the goal node goal, a weight w (between 0 and 1)
    
    w = 0.3
    
    distance = compute_distance(node_i, goal_node) # Euclidean distance
    ergonomic_score = REBA_scores[node_i]   # Geef REBA_scores dictionary mee als global variable
    
    h = w * distance + (1-w) * ergonomic_score
    
    return h

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

def compute_distance(tuple1,tuple2):
    return math.sqrt((tuple2[0] - tuple1[0])**2 + (tuple2[1] - tuple1[1])**2)


#path = A_Star_Algorithm(G,(0.2,1.0),(0.0,0.8))
    
