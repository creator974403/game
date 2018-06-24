typedef struct {
    int min_x, max_x;
    int min_y, max_y;
} Track;

int collide_car_at_point(Point car_position, Track track)
{
    int is_collide = 0;
    if (car_position.x <= track.min_x) {
        is_collide = 1;
    }
    
    if (car_position.x >= track.max_x) {
        is_collide = 1;
    }

    if (car_position.y <= track.min_y) {
        is_collide = 1;
    }
    
    if (car_position.y >= track.max_y) {
        is_collide = 1;
    }
    
    return is_collide;
}

int collide_car_at_point(Point car_position, Track track)
{
    if (car_position.x <= track.min_x) {
        return 1;
    }
    
    if (car_position.x >= track.max_x) {
        return 1;
    }

    if (car_position.y <= track.min_y) {
        return 1;
    }
    
    if (car_position.y >= track.max_y) {
        return 1;
    }
    return 0;
}