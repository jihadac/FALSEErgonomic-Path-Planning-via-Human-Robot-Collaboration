import math

def compute_ellips(distance,a,b,c):
    devisor = 1 - ((distance**2)/(b**2))
    new_a = a*math.sqrt(devisor)
    new_c = c*math.sqrt(devisor)
    
    return new_a, new_c
    