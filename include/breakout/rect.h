#ifndef BREAKOUT_RECT_H
#define BREAKOUT_RECT_H

typedef struct
{
    int top;
    int left;
    int bottom;
    int right;
    int height;
    int width;
} RECT;

void rect_set_top(RECT *rect, int top);
void rect_set_left(RECT *rect, int left);
void rect_set_bottom(RECT *rect, int bottom);
void rect_set_right(RECT *rect, int right);
void rect_set_height(RECT *rect, int height);
void rect_set_width(RECT *rect, int width);

void rect_mov_y(RECT *rect, int y);
void rect_mov_x(RECT *rect, int x);

void rect_init(RECT *rect, int top, int left, int height, int width);

#endif
