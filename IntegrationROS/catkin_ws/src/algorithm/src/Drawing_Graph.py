import matplotlib.pyplot as plt
import numpy as np

def drawPath(path,REBA_tuple_dictionary,colors_list,a,b,c,length,height_circle):

    theta = np.linspace(0, 2*np.pi, 150)
    u = a * np.cos(theta)
    v = c * np.sin(theta)+height_circle
    
    figure, axes = plt.subplots(1)
    axes.plot(u,v)
    axes.set_aspect(1) #Same scale for x and z

    i = 0

    for point in REBA_tuple_dictionary:    # point represents a tuple (x,z) in the list tuples
        plt.scatter(point[0], point[1], color =colors_list[i])
        if REBA_tuple_dictionary[point] != 100: # Only add the score next to the point if it is reachable by both human and robot
            axes.text(point[0]+0.04,point[1]-0.025,REBA_tuple_dictionary[point])
        i += 1
        
    # for i in range(length):
    #     plt.scatter(tuples[i][0],tuples[i][1],c=colors_list[i])

    # for i in path:
    #     plt.scatter(i[0],i[1],c='#BF3EFF')

    for i in range(len(path)-1):
        plt.arrow(path[i][0],path[i][1],path[i+1][0]-path[i][0],path[i+1][1]-path[i][1], head_width=0.05, length_includes_head=True, lw=0.5,color='#BF3EFF')

#plt.arrow(0,0.8,0,0.2,head_width=0.02, head_length=0.02, color='#BF3EFF')


    plt.title('Most ergonomic path')
    plt.grid(True)
    plt.show()