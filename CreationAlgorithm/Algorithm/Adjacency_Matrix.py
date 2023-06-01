import numpy as np
import math


def createAdjacencyMatrix(tuples,step,length,REBA):

    M = np.zeros((length, length)) # Adjacency matrix    

    for i in range(length):
        for j in range(length):
            distance = math.dist(tuples[i],tuples[j])
            
            if tuples[i] == tuples[j]:
                continue # Value in matrix M is by default already equal to zero
            elif round(distance,14) != step and round(distance,14) != round(math.sqrt(2)*step,14):
                continue # Value in matrix M is by default already equal to zero
            else:
                M[i][j] = REBA[j] # Weight of the edge corresponds to REBA score of node to which you go


    return M