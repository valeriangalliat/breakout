#ifndef BREAKOUT_GAME_H
#define BREAKOUT_GAME_H

#include <ncurses.h>
#include <stdbool.h>

#include <breakout/clock.h>
#include <breakout/konami.h>
#include <breakout/obj.h>
#include <breakout/rect.h>

typedef struct
{
    WINDOW *win;
    RECT rect;

    CLOCK clock;

    BALL *ball;
    BAT *bat;

    int nchlives;
    char *chlives; // Live characters

    int nbtypes;
    BTYPE *btypes; // Brick types

    int nbricks;
    int rbricks; // Remaining bricks
    BRICK *bricks;

    char *title;

    bool debug;
    bool end;
    bool won;
    bool over;
    int score;

    KONAMI *konami;
} GAME;

void game_setup(GAME *game);
void game_run(GAME *game);
void game_repaint(GAME *game);
void game_refresh(GAME *game);

#endif
