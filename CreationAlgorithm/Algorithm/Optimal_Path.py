import Score_Candidate_Points as ScoresAndPoints

initial_REBA_score = 12 #Now just an example
initial_X = 0.395
initial_Z = 0.395

def findGoal(initial_node,REBA_tuple_directionary,scores,X,Z,length):

    MoreErgo_scores = []
    MoreErgo_X = []
    MoreErgo_Z = []

    # Add initial values to lists
    MoreErgo_X.append(initial_X)
    MoreErgo_Z.append(initial_Z)
    MoreErgo_scores.append(initial_REBA_score)

    length_MoreErgo = len(MoreErgo_scores)
    element_added = False


    # Check if candidate point has a more ergonomic score than the rest 

    for i in range(length): # Check for all the elements in scores
        for j in range(length_MoreErgo): # For each element in scores verify its position in the MoreErgo list
            if element_added == False and scores[i] < MoreErgo_scores[j]:
                MoreErgo_scores.insert(j,scores[i])
                MoreErgo_X.insert(j,X[i])
                MoreErgo_Z.insert(j,Z[i])
                element_added = True # Every score can only be added once
        if element_added == False: # If the score is bigger than the elements in MoreErgo, just add it at the end
            MoreErgo_scores.append(scores[i]) 
            MoreErgo_X.append(X[i])
            MoreErgo_Z.append(Z[i])
        
        length_MoreErgo = len(MoreErgo_scores)
        element_added = False # Reinitialize parameter for new score in scores
            
      
