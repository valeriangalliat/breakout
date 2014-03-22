#include <breakout/col.h>

bool col_test(const RECT *r1, const RECT *r2)
{
    if (r1->top > r2->bottom) {
        return false;
    }

    if (r1->left > r2->right) {
        return false;
    }

    if (r2->bottom < r2->top) {
        return false;
    }

    if (r1->right < r2->left) {
        return false;
    }

    return true;
}

static inline bool col_mov_test_dir(int s, int p, int vel)
{
    if (vel <= 0) {
        return false;
    }

    if (p >= s) {
        return false;
    }

    return (p + vel) >= s;
}

static inline bool col_mov_test_top(const RECT *stat, const RECT *rect, const VEL *vel)
{
    return col_mov_test_dir(stat->top, rect->bottom, vel->y);
}

static inline bool col_mov_test_left(const RECT *stat, const RECT *rect, const VEL *vel)
{
    return col_mov_test_dir(stat->left, rect->right, vel->x);
}

static inline bool col_mov_test_bottom(const RECT *stat, const RECT *rect, const VEL *vel)
{
    return col_mov_test_dir(-stat->top, -rect->bottom, -vel->y);
}

static inline bool col_mov_test_right(const RECT *stat, const RECT *rect, const VEL *vel)
{
    return col_mov_test_dir(-stat->left, -rect->right, -vel->x);
}

static inline bool col_mov_test_axis(int s1, int s2, int p1, int p2, int vel)
{
    int n1 = p1 + vel;
    int n2 = p2 + vel;

    return n2 >= s1 && n1 <= s2;
}

static inline bool col_move_test_y(const RECT *stat, const RECT *rect, const VEL *vel)
{
    return col_mov_test_axis(stat->top, stat->bottom, rect->top, rect->bottom, vel->y);
}

static inline bool col_move_test_x(const RECT *stat, const RECT *rect, const VEL *vel)
{
    return col_mov_test_axis(stat->left, stat->right, rect->left, rect->right, vel->x);
}

COL col_mov_test(const RECT *stat, const RECT *rect, const VEL *vel)
{
    bool y = col_move_test_y(stat, rect, vel);
    bool x = col_move_test_x(stat, rect, vel);

    if (x && col_mov_test_top(stat, rect, vel)) {
        return TOP;
    }

    if (y && col_mov_test_left(stat, rect, vel)) {
        return LEFT;
    }

    if (x && col_mov_test_bottom(stat, rect, vel)) {
        return BOTTOM;
    }

    if (y && col_mov_test_right(stat, rect, vel)) {
        return RIGHT;
    }

    return NONE;
}
