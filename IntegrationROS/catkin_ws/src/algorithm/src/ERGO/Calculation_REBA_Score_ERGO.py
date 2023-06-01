import sys
sys.path.insert(0, 'C:/Users/jihad/Documents/VUB/Master 2/Master Thesis/Code')
import ERGO.Degree_Body_Parts_ERGO as DEG
from ergonomics.reba import RebaScore
import requests
import numpy as np

def rebaCalculation_ERGO():
    
    rebaScore = RebaScore()
    
    angles = DEG.Degrees_ERGO()
    joints_degrees_body = angles.degree_body_parts_body_ERGO()
    joints_degrees_arm = angles.degree_body_parts_arm_ERGO(joints_degrees_body[2])

    rebaScore.set_body(joints_degrees_body)
    score_a, partial_a = rebaScore.compute_score_a()
    
    rebaScore.set_arms(joints_degrees_arm)
    score_b, partial_b = rebaScore.compute_score_b()

    
    score_c, caption = rebaScore.compute_score_c(score_a, score_b)
    
    return score_c

#test = rebaCalculation_ERGO()



