import numpy as np
import Computation_Ellips as ellips

def candidatePoints(a,b,c,distance_circle,height_circle,step):
    
    # Parameters of ellips representing 2D workspace
    a, c = ellips.compute_ellips(distance_circle,a,b,c)
    
    # Each point/node is represented as a tuple(x,z)
    tuples = []
    
    
    for x in np.arange(-a,a+step,step):
        for z in np.arange(-0.200,height_circle+c+step,step):
            if ((x**2)/(a**2))+((z-height_circle)**2/(c**2)) <= 1:
                tuples.append((round(x,4),round(z,4)))         
    return tuples, a, c


    # for x in np.arange(-rad,rad+1,step): #WRM +2. Er is een probleem met r=0.2 en step = 0.1
    #     for z in np.arange(-rad,rad+1,step):
    #         y = x**2 + (z-height_circle)**2
    #         if x**2 + (z-height_circle)**2 <= rad**2:
    #             tuples.append((round(x,4),round(z,4)))

#t = candidatePoints(0.855,0.25)
# a = 0.855
# b = 0.855
# c = 0.775
# step = 0.155 #0.25         # Distance between the candidate points
# height_circle = 0.415         # Height centre point circle with respect to origin
# distance_circle = 0.42        # Distance in y direction with respect to origin --> determines how far circle is from human
#t = candidatePoints(a,b,c,distance_circle,height_circle,step)