#ifndef __TIC_TAC_TOE_H__
#define __TIC_TAC_TOE_H__

#include <iostream>
#include <array>

using std::array;

class TicTacToe {
    array<char, 9> board; // Array of size 9, containing chars in ".X0"
    bool isOver;
    char curPlayer;       // Either 'X' or 'O'. If isOver, contains the winner.

    static array< array<int,3>, 8 > winLines;

    static int posToLoc( int x, int y ); // Determines the index of position (x,y) in board.
    bool checkWinner();                  // Updates necessary fields and returns whether a winner is found or not.

  public:
    TicTacToe();

    void doMove( int x, int y ); // If the move is invalid, throws std::runtime_error("Invalid move.").
    char getVal( int x, int y ) const;
    bool checkIsOver() const;
    char getCurPlayer() const;   // If the game is over, throws std::runtime_error("Game over.").
    char getWinner() const;      // If the game is not over, throws std::runtime_error("Game not over.").

};

std::ostream &operator<<( std::ostream &out, const TicTacToe &game );

#endif
