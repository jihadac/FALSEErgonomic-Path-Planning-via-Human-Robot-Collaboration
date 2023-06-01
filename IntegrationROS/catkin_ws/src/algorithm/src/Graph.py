import matplotlib.pylab as plt
import networkx as nx


def createGraph(M,tuples,length):


    G = nx.DiGraph() # Directional graph

    # Add a list of tuples as nodes to the graph G
    G.add_nodes_from(tuples)

    # Define a list of edges with weights
    for i in range(length):
        for j in range(length):
            if M[i][j] != 0:
                G.add_edge(tuples[i],tuples[j],weight=M[i][j])
    return G

# zet in method en return graph

#res = nx.algorithms.shortest_paths.dijkstra_path(G,tuples[0],tuples[15])
            
#### DIT IN EEN APARTE METHOD ZETTEN ####         
# pos = nx.spring_layout(G)
# nx.draw(G, pos, node_color='b', width=2, with_labels=True, connectionstyle='arc3, rad = 0.1')
# edge_weights = nx.get_edge_attributes(G, 'weight')
# nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_weights, label_pos=0.75, verticalalignment="top")
# plt.show()
#########################################

# plt.rcParams["figure.figsize"] = [7.50, 3.50]
# plt.rcParams["figure.autolayout"] = True

# G = nx.DiGraph()

# G.add_nodes_from([1, 2, 3, 4])
# G.add_edges_from([(1, 2), (2, 3), (3, 4), (4, 1), (1, 3)])

# pos = nx.spring_layout(G)

# weights = [3] * len(G.edges())

# nx.draw(G, pos, node_color='b', edge_color=weights, width=2, with_labels=True)

# edge_labels = {edge: label for edge, label in zip(G.edges(), ['x', 'y', 'w', 'z', 'v'])}

# nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, label_pos=0.75)

# plt.show()
