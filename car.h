#ifndef CAR_H
#define CAR_H


typedef enum {
    MoveLeft,
    MoveRight, 
    MoveUp, 
    MoveDown
} Move;

void clear_car_at_position(Point car_position)
Point get_next_car_position(Point current_position, Move move, Border borders);
void draw_car_at_point(Point new_car_position);


#endif