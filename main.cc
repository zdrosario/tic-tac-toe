#include <iostream>
#include <stdexcept>
#include "tictactoe.h"

int main() {
    // Info printed;
    std::cout << "Move format: xy" << std::endl;
    std::cout << "       x" << std::endl;
    std::cout << "  | 0| 1| 2" << std::endl;
    std::cout << " 0|00|10|20" << std::endl;
    std::cout << "y1|10|11|21" << std::endl;
    std::cout << " 2|20|21|22" << std::endl << std::endl;

    TicTacToe game;
    while ( !(game.checkIsOver()) ) {
        char player = game.getCurPlayer();
        char x, y;
        std::cout << "It is " << player << "'s turn." << std::endl;
        std::cout << game;
        
        // get move:
        while( true ) {
            std::cin >> x;
            std::cin >> y;

            // Input check:
            if ( x < '0' || x > '2' || y < '0' || y > '2' ) {
                std::cout << "Invalid move." << std::endl;
                continue;
            } // if

            try { game.doMove( x - '0', y - '0' ); }
            catch ( std::runtime_error ) {
                std::cout << "Invalid move." << std::endl;
                continue;
            } //

            break;
        } // while
    } // while

    std::cout << game.getWinner() << " wins!" << std::endl;

} // main
