from openpyxl import load_workbook

class Degrees:
    
    def degree_body_parts(self):
        
        path = 'C:/Users/jihad/Documents/VUB/Master 2/Master Thesis/Code/Fabrik/outputs/angles.txt'
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
    
    def degree_body_parts_XSens(self,worksheet,row):
        
        columns = ['B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W']
        
        neck_degrees = [worksheet[columns[0]+str(row)].value, worksheet[columns[1]+str(row)].value, worksheet[columns[2]+str(row)].value]
        trunk_degrees = [worksheet[columns[3]+str(row)].value, worksheet[columns[4]+str(row)].value, worksheet[columns[5]+str(row)].value]
        leg_degrees = [worksheet[columns[6]+str(row)].value, worksheet[columns[7]+str(row)].value]
        UA_degrees = [worksheet[columns[8]+str(row)].value, worksheet[columns[9]+str(row)].value, worksheet[columns[10]+str(row)].value, worksheet[columns[11]+str(row)].value, worksheet[columns[12]+str(row)].value, worksheet[columns[13]+str(row)].value]
        LA_degrees = [worksheet[columns[14]+str(row)].value, worksheet[columns[15]+str(row)].value]
        wrist_degrees = [worksheet[columns[16]+str(row)].value, worksheet[columns[17]+str(row)].value, worksheet[columns[18]+str(row)].value, worksheet[columns[19]+str(row)].value, worksheet[columns[20]+str(row)].value, worksheet[columns[21]+str(row)].value]
        
        degrees = [neck_degrees, trunk_degrees, leg_degrees, UA_degrees, LA_degrees, wrist_degrees]
        
        return degrees
        

#angles = Degrees()
#d = angles.degree_body_parts()