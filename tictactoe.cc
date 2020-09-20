#include <stdexcept>
#include "tictactoe.h"

// STATIC VARS
array< array<int,3>, 8 > TicTacToe::winLines{
    array<int,3>{0,1,2},
    array<int,3>{3,4,5},
    array<int,3>{6,7,8},
    array<int,3>{0,3,6},
    array<int,3>{1,4,7},
    array<int,3>{2,5,8},
    array<int,3>{0,4,8},
    array<int,3>{2,4,6},
}; // winLines

// CONSTRUCTOR
TicTacToe::TicTacToe(): isOver{ false }, curPlayer{ 'X' } {
    board.fill('.');
} // constructor

//
// HELPER METHODS
//

int TicTacToe::posToLoc( int x, int y ) {
    return 3 * y + x;
} // posToLoc

bool TicTacToe::checkWinner() {
    if ( isOver ) return true;
    char winner{ '.' };
    for ( array<int,3> line : winLines ) {
        if ( board[ line[0] ] == board[ line[1] ]
            && board[ line[0] ] == board[ line[2] ]
        ) {
            winner = board[ line[0] ];
        } // if
    } //for

    curPlayer = ( winner == '.' ) ? curPlayer : winner;
    isOver = winner != '.';
    return ( winner == '.' ) ? false : true;
} // checkWinner

//
// INTERFACE METHODS
//

void TicTacToe::doMove( int x, int y ) {
    if ( getVal( x, y ) != '.' ) throw std::runtime_error("Invalid move.");
    char player = curPlayer;
    board[ posToLoc( x, y ) ] = player;
    if ( !checkWinner() ) {
        curPlayer = player == 'X' ? 'O' : 'X';
    } // if
} // doMove

char TicTacToe::getVal( int x, int y ) const {
    return board[ posToLoc( x, y ) ];
} // getVal

bool TicTacToe::checkIsOver() const {
    return isOver;
} // checkIsOver

char TicTacToe::getCurPlayer() const {
    if ( isOver ) throw std::runtime_error("Game over.");
    return curPlayer;
} // getCurPlayer

char TicTacToe::getWinner() const {
    if ( !isOver ) throw std::runtime_error("Game not over.");
    return curPlayer;
} // getWinner

//
// IO
//

std::ostream &operator<<( std::ostream &out, const TicTacToe &game ) {
    for ( int y = 0; y < 3; ++y ) {
        for ( int x = 0; x < 3; ++x ) {
            out << game.getVal( x,y );
        } // for
        out << std::endl;
    } // for
    return out;
} // operator<<
