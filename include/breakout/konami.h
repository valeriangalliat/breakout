#ifndef BREAKOUT_KONAMI_H
#define BREAKOUT_KONAMI_H

#include <stdbool.h>

typedef struct
{
    int nkeys;
    int *keys;
    int ok;
} KONAMI;

bool konami_push(KONAMI *konami, int ch);

#endif
