#include <ncurses.h>
#include <stdbool.h>

#include <breakout.h>

static inline bool check_screen()
{
    return LINES >= 20 && COLS >= 80;
}

static inline void init()
{
    // Don't show cursor
    curs_set(0);

    // Read arrow keys
    keypad(stdscr, true);

    // Read chars directly but allow interrupts
    cbreak();

    // Don't echo typed characters
    noecho();

    // Don't wait for characters, error if nothing typed
    nodelay(stdscr, true);
}

#define NCHLIVES 4
#define NBTYPES 4
#define NBRICKS 16

static inline void boot()
{
    RECT rect;
    CLOCK clock;

    RECT ball_rect;
    VEL ball_vel;
    BALL ball;

    ball.rect = ball_rect;
    ball.vel = ball_vel;

    RECT bat_rect;
    BAT bat;

    bat.rect = bat_rect;

    char chlives[4];

    chlives[0] = '=';
    chlives[1] = '$';
    chlives[2] = '&';
    chlives[3] = '|';

    BTYPE btypes[NBTYPES];

    btypes[0].lives = 1;
    btypes[0].score = 2;

    btypes[1].lives = 2;
    btypes[1].score = 4;

    btypes[2].lives = 3;
    btypes[2].score = 8;

    btypes[3].lives = 4;
    btypes[3].score = 16;

    BRICK bricks[NBRICKS];

    int konami_keys[10];

    konami_keys[0] = KEY_UP;
    konami_keys[1] = KEY_UP;
    konami_keys[2] = KEY_DOWN;
    konami_keys[3] = KEY_DOWN;
    konami_keys[4] = KEY_LEFT;
    konami_keys[5] = KEY_RIGHT;
    konami_keys[6] = KEY_LEFT;
    konami_keys[7] = KEY_RIGHT;
    konami_keys[8] = 'B';
    konami_keys[9] = 'A';

    KONAMI konami;

    konami.nkeys = 10;
    konami.keys = konami_keys;

    GAME game;

    game.win = stdscr;
    game.rect = rect;
    game.clock = clock;
    game.ball = &ball;
    game.bat = &bat;

    game.nchlives = NCHLIVES;
    game.chlives = chlives;

    game.nbtypes = NBTYPES;
    game.btypes = btypes;

    game.nbricks = NBRICKS;
    game.rbricks = NBRICKS;
    game.bricks = bricks;

    game.title = "Ncurses C Breakout";

#ifdef DEBUG
    game.debug = true;
#else
    game.debug = false;
#endif

    game.konami = &konami;

    game_setup(&game);
    game_run(&game);
}

#undef NBRICKS
#undef NBTYPES
#undef NCHLIVES

int main(int argc, char *argv[])
{
    int err = 0;

    initscr();

    if (!check_screen()) {
        fprintf(stderr, "Your terminal is not big enough.\n");
        err = 1;
    } else {
        init();
        boot();
    }

    endwin();

    return err;
}
