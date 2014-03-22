#include <ctype.h>
#include <ncurses.h>

#include <breakout/konami.h>

bool konami_push(KONAMI *konami, int ch)
{
    ch = toupper(ch);

    if (konami->keys[konami->ok] != ch) {
        konami->ok = 0;
        return false;
    }

    if (++konami->ok == konami->nkeys) {
        konami->ok = 0;
        return true;
    }

    return false;
}
