import sys
sys.path.insert(0, 'C:/Users/jihad/Documents/VUB/Master 2/Master Thesis/Code/Fabrik')
import Fabrik.Execution_Fabrik as fabrik
import REBA.Calculation_REBA_Score as reba


def computeScores(tuples,distance_circle):

    length = len(tuples)
    colors = []
    REBA_color = ''
    results_fabrik_list = []
    REBA_scores_list = []
    error = False


    for i in range(length):
        x = tuples[i][0]
        z = tuples[i][1]
    
        path = 'C:/Users/jihad/Documents/VUB/Master 2/Master Thesis/Code/Fabrik/inputs/target.txt'
        with open(path,'r') as target:
            content = target.readlines()
            #print(content)
        
        #old = content[0]
        content[0] = str(x) + ', ' + str(distance_circle) + ', ' + str(z) + '\n'

    
        with open(path,'w') as target:
            target.writelines(content)
            #print(content)
        
        result_fabrik, reach = fabrik.calcFabrik()
        results_fabrik_list.append(result_fabrik)
    
        if reach == 'Error':
            error = True
    
        if not reach:
            REBA_score = reba.rebaCalculation()
            #REBA_score_new = reba_ERGO.rebaCalculation_ERGO()
        else:
            REBA_score = 100 #Target is out of reach
        
        REBA_scores_list.append(REBA_score)

        if REBA_score == 100:
            REBA_color = '#FF33FC' #pink
        elif REBA_score >= 11:
            REBA_color = '#8B1A1A'
        elif REBA_score == 8 or REBA_score == 9 or REBA_score == 10:
            REBA_color = '#FF3030'
        elif REBA_score == 4 or REBA_score == 5 or REBA_score == 6 or REBA_score == 7:
            REBA_color = '#FF8C00'
        elif REBA_score == 2 or REBA_score == 3:
            REBA_color = '#FFD700'
        else:
            REBA_color = '#76EE00'
    
        colors.append(REBA_color)

    return colors, REBA_scores_list, results_fabrik_list, error



