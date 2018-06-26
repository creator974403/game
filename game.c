#include "track.h"
#include "types.h"
#include "game.h"
#include "car.h"

int is_car_collide_with_track(Point car_position, Track track, Screen screen)
{
    int min_x = 0, max_x = track.width
    int min_y = 0, max_y = screen.ord_y;

    if (car_position.x <= min_x) {
        return 1;
    }
    
    if (car_position.x + CAR_WIDTH >= man_x) {
        return 1;
    }

    if (car_position.y <= min_y) {
        return 1;
    }
    
    if (car_position.y + CAR_HEIGHT >= max_y) {
        return 1;
    }
    return 0;
}
