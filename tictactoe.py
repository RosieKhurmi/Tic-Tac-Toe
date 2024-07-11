# Rosie Khurmi
# September 2, 2023

"""
Tic Tac Toe Player
"""

import math
import copy

X = "X"
O = "O"
EMPTY = None

# initial_state() returns an empty 3 x 3 board
def initial_state():

    return [
        [EMPTY, EMPTY, EMPTY],
        [EMPTY, EMPTY, EMPTY],
        [EMPTY, EMPTY, EMPTY]
    ]

# player() returns which player has the next turn on the board
# @param board: 3 x 3 board
def player(board):

    # Count the number of X's and O's on the board
    x_count = sum(row.count('X') for row in board)
    o_count = sum(row.count('O') for row in board)

    # If X = X, return X, else O
    player = X if x_count <= o_count else O
    return player

# actions() returns a set of all possible actions (i, j) available on the board
# @param board: 3 x 3 board   
def actions(board):

    options = set() # Hold all options in a set

    # Go through 2D array
    # If there is an empty spot, add its coordinates to the set
    for r in range(len(board)):
        for c in range(len(board)):
            if board[r][c] == EMPTY:
                options.add((r, c))

    return options # Return all possible option

# result() returns the board that results from making move (i, j) on the board
# @param board: 3 x 3 board, action: set of (i, j)
def result(board, action):

    # Create a deep copy of the board
    result = copy.deepcopy(board)

    r = action[0] # Row
    c = action[1] # Colum

    # If the sopt is empty, append the corresponding player
    # Else raise an exception
    if result[r][c] == EMPTY:
        result[r][c] = player(result)
        return result
    else:
        raise ValueError

# winner() returns the winner of the game, if there is one
# @param board: 3 x 3 board
def winner(board):

    winner = None

    # Check if top to bottom diagonal is all the same
    if board[0][0] == board[1][1] == board[2][2]:
        # Return X or O depending who gets all the same
        winner = X if board[0][0] == X else O if board[0][0] == O else None
        
    # Check if bottom to top diagonal is all the same
    if board[0][2] == board[1][1] == board[2][0]:
        # Return X or O depending who gets all the same
        winner = X if board[0][2] == X else O if board[0][2] == O else None
        
    # Check matching in any 3 rows
    for r in board: 
        if r[0] == r[1] == r[2]:
            # Return X or O depending who gets all the same
            winner = X if r[0] == X else O if r[0] == O else None

    # Check matching in any 3 columns     
    for c in range(len(board)): 
        if board[0][c] == board[1][c] == board[2][c]:
            # Return X or O depending who gets all the same
            winner = X if board[0][c] == X else O if board[0][c] == O else None
            
    return winner

# terminal() returns True if the game is over, False otherwise
# @param board: 3 x 3 board
def terminal(board):

    # If a winner has been declared or there are no spaces on the board
    # Return True, else False
    if (winner(board) or (len(actions(board)) == 0)):
        return True
    else:
        return False

# utility() returns 1 if X has won the game, -1 if O has won, 0 otherwise
# @param board: 3 x 3 board
def utility(board):

    # If board has reached terminal
    if terminal(board):
        # Return 1 if X has won
        if winner(board) == X:
            return 1 
        # Return -1 if O won
        elif winner(board) == O:
            return -1
        # Return 0 if tie
        else:
            return 0 

# optimal() returns the optimal action for the current player on the board
# @param board: 3 x 3 board, depth: int
def optimal(board, depth = 0):

    # If the board is at terminal, return the winner and no possible solution  
    if terminal(board):
        return utility(board), None
    
    # Else perform minimax
    else:

        move = set() # Hold best move

        if player(board) == X: # Maximizing Player
            best = float('-inf') # Optimal Value - Try to get to 1
    
            # Go through all empty spots
            for a in actions(board):
                # Perform a recursive call of the fuction with all possible spots
                temp, m = optimal(result(board, a))

                # If the result is a larger value, change best and store the move
                if temp > best:
                    best = temp
                    move = a
    
            # Return best and move
            return best, move
        
        elif player(board) == O: # Minimizing Player

            best = float('inf')  # Optimal Value - Try to get to -1

            # Go through all empty spots
            for a in actions(board):
                # Perform a recursive call of the fuction with all possible spots
                temp, m = optimal(result(board, a))

                # If the result is a smaller value, change best and store the move
                if temp < best:
                    best = temp
                    move = a

            # Return best and move
            return best, move

# minimax() returns the optimal action for the current player on the board
# @param board: 3 x 3 board
def minimax(board):

    # Call optimal and return the move
    value, move = optimal(board)
    return move

 









    



    











    









   


