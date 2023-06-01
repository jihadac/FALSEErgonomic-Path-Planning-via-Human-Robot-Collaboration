import Paths_And_Scores as path_scores
import networkx as nx

def brute_force_search(tuples,start_node, goal_node, graph, scores):

    length = graph.number_of_nodes() # Get the number of nodes in the graph
    visited =[False]*(length)        # Mark all the vertices as not visited
    path = []                        # Create an array to store path
    list_all_paths = []              # Create an array to store all the paths

    # Generate all possible paths from start to goal
    all_paths = path_scores.generate_all_paths(start_node, goal_node, visited, path, tuples, graph, list_all_paths)

    lowest_score_path = []
    lowest_score = float('inf');

    for path in all_paths:
        score_path = path_scores.compute_score_path(path,scores)
        if score_path < lowest_score:
            lowest_score = score_path
            lowest_score_path = path
    
    return lowest_score_path, lowest_score
    

# tuples = [(1,1), (2,2), (3,3), (4,4)]
# scores = {(1,1):10, (2,2):20, (3,3):30, (4,4):40}
# graph = nx.DiGraph()
# graph.add_nodes_from(tuples)
# graph.add_edge((3,3),(4,4))
# graph.add_edge((3,3),(2,2))
# graph.add_edge((2,2),(4,4))
# graph.add_edge((4,4),(2,2))
# graph.add_edge((2,2),(1,1))
# graph.add_edge((4,4),(1,1))

# start_node = (3,3)
# goal_node = (1,1)
        