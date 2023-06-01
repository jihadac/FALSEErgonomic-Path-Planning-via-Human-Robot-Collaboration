import Read_Data as data
import os
import shutil

def rewrite_input_file(only_distance,distance_human_robot): # only_distance = Boolean to determine if only the distance needs to be changed in the input txt file or not
    
    path = 'C:/Users/jihad/Documents/VUB/Master 2/Master Thesis/Code/Fabrik/inputs/joints_position.txt'
    path_fixed = 'C:/Users/jihad/Documents/VUB/Master 2/Master Thesis/Code/Fabrik/inputs/joints_position_fixed.txt'
    path_temp = 'C:/Users/jihad/Documents/VUB/Master 2/Master Thesis/Code/Fabrik/inputs/joints_position_temp.txt'    

    counter = 1;

    if only_distance == False:
        joint_positions = data.extract_joint_posisitions_for_fabrik()
    
        with open(path,'w') as target:
            for joint in joint_positions:
                content = str(joint[0]) + ' ' + str(joint[1]) + ' ' + str(joint[2]) + '\n'
                target.writelines(content)
    else:
        with open(path, 'r') as file_in:
            lines = file_in.readlines()  # Read all lines into memory
    
        with open(path_temp, 'w') as file_out:
            #with open(path, 'w') as file_out:
            for line in lines:
                values = line.strip().split()
                if counter == 14 or counter == 17:
                    values[1] = str(distance_human_robot-0.25)  # Replace y-coordinate (2nd element), which corresponds to the distance of human wrt robot (FABRIK frame)
                else:
                    values[1] = str(distance_human_robot)  # Replace y-coordinate (2nd element), which corresponds to the distance of human wrt robot (FABRIK frame)
                updated_line = ' '.join(values)
                file_out.write(updated_line + '\n')
            
                counter += 1

    # Replace the original file with the temporary file
    # os.replace(path_temp, path)
    # Copy the source file to the destination file
    shutil.copyfile(path_temp, path)

    # Paste the content from joint_position.txt into joint_position_fixed.txt
    with open(path, 'r') as source_file:            # Open the source file for reading
        content = source_file.read()                # Read the contents of the source file


    with open(path_fixed, 'w') as destination_file: # Open the destination file for writing
        destination_file.write(content)             # Write the contents to the destination file
     
        
distance_human_robot = 0.80#0.805
#rewrite_input_file(False,distance_human_robot) 
rewrite_input_file(True,distance_human_robot) 