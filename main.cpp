#include "GoL.h"

/*------------------------------------------*
 | GoL class, contains all state information
 | for an entire running session in GoL.
 *------------------------------------------*/
int main(void)
{
    GoL::GoL *g = new GoL::GoL();

    for (;;) {
        g->printBoard();
        g->tick();
    }
}

