#include "border.h"
#include "types.h"
#include "game.h"

#define CAR_WIDTH 3
#define CAR_HEIGHT 4

int is_car_collide_with_border(Point car_position, Border border)
{
    if (car_position.x <= border.min_x) {
        return 1;
    }
    
    if (car_position.x + CAR_WIDTH >= border.max_x) {
        return 1;
    }

    if (car_position.y <= border.min_y) {
        return 1;
    }
    
    if (car_position.y + CAR_HEIGHT >= border.max_y) {
        return 1;
    }
    return 0;
}