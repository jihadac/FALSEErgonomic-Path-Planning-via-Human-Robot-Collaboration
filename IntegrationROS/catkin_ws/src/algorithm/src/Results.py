import Fabrik.Execution_Fabrik as fabrik
import matplotlib.pyplot as plt
import numpy as np

# Plot the original and new configuration of human body

def plotHumanConfiguration(colors_list,results_fabrik,a,b,c,step,length,height_circle,distance_circle):
        
    for i in range(length):
        
        res_fabrik = results_fabrik[i]
        fabrik.drawFabrik(res_fabrik,i,colors_list,a,b,c,step,height_circle,distance_circle)
    

# Plot circle only

def plotCircle(colors_list,a,b,c,REBA_tuple_dictionary,length,height_circle):
    
    theta = np.linspace(0, 2*np.pi, 150)
    u = a * np.cos(theta)
    v = c * np.sin(theta)+height_circle

    figure, axes = plt.subplots(1)
    axes.plot(u,v)
    axes.set_aspect(1) #Same scale for x and z
    
    i = 0
    
    for point in REBA_tuple_dictionary:    # point represents a tuple (x,z) in the list tuples
        plt.scatter(point[0], point[1], color=colors_list[i])
        if REBA_tuple_dictionary[point] != 100: # Only add the score next to the point if it is reachable by both human and robot
            axes.text(point[0]+0.04,point[1]-0.025,REBA_tuple_dictionary[point])
        i += 1
    
    plt.title('Color score for the different candidate points')
    plt.grid(True)
    plt.show()
    