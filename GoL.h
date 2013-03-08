#ifndef GOL_H
#define GOL_H
class GoL 
{
    static const int ROWS = 20;
    static const int COLS = 40;
    bool board[20][40];
    // TODO Variable size for array (Vector?)

    public:
        GoL();     // Constructor TODO Variable size as Params
        void printBoard();  // Display to STDOUT
        void tick();        // Update board to next Generation
        int generation;
        void printBoardNoCurse();
};
#endif
