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

inline void rect_set_top(RECT *rect, int top);
inline void rect_set_left(RECT *rect, int left);
inline void rect_set_bottom(RECT *rect, int bottom);
inline void rect_set_right(RECT *rect, int right);
inline void rect_set_height(RECT *rect, int height);
inline void rect_set_width(RECT *rect, int width);

inline void rect_mov_y(RECT *rect, int y);
inline void rect_mov_x(RECT *rect, int x);

inline void rect_init(RECT *rect, int top, int left, int height, int width);

#endif
