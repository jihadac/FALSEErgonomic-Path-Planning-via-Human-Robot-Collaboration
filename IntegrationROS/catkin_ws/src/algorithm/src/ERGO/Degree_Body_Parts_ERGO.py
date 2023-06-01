class Degrees_ERGO:
    
    def degree_body_parts_body_ERGO(self):
        
        path = 'C:/Users/jihad/Documents/VUB/Master 2/Master Thesis/Code/Fabrik/outputs/angles.txt'
        with open(path,'r') as angles_fabrik:
            content = angles_fabrik.readlines()
            
        neck_angle = float(content[1])
        neck_side = float(content[3])
        trunk_angle = float(content[7])
        trunk_side = float(content[9])
        legs_walking = 0
        legs_angle = float(content[13])
        load = 0
        

        degrees_body = [neck_angle, neck_side, trunk_angle, trunk_side, legs_walking, legs_angle, load]
        
        return degrees_body
    
    
    def degree_body_parts_arm_ERGO(self,trunk_angle):
        
        path = 'C:/Users/jihad/Documents/VUB/Master 2/Master Thesis/Code/Fabrik/outputs/angles.txt'
        with open(path,'r') as angles_fabrik:
            content = angles_fabrik.readlines()
            
        upper_arm_angle = float(content[41])
        shoulder_raised = float(content[49])
        arm_abducted = float(content[45])
        leaning = 1 if trunk_angle > 30 else 0
        lower_arm_angle = float(content[57])
        wrist_angle = float(content[61])
        wrist_twisted = float(content[69])


        degrees_arm = [upper_arm_angle, shoulder_raised, arm_abducted, leaning, lower_arm_angle, wrist_angle, wrist_twisted]
        
        return degrees_arm
    
   
