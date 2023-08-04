// Rosie Khurmi
// July 2023
// Tic_Tac_Toe will simulate a game of tic-tac-toe between 2 players 

#include "Tic_Tac_Toe.h"

// Parameterized Constructor, takes in size of board
TTT::TTT (int s) { 
    this->size = s;
    this->board.resize(this->size, std::vector<char>(this->size, '-'));
}

// Getters
std::vector<std::vector<char>> TTT::getBoard() {
    return this->board;
}

int TTT::getSize() {
    return this->size;
}

// Setters
void TTT::setBoard (int size) {
    this->size = size;
    this->board.resize(size, std::vector<char>(size, '-'));
}

// Equality Checkers

// checkDiagonalLeft() takes in the number of the player 
// Returns true if the top left to bottom right is the same, otherwise false
bool TTT::checkDiagonalLeft(int player) {

    int count = 0; // Counter for how many in a diagonal
    char compare; // Comaprison variable
    
    // Change comapre depending if its the turn of player 1 or player 2
    if (player == 1) {
        compare = 'X';
    } else if (player == 2) {
        compare = 'O';
    }

    // Go through rows
    for (int i = 0; i < this->size; i++) {
        // Go through columns
        for (int j = 0; j < this->size; j++) {
            // Increase counter if piece on left diagonals on board match compare
            if ((this->board[i][j] == compare) && (i == j)) {
                count ++;
            }

        }
    }

    // Return true if counter is the same size as board, otherwise false
    if (count == this->size) {
        return true;
    }
    return false;

}

// checkDiagonalLeft() takes in the number of the player 
// Returns true if the top right to bottom left is the same, otherwise false
bool TTT::checkDiagonalRight(int player) {

    int count = 0; // Counter for how many in a diagonal
    char compare; // Comaprison variable
    
    // Change comapre depending if its the turn of player 1 or player 2
    if (player == 1) {
        compare = 'X';
    } else if (player == 2) {
        compare = 'O';
    }

    // Go through rows
    for (int i = 0; i < this->size; i++) {
        // Go through columns
        for (int j = 0; j < this->size; j++) {
            // Increase counter if piece on right diagonals on board match compare
            if ((this->board[i][j] == compare) && (j == (this->size- 1) - i)) {
                count ++;
            }

        }
    }

    // Return true if counter is the same size as board, otherwise false
    if (count == this->size) {
        return true;
    }
    return false;

}

// checkRows() takes in the number of the player 
// Returns if all the same are in any row
bool TTT::checkRows(int player) { 

    int count = 0; // Counter for how many in a row
    char compare; // Comaprison variable
    
    // Change comapre depending if its the turn of player 1 or player 2
    if (player == 1) {
        compare = 'X';
    } else if (player == 2) {
        compare = 'O';
    }
    
    // Go through each row
    for (int i = 0; i < this->size; i++) {
        // Use this loop to check if each column of the row matches compare
        for (int j = 0; j < this->size; j++) {
            if (this->board[i][j] == compare) {
                count ++;
            }
        }
        // If counter equals total size in the row, return true
        if (count == this->size) {
            return true;
        // Else, set the count to 0 and repeat the process for the other rows
        } else {
            count = 0;
        }
    }

    // If no wins are found, return false
    return false;

}

// checkColumns() takes in the number of the player 
// Returns if all the same are in any row
bool TTT::checkColumns(int player) {

    int count = 0; // Counter for how many in a column
    char compare; // Comaprison variable
    
    // Comaprison variable
    if (player == 1) {
        compare = 'X';
    } else if (player == 2) {
        compare = 'O';
    }
    
    // Go through each column
    for (int i = 0; i < this->size; i++) {
        // Use this loop to check if each row of the column matches compare
        for (int j = 0; j < this->size; j++) {
            if (compare == this->board[j][i]) {
                count ++;
            }
        }

        // If counter equals total size in the row, return true
        if (count == this->size) {
            return true;
        // Else, set the count to 0 and repeat the process for the other rows
        } else {
            count = 0;
        }

    }

    // If no wins are found, return false
    return false;

}

// enterValue() takes in player number
// Adds the player piece to the game board
void TTT::enterValue(int player) {

    std::cout << "\nPlayer " << player << std::endl << std::endl; 

    int row, column;

    std::cout << "Enter a Column: ";
    std::cin >> column;

    std::cout << "Enter a Row: ";
    std::cin >> row;

    // If the user chosen square is empty, add the corresponding piece
    if (this->board[row - 1][column - 1] == '-') {
        if (player == 1) {
        this->board[row - 1][column - 1] = 'X';
        } if (player == 2) {
        this->board[row - 1][column - 1] = 'O';
        }
    }
    // Else, ask user to enter again
    else {
        std::cout << "\nInvalid Choice\n" << std::endl;
        enterValue(player);
    }

}

// checkFull() checks if the game board is full
// Returns true or false accordingly
bool TTT::checkFull() {

    for (int i = 0; i < this->size; i++) {
       for (int j = 0; j < this->size; j++) {
            if (this->board[i][j] == '-') {
                return false;
            }
        } 
    }

    return true;

}

// displayBoard() prints what is in the board at any given time
void TTT::displayBoard() {

    std::cout << "\nBOARD\n" << std::endl;

    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            std::cout << "   " << this->board[i][j] << "   ";
        } 
        std::cout << std::endl;
    }

}

// getSizeBoard() takes in a pointer to the game board size
/* Asks user what size board they want and modifies size to that value
if => 3 */
void getSizeBoard(int* size) {

    std::cout << "Enter the size of board you would like: ";
    std::cin >> *size;
    
    if (*size < 3) {
        std::cout << "The size of the board must be at least 3 units\n" << std::endl;
        getSizeBoard(size);
    }

}

// playGame() is a static method that takes in a TTT object and a pointer to the player
// Executes the tic-tac-toe game
void playGame(TTT game, int* player) {

        // Execute while the board is not full
        while (game.checkFull() != true) {
 
        // Using pointers allows player variable to be modifed in memory
        game.enterValue(*player);
        game.displayBoard();

        // If there is a match anyhwere, exit the method 
        if (game.checkDiagonalLeft(*player) || game.checkDiagonalRight(*player) 
        || game.checkColumns(*player) || game.checkRows(*player)) {
            std::cout << "\nPLAYER " << *player << " HAS WON THE GAME" << std::endl;
            return;
        // Else, switch players and execute loop again
        } else {
            if (*player == 1) {
                *player = 2;
            } else if (*player == 2) {
                *player = 1;
            }
        } 


    }

}