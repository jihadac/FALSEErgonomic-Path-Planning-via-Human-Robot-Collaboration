import sys
sys.path.insert(0, 'C:/Users/jihad/Documents/VUB/Master 2/Master Thesis/Code')
import REBA.Degree_Body_Parts as DEG
import REBA.body_part_reba_calculator.Degree_to_REBA as reba

def rebaCalculation():
    
    angles = DEG.Degrees()
    joints_degrees = angles.degree_body_parts()
    
    m_reba = reba.DegreeToREBA(joints_degrees)
    REBA_scores = m_reba.reba_computation()
    
    return REBA_scores[0]


