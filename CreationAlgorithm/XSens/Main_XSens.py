from openpyxl import load_workbook
import XSens.Results_XSens as results

file = 'C:/Users/jihad/Documents/VUB/Master 2/Master Thesis/Code/XSens/Joint_Angles_XSens.xlsx' # Path to Excel file
wb = load_workbook(file,data_only=True)           # Load Excel file
worksheet = wb['Distance2']

reachable_points = results.readReachablePoints()
unreachble_points = results.readUnreachablePoints()

reachable_points_fabrik = results.adaptPointsForFabrik(reachable_points)
unreachable_points_fabrik = results.adaptPointsForFabrik(unreachble_points)

scores_reachable_points = results.computeScoresXSens(worksheet)
#scores_reachable_points[19] = 9
#scores_reachable_points[30] = 4
color_score_reachable_points = results.determineColor(scores_reachable_points)

results.plotScoresXSens(scores_reachable_points, color_score_reachable_points, reachable_points_fabrik, unreachable_points_fabrik)