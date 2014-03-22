Breakout
========

Breakout game in C with ncurses.

Dependencies
------------

- `ncurses`

Controls
--------

Use left and right arrow keys to move the bat, and add shift
to move faster.

Bricks
------

There is 4 types of bricks:

1. 1 life, 2 points,
1. 2 lives, 4 points,
1. 3 lives, 8 points,
1. 4 lives, 16 points.

The character with which the brick is drawn represents its life:

1. `=`, 1 life,
1. `$`, 2 lives,
1. `&`, 3 lives,
1. `|`, 4 lives.

Each time a brick is hit by the ball, it loses a life.
Whene there is no more lives left, the brick disappears and its
score value is added to the game score.
