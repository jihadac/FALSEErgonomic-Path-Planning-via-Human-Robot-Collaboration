import queue
import timeit
from memory_profiler import profile

#@profile
def Dijkstras_Algorithm(graph,start_node,goal_node,M,tuples):
    
    number_node_expansions = 0
    
    start_time = timeit.default_timer()
    # Dictionary assigning to every node in the graph an ergonomic score/cost of infinity 
    ergonomic_scores_nodes = {node: float('inf') for node in graph} 

    # Ergonomic score of start node is equal to zero
    ergonomic_scores_nodes[start_node] = 0
    
    # Create dictionary to store the parent nodes
    parent = {}
    
    # Set keeping track of already visisted nodes
    visited_nodes = set([])
    
    # Priority queue
    priority_queue = queue.PriorityQueue()
    priority_queue.put((0,start_node))
    
    while priority_queue: # While priority_queue is not empty
        
        # Extract from priority the node with the smallest total cost
        sum_cost, current_node = priority_queue.get()
        # Add current_node to the set of visited nodes
        visited_nodes.add(current_node)
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
            
            if neighbor in visited_nodes:
                continue
            
            # Calculate and compare the cost from the initial node to the considered neighbor
            initial_score = ergonomic_scores_nodes[neighbor]
            updated_score = ergonomic_scores_nodes[current_node] + cost(current_node, neighbor, tuples, M)
            if updated_score < initial_score:
                priority_queue.put((updated_score,neighbor))
                ergonomic_scores_nodes[neighbor] = updated_score
                parent[neighbor] = current_node
                
    return None


def cost(from_node,to_node,tuples,M):
    F = tuples.index(from_node)
    T = tuples.index(to_node)
    return M[F][T]

def reconstruction_path(current_node,start_node,parent):
    path = [current_node]
    
    while current_node != start_node:
        current_node = parent[current_node]
        path.append(current_node)
    
    path.reverse()
    
    return path
