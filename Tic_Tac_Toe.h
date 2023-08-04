// Rosie Khurmi
// July 2023
// Tic_Tac_Toe will simulate a game of tic-tac-toe between 2 players 

#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <iostream> 
#include <vector> 

// TTT Class creates a Tic-Tac-Toe object
class TTT {

    private: // Data members
        std::vector<std::vector<char>> board;
        int size;

    public:

        TTT (int s); // Parameterized Constructor
        std::vector<std::vector<char>> getBoard(); // Getter
        int getSize();
        void setBoard (int s); // Setter

        // Equality Checker
        bool checkDiagonalLeft(int player);
        bool checkDiagonalRight(int player);
        bool checkRows(int player);
        bool checkColumns(int player);

        // Game Functions
        void enterValue(int player);
        bool checkFull();
        void displayBoard();

};

#endif