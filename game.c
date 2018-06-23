#include "border.h"
#include "types.h"
#include "game.h"


int is_car_collide_with_border(Point car_position, Border border, Screen screen)
{
    int mid_x = screen.ord_x / 2;
    int min_y = 0, max_y = screen.ord_y;
    int r = border.radius;

    if (car_position.x <= mid_x - r) {
        return 1;
    }
    
    if (car_position.x + CAR_WIDTH >= mid_x + r) {
        return 1;
    }

    if (car_position.y <= 0) {
        return 1;
    }
    
    if (car_position.y + CAR_HEIGHT >= screen.ord_y) {
        return 1;
    }
    return 0;
}
