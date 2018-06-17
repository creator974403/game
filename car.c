#include "types.h"
#include "car.h" 
#include <curses.h>

Point get_next_car_position(Point current_position, Move move, Border borders) {
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
  
  /*if (p.x + CAR_WIDTH > border.max_x) { p.x = ...; }
  if (p.x - CAR_WIDTH < border.min_x) { p.x = ...; }
  // ...*/
  
  return p;
}

void draw_car_at_point(Point current_car_position, Point new_car_position) {
    move(current_car_position.y, current_car_position.x);
    addch(' ');
    move(new_car_position.y, new_car_position.x);
    addch('*');
}