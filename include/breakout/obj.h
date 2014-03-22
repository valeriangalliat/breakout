#ifndef BREAKOUT_OBJ_H
#define BREAKOUT_OBJ_H

#include <breakout/mov.h>
#include <breakout/rect.h>

typedef struct
{
    RECT rect;
    VEL vel;
    char ch;
} BALL;

typedef struct
{
    RECT rect;
    char ch;
    int speed;
} BAT;

typedef struct
{
    int lives;
    int score;
} BTYPE;

typedef struct
{
    RECT rect;
    BTYPE *btype;
    int lives;
} BRICK;

#endif
