#include "GoL.h"
#include <iostream>
#include <time.h>
#include <ncurses.h>

using std::cout;
using std::endl;
using std::cin;



/*----------------------------------------*
 | Constructor for GoL class
 | ------------------------- 
 | Reads a (currently fixed) number of
 | cells from STDIN, sets them as the
 | current board.
 *----------------------------------------*/
GoL::GoL()
{
    initscr();
    this->generation = 1;
    for (int i = 0; i < this->ROWS; ++i) {
        for (int j = 0; j < this->COLS; ++j) {
            cin >> this->board[i][j];
        }
    }
}

/*------------------------------------------*
 | PrintBoard 
 | -----------
 | Prints board to STDOUT using the ncurses
 | library. Treats 1 as alive and 0 as dead.
 *------------------------------------------*/
void GoL::printBoard()
{
    clear();
    for (int i = 0; i < this->ROWS; ++i) {
        for (int j = 0; j < this->COLS; ++j) {
            printw(this->board[i][j] ? "# " : ". ");
        }
        printw("\n");
    }
    refresh();
}


/*------------------------------------------*
 | Gol Tick 
 | --------
 | Performs the basic logic and calculation
 | for a GoL session. When run, updates
 | the games board to the next generation.
 *-----------------------------------------*/
void GoL::tick()
{
    usleep(1 * 100000);
    this->generation++;
    bool newBoard[20][40]; // FIXME this should be dynamicly
                           // sized (vector maybe?)
    

    // Create new zero'd array for temperary board manipulation.
    for (int i = 0; i < this->ROWS; ++i) {
        for (int j = 0; j < this->COLS; ++j) {
            newBoard[i][j] = 0;
        }
    }


    for (int i = 0; i < this->ROWS; ++i) {
        for (int j = 0; j < this->COLS; ++j) {
            int adjCount = 0;

            // Cycles through deltas for adjecent cell calculation
            for (int di = -1; di < 2; ++di) {
                for (int dj = -1; dj < 2; ++dj) {
                    int newI = i + di;
                    int newJ = j + dj;

                    // Toidial Cycling 
                    if (newI >= this->ROWS) {
                        newI -= this->ROWS;
                    }
                     
                    if (newI < 0) {
                        newI += this->ROWS;
                    } 

                    if (newJ >= this->COLS) {
                        newJ -= this->COLS;
                    }

                    if (newJ < 0) {
                        newJ += this->COLS;
                    }

                    adjCount += this->board[newI][newJ];
                }
            }

            // This is where the magic happens
            if (adjCount == 4 and this->board[i][j]) {
                newBoard[i][j] = 1;
            }

            if (adjCount == 3) {
                newBoard[i][j] = 1;
            }
        }
    }

    // Finally, copy the temperary array into the main array.
    for (int i = 0; i < this->ROWS; ++i) {
        for (int j = 0; j < this->COLS; ++j) {
            this->board[i][j] = newBoard[i][j];
        }
    }
}



