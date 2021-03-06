#include "types.h"
#include "car.h"
#include <curses.h>

Point get_next_car_position(Point current_position, Move move) 
{
    Point p;

    switch(move) {
        case MoveLeft: {
            p.x = current_position.x - 1;
            p.y = current_position.y;
            break;
        }
        case MoveRight: {
            p.x = current_position.x + 1;
            p.y = current_position.y;
            break;
        }
        case MoveUp: {
            p.x = current_position.x;
            p.y = current_position.y - 1;
            break;
        }
        case MoveDown: {
            p.x = current_position.x;
            p.y = current_position.y + 1;
            break;
        }
    }
    return p;
}

void clear_car_at_position(Point car_position) 
{
    int i;
    for (i = 0; i <= 3; ++i) {
        move(car_position.y + i, car_position.x);
        addstr("   ");
    }
}

void draw_car_at_point(Point new_car_position) 
{
    move(new_car_position.y, new_car_position.x);
    addstr(" ^ ");
    move(new_car_position.y+1, new_car_position.x);
    addstr("|+|");
    move(new_car_position.y+2, new_car_position.x);
    addstr(" | ");
    move(new_car_position.y+3, new_car_position.x);
    addstr("|-|");
}