#include "border.h"
#include "types.h"
#include "car.h"
#include <curses.h>

Point get_next_car_position(Point current_position, Move move, Border border) {
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
  
    if (p.x > border.max_x) { 
        p.x = border.max_x; 
    }
    if (p.x <= border.min_x) { 
        p.x = border.min_x; 
    }
    if (p.y > border.max_y) { 
        p.y = border.max_y; 
    }
    if (p.y <= border.min_y) { 
        p.y = border.min_y; 
    }
  return p;
}

void draw_car_at_point(Point current_car_position, Point new_car_position) {
    move(current_car_position.y, current_car_position.x);
    addch(' ');
    move(new_car_position.y, new_car_position.x);
    addch('*');
}