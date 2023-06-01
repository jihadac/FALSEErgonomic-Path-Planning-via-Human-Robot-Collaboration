class Degrees:
    
    def degree_body_parts(self):
        
        path = '/home/mainuser/Jihad/catkin_ws/src/algorithm/src/Fabrik/outputs/angles.txt'
        with open(path,'r') as angles_fabrik:
            content = angles_fabrik.readlines()
            
        neck_degrees = [float(content[1]), float(content[3]), float(content[5])]
        trunk_degrees = [float(content[7]), float(content[9]), float(content[11])]
        leg_degrees = [float(content[13]), float(content[15])]
        UA_degrees = [float(content[41]), float(content[43]), float(content[45]), float(content[47]), float(content[49]), float(content[51])]
        LA_degrees = [float(content[57]), float(content[59])]
        wrist_degrees = [float(content[61]), float(content[63]), float(content[65]), float(content[67]), float(content[69]), float(content[71])]

        degrees = [neck_degrees, trunk_degrees, leg_degrees, UA_degrees, LA_degrees, wrist_degrees]
        
        return degrees
    

#angles = Degrees()
#d = angles.degree_body_parts()
