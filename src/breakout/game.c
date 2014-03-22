#include <ncurses.h>
#include <stdbool.h>
#include <time.h>

#include <breakout.h>

#include "game/over.h"
#include "game/play.h"
#include "game/won.h"

static inline void game_frame(GAME *game)
{
    if (game->over) {
        game_over_frame(game);
    } else if (game->won) {
        game_won_frame(game);
    } else {
        game_play_frame(game);
    }
}

static inline void game_setup_bricks(GAME *game)
{
    int cols = 8;
    int height = 2;
    int width = 8;
    int pad = 2;

    int game_half_width = game->rect.width / 2;
    int row_half_width = (((width + pad) * cols) - pad) / 2;
    int left = game->rect.left + (game_half_width - row_half_width);

    int y = game->rect.top + 2;
    int x = left;

    int btype = 0;

    int i = game->nbricks;

    while (--i >= 0) {
        rect_init(&game->bricks[i].rect, y, x, height, width);
        game->bricks[i].btype = &game->btypes[btype];
        game->bricks[i].lives = game->btypes[btype].lives;

        x += width + pad;

        if (!(i % cols)) {
            x = left;
            y += height + pad;
        }

        if (++btype == game->nbtypes) {
            btype = 0;
        }
    }
}

void game_setup(GAME *game)
{
    rect_init(&game->rect, 1, 1, LINES - 2, COLS - 2);

    game->clock.s = 0;
    game->clock.ms = 0;

    rect_init(&game->ball->rect, (LINES / 2) - 1, (COLS / 2) - 1, 1, 1);

    game->ball->vel.y = 1;
    game->ball->vel.x = 0;
    game->ball->ch = '*';

    rect_init(&game->bat->rect, LINES - 3, (COLS / 2) - 8, 1, 16);

    game->bat->ch = '#';
    game->bat->speed = 2;

    game->end = false;
    game->over = false;
    game->won = false;
    game->score = 0;

    game_setup_bricks(game);

    game->konami->ok = 0;
}

void game_run(GAME *game)
{
    struct timespec timein;

    timein.tv_sec = 0;
    timein.tv_nsec = 1000000;

    game_frame(game);

    while (!game->end) {
        nanosleep(&timein, NULL);
        game->clock.ms += 1;

        if (1000 == game->clock.ms) {
            game->clock.s++;
            game->clock.ms = 0;
        }

        game_frame(game);
    }
}

static inline void game_repaint_title(GAME *game)
{
    mvwaddch(game->win, 0, 2, ' ');
    waddstr(game->win, game->title);
    waddch(game->win, ' ');
}

static inline void game_repaint_box(GAME *game)
{
    box(game->win, 0, 0);
}

void game_repaint(GAME *game)
{
    werase(game->win);
    game_repaint_box(game);
    game_repaint_title(game);
}

void game_refresh(GAME *game)
{
    wrefresh(game->win);
}
