import math

def compute_ellips(distance,a,b,c):
    devisor = 1 - ((distance**2)/(b**2))
    new_a = math.sqrt(a**2 * devisor)
    new_c = math.sqrt(c**2 * devisor)
    
    return new_a, new_c
    