#ifndef BREAKOUT_COL_H
#define BREAKOUT_COL_H

#include <stdbool.h>

#include <breakout/mov.h>
#include <breakout/rect.h>

typedef enum {
    NONE,
    TOP,
    LEFT,
    BOTTOM,
    RIGHT,
} COL;

bool col_test(const RECT *r1, const RECT *r2);
COL col_mov_test(const RECT *stat, const RECT *rect, const VEL *vel);

#endif
