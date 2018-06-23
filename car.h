#ifndef CAR_H
#define CAR_H


#define CAR_WIDTH 3
#define CAR_HEIGHT 4

typedef enum {
    MoveLeft,
    MoveRight, 
    MoveUp, 
    MoveDown
} Move;

Point get_next_car_position(Point current_position, Move move);

void clear_car_at_position(Point car_position);
void draw_car_at_point(Point new_car_position);

#endif