#ifndef BREAKOUT_MOV_H
#define BREAKOUT_MOV_H

#include <breakout/rect.h>

typedef struct
{
    int y;
    int x;
} VEL;

void mov_rect(RECT *rect, const VEL *vel);
void mov_next(const RECT *in, const VEL *vel, RECT *out);

#endif
