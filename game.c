#include "track.h"
#include "types.h"
#include "game.h"
#include "car.h"

int is_car_collide_with_track(Point car_position, Track track, Screen screen)
{
    int left_border = screen.ord_x / 2 - track.width / 2;
    int right_border= screen.ord_x / 2 + track.width / 2;
    int min_y = 0, max_y = screen.ord_y;

    if (car_position.x <= left_border) {
        return 1;
    }
    
    if (car_position.x + CAR_WIDTH >= right_border) {
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
