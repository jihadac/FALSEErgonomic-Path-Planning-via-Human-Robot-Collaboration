from Fabrik.fabrik_full_body import fabrik, input_reader



def calcFabrik():
    reader = input_reader.InputReader()
    manipulator = fabrik.FABRIK(reader.joints(),
                         reader.initial_joints_position(), 
                         reader.orientation(), 
                         reader.target_position(),
                         reader.target_orientation(), 
                         reader.joints_constraints(),
                         reader.constraint_type(),
                         reader.bone_orientation_limit())

    calcFabrik.man = manipulator #Needed to avoid original pose and new pose to be the same on plot!
    
    reach = manipulator.solve()
    
    return manipulator, reach

    
def drawFabrik(res_fabrik,counter,colors,a,b,c,step,height_circle,distance_circle):
    
    #manipulator = calcFabrik.man #See comment above
    manipulator = res_fabrik
    manipulator.drawing(counter,colors,a,b,c,step,height_circle,distance_circle)
    
#if __name__ == "__main__": #Moet het main zijn, of calcFabrik
#    calcFabrik()