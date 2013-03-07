#include <iostream>
#include <time.h>
#include <ncurses.h>
#include <stdlib.h>

using std::cout;
using std::endl;
using std::cin;

/********************************************\
 * GoL class, contains all state information
 * for an entire running session in GoL.
\********************************************/
// TODO make this a header file
class GoL 
{
    static const int ROWS = 20;
    static const int COLS = 27;
    bool board[20][27];
    // TODO Variable size for array (Vector?)

    public:
        GoL();     // Constructor TODO Variable size as Params
        void printBoard();  // Display to STDOUT
        void tick();        // Update board to next Generation
        int generation;
        void printBoardNoCurse();
};

                    
int main(void)
{
    initscr();
    GoL *g = new GoL();

    for (;;) {
        g->printBoard();
        g->tick();
    }
}


/*****************************************\
 * Constructor for GoL class
 * currently takes no parameters.
 * 
 * Reads a (currently fixed) number of
 * cells from STDIN, sets them as the
 * current board.
\*****************************************/
GoL::GoL()
{
    this->generation = 1;
    for (int i = 0; i < this->ROWS; ++i) {
        for (int j = 0; j < this->COLS; ++j) {
            cin >> this->board[i][j];
        }
    }
}


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


/*******************************************
 * Gol Tick Function
 *
 * Performs the basic logic and calculation
 * for a GoL session. When run, updates
 * the games board to the next generation.
 *******************************************/
void GoL::tick()
{
    usleep(1 * 100000);
    this->generation++;
    bool newBoard[20][27]; // FIXME this should be dynamicly
                                          // sized (vector maybe?)

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

                    // Toidial Cycling (Buzzword Synergy)
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

    for (int i = 0; i < this->ROWS; ++i) {
        for (int j = 0; j < this->COLS; ++j) {
            this->board[i][j] = newBoard[i][j];
        }
    }
}

