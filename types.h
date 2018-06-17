#ifndef TYPES_H_CENTR
#define TYPES_H_CENTR

typedef struct {
    int x; 
    int y;
} Point;

typedef enum {
    MoveLeft,
    MoveRight, 
    MoveUp, 
    MoveDown
} Move;

typedef struct {
    int min_x, max_x;
    int min_y, max_y;
} Border;

typedef enum {
    ActionNothing,
    ActionQuit,
    ActionMoveLeft,
    ActionMoveRight,
    ActionMoveUp,
    ActionMoveDown,
}   Action;

#endif