#ifndef CAR_H_CENTR
#define CAR_H_CENTR

Point get_next_car_position(Point current_position, Move move, Border borders);
void draw_car_at_point(Point current_car_position, Point new_car_position);

#endif