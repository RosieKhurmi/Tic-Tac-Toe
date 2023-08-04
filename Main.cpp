// Rosie Khurmi
// July 2023
// Tic_Tac_Toe will simulate a game of tic-tac-toe between 2 players 

#include "Tic_Tac_Toe.cpp"

int main() {

    std::cout << "----- TIC TAC TOE -----" << std::endl << std::endl;

    int player = 1; // Track player


    int size; // Hold size of board
    // call getSizeBoard()
    getSizeBoard(&size);

    TTT game(size);

    playGame(game, &player);

}