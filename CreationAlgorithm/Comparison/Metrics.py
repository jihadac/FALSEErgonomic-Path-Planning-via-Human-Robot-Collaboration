import math

def compute_length_path(path):
    distance = 0
    length = len(path)
    for i in range(length-1):
        distance += math.dist(path[i], path[i+1])
        
    return distance

def compute_total_score_path(path,REBA_tuple_dictionary):
    
    total_score = 0
    for node in path:
        total_score += REBA_tuple_dictionary[node]
        
    total_score -= REBA_tuple_dictionary[path[0]] # Score of first node in path must not be considered in sum
    
    return total_score
        
def number_of_nodes_path(path):
    return len(path)
