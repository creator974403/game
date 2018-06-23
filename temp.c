typedef struct {
    int min_x, max_x;
    int min_y, max_y;
} Border;

int collide_car_at_point(Point car_position, Border border)
{
    int is_collide = 0;
    if (car_position.x <= border.min_x) {
        is_collide = 1;
    }
    
    if (car_position.x >= border.max_x) {
        is_collide = 1;
    }

    if (car_position.y <= border.min_y) {
        is_collide = 1;
    }
    
    if (car_position.y >= border.max_y) {
        is_collide = 1;
    }
    
    return is_collide;
}

int collide_car_at_point(Point car_position, Border border)
{
    if (car_position.x <= border.min_x) {
        return 1;
    }
    
    if (car_position.x >= border.max_x) {
        return 1;
    }

    if (car_position.y <= border.min_y) {
        return 1;
    }
    
    if (car_position.y >= border.max_y) {
        return 1;
    }
    return 0;
}