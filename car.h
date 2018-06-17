#ifndef CAR_H
#define CAR_H

typedef enum {
    MoveLeft,
    MoveRight, 
    MoveUp, 
    MoveDown
} Move;

Point get_next_car_position(Point current_position, Move move, Border borders);
void draw_car_at_point(Point current_car_position, Point new_car_position);


#endif