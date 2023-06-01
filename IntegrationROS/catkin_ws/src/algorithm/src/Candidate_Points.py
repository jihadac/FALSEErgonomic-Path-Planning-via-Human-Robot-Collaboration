import numpy as np
import Computation_Ellips as ellips


def candidatePoints(a,b,c,distance_circle,height_circle,step):
    
    # Parameters of ellips representing 2D workspace
    a, c = ellips.compute_ellips(distance_circle,a,b,c)
    
    # Each point/node is represented as a tuple(x,z)
    tuples = []
    
    
    for x in np.arange(-a,a+step,step):
        for z in np.arange(-0.200,height_circle+c+step,step):
            if (x**2/(a**2))+((z-height_circle)**2/(c**2)) <= 1:
                tuples.append((round(x,4),round(z,4)))         
    return tuples, a, c

#t = candidatePoints(0.855,0.25)