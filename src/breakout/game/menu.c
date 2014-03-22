#include <ncurses.h>
#include <stdbool.h>
#include <string.h>

#include "menu.h"

static inline void input(GAME *game)
{
    int ch = getch();

    switch (ch) {
    case 10:
        // Enter
        game_setup(game);
        break;

    case 27:
        // Escape
        game->end = true;
        break;
    }
}

static inline void draw(GAME *game, const char *title)
{
    game_repaint(game);

    int middley = game->rect.top + (game->rect.height / 2);
    int middlex = game->rect.left + (game->rect.width / 2);

    mvwaddstr(game->win, middley - 2, middlex - (strlen(title) / 2), title);
    mvwaddstr(game->win, middley, middlex - (14 / 2), "[Enter]: Retry");
    mvwaddstr(game->win, middley + 1, middlex - (14 / 2), "[Escape]: Quit");

    game_refresh(game);
}

void game_menu_frame(GAME *game, const char *title)
{
    input(game);
    draw(game, title);
}
