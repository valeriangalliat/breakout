#include <breakout/mov.h>
#include <breakout/rect.h>

void mov_rect(RECT *rect, const VEL *vel)
{
    rect_mov_y(rect, vel->y);
    rect_mov_x(rect, vel->x);
}

void mov_next(const RECT *in, const VEL *vel, RECT *out)
{
    out->top = in->top;
    out->left = in->left;
    out->bottom = in->bottom;
    out->right = in->right;
    out->height = in->height;
    out->width = in->width;

    mov_rect(out, vel);
}
