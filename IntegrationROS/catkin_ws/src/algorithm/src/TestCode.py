scores = [9,10,9,7,13]
MoreErgo_scores = [12]

length = len(scores)
length_MoreErgo = len(MoreErgo_scores)

element_added = False

for i in range(length): # Check for all the elements in scores
    for j in range(length_MoreErgo): # For each element in scores verify its position in the MoreErgo list
        if element_added == False and scores[i] < MoreErgo_scores[j]:
            MoreErgo_scores.insert(j,scores[i])
            element_added = True # Every score can only be added once
    if element_added == False: # If the score is bigger than the elements in MoreErgo, just add it at the end
        MoreErgo_scores.append(scores[i]) 
        
    length_MoreErgo = len(MoreErgo_scores)
    element_added = False # Reinitialize parameter for new score in scores
    
print(MoreErgo_scores)