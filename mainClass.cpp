#include <iostream>
using std::cout;
using std::endl;
using std::cin;

/********************************************\
 * Game class, contains all state information
 * for an entire running session in GoL.
\********************************************/
class Game 
{
    int generation;
    static const int ROWS = 5;
    static const int COLS = 10;
    bool board[5][20];
    // TODO Variable size for array (Vector?)

    public:
        Game();     // Constructor TODO Variable size as Params
        void printBoard();  // Display to STDOUT
        void tick();        // Update board to next Generation
};

                    
int main(void)
{
    Game *g = new Game();
    for (;;) {
        g->printBoard();
        g->tick();
    }
}


/*****************************************\
 * Constructor for Game class
 * currently takes no parameters.
 * Reads 200 booleans (1 or 0) from STDIN
\*****************************************/
Game::Game()
{
    /*
     *for (int i = 0; i < this->ROWS; i++) {
     *    for (int j = 0; j < this->cols; j++) {
     *        cin >> this->board[i][j];
     *    }
     *}
     */

    bool tempBoard[][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                           {0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}; 

    for (int i = 0; i < this->ROWS; ++i) {
        for (int j = 0; j < this->COLS; ++j) {
            this->board[i][j] = tempBoard[i][j];
        }
    }

}


void Game::printBoard()
{
    for (int i = 0; i < this->ROWS; ++i) {
        for (int j = 0; j < this->COLS; ++j) {
            cout << (this->board[i][j] ? "#" : " ") << " ";
        }
        cout << endl;
    }

    cout << endl << endl;
}


void Game::tick()
{
    int herber;
    cin >> herber;
    herber += 1;

    int newBoard[5][10]; // FIXME this should be dynamic
                                          // sized (vector maybe?)

    for (int i = 0; i < this->ROWS; ++i) {
        for (int j = 0; j < this->COLS; ++j) {
            newBoard[i][j] = this->board[i][j];
        }
    }

    for (int i = 0; i < this->ROWS; ++i) {
        for (int j = 0; j < this->COLS; ++j) {
            int adjCount = 0;
            for (int di = -1; di < 2; ++di) {
                for (int dj = -1; dj < 2; ++dj) {
                    int newI = i + di;
                    int newJ = j + dj;

                    if (newI > 0 and newI < this->ROWS) {
                        if (newJ > 0 and newJ < this->COLS) {
                            adjCount += this->board[newI][newJ];
                        }
                    }
                }
            }

            if (this->board[i][j]) {
                --adjCount;  // Adjcount adds with (0, 0) 
                             // which means this hack is needed
            }

            cout << adjCount;
            if (adjCount < 2 or adjCount > 3) {
                newBoard[i][j] = 0;
            }

            if (adjCount == 3) {
                newBoard[i][j] = 1;
            }
        }
        cout << endl;
    }

    for (int i = 0; i < this->ROWS; ++i) {
        for (int j = 0; j < this->COLS; ++j) {
            this->board[i][j] = newBoard[i][j];
        }
    }
}
