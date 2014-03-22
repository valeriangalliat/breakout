#include <breakout/rect.h>

static inline void rect_calc_height(RECT *rect)
{
    rect->height = (rect->bottom - rect->top) + 1;
}

static inline void rect_calc_width(RECT *rect)
{
    rect->width = (rect->right - rect->left) + 1;
}

static inline void rect_calc_bottom(RECT *rect)
{
    rect->bottom = (rect->top + rect->height) - 1;
}

static inline void rect_calc_right(RECT *rect)
{
    rect->right = (rect->left + rect->width) - 1;
}

void rect_set_top(RECT *rect, int top)
{
    rect->top = top;
    rect_calc_height(rect);
}

void rect_set_left(RECT *rect, int left)
{
    rect->left = left;
    rect_calc_width(rect);
}

void rect_set_bottom(RECT *rect, int bottom)
{
    rect->bottom = bottom;
    rect_calc_height(rect);
}

void rect_set_right(RECT *rect, int right)
{
    rect->right = right;
    rect_calc_width(rect);
}

void rect_set_height(RECT *rect, int height)
{
    rect->height = height;
    rect_calc_bottom(rect);
}

void rect_set_width(RECT *rect, int width)
{
    rect->width = width;
    rect_calc_right(rect);
}

void rect_mov_y(RECT *rect, int y)
{
    rect->top += y;
    rect->bottom += y;
}

void rect_mov_x(RECT *rect, int x)
{
    rect->left += x;
    rect->right += x;
}

void rect_init(RECT *rect, int top, int left, int height, int width)
{
    rect->top = top;
    rect->left = left;

    rect_set_height(rect, height);
    rect_set_width(rect, width);
}
