import XSens.Main_XSens as xsens
import Main as main


REBA_tuple_dictionary = main.REBA_tuple_dictionary
list_reachable_points_robot = main.list_reachable_points_robot
colors = main.colors

reachable_points_fabrik = xsens.reachable_points_fabrik
scores_reachable_points = xsens.scores_reachable_points
color_score_reachable_points = xsens.color_score_reachable_points

length = len(list_reachable_points_robot)


# Define risk levels
LowRisk = [2,3]
MediumRisk = [4,5,6,7]
HighRisk = [8,9,10]

# Define counters
counter_same_score = 0      # Number of points for which scores are identical
counter_lower_score = 0     # Number of points for which score FABRIK < score XSens
counter_higher_score = 0    # Number of points for which score FABRIK > score XSens
counter_same_risk_level = 0 # Number of points for which scores are in same risk level

counter_difference_scores = 0

for i in range(length):
    score_fabrik = REBA_tuple_dictionary[list_reachable_points_robot[i]]
    score_xsens = scores_reachable_points[i]

    if score_fabrik == score_xsens:
        counter_same_score += 1
    elif score_fabrik < score_xsens:
        counter_lower_score += 1
    else:
        counter_higher_score += 1
        
    if (score_fabrik in LowRisk) and (score_xsens in LowRisk):
        counter_same_risk_level += 1
    elif (score_fabrik in MediumRisk) and (score_xsens in MediumRisk):
        counter_same_risk_level += 1
    elif (score_fabrik in HighRisk) and (score_xsens in HighRisk):
        counter_same_risk_level += 1
    
    counter_difference_scores += abs(score_fabrik-score_xsens)
    


percentage_same_score = (counter_same_score/length)*100
percentage_lower_score = (counter_lower_score/length)*100
percentage_higher_score = (counter_higher_score/length)*100
percentage_same_risk_level = (counter_same_risk_level/length)*100

MSE = counter_difference_scores/length

print('Percentage same score',str(percentage_same_score))
print('Percentage lower score',str(percentage_lower_score))
print('Percentage higher score',str(percentage_higher_score))
print('Percentage same risk level',str(percentage_same_risk_level))

print('MSE is equal to',str(MSE))




    
    