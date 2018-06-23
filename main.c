#include <curses.h>
#include <unistd.h>
#include "types.h"
#include "screen.h"
#include "border.h"
#include "car.h"
#include "game.h"


#define DELAY_DURATION 5
#define KEY_ESCAPE 27


typedef enum {
    ActionNothing,
    ActionQuit,
    ActionMoveLeft,
    ActionMoveRight,
    ActionMoveUp,
    ActionMoveDown,
}   Action;


Action next_action();


int main() {
    Point car_position;
    Border border;
    int ord_x, ord_y;
    Action action;
    Screen screen;

    initscr(); 
    curs_set(0); 
    cbreak(); /* введеный символ доступен сразу же после ввода */
    keypad(stdscr, 1); /* обработка escape поседовательности */ 
    noecho(); 

    getmaxyx(stdscr, ord_y, ord_x);
    screen.ord_x = ord_x;
    screen.ord_y = ord_y;

    border.radius = 20;
    draw_border(border, screen);

    car_position.x = ord_x/2-2;
    car_position.y = ord_y/2;

    draw_car_at_point(car_position);
    refresh();

    while( (action = next_action()) != ActionQuit) {
        Point old_position = car_position;
        switch(action) {
            case ActionMoveUp: {
                car_position = get_next_car_position(car_position, MoveUp);
                clear_car_at_position(old_position);
                draw_car_at_point(car_position);
                break;
            }
            case ActionMoveDown: {
                car_position = get_next_car_position(car_position, MoveDown);
                clear_car_at_position(old_position);
                draw_car_at_point(car_position);                
                break;
            }
            case ActionMoveLeft: {
                car_position = get_next_car_position(car_position, MoveLeft);
                clear_car_at_position(old_position);
                draw_car_at_point(car_position);
                break;
            }
            case ActionMoveRight: {
                car_position = get_next_car_position(car_position, MoveRight);
                clear_car_at_position(old_position);
                draw_car_at_point(car_position);
                break;
            }
            default:
                break;
        }
        if (is_car_collide_with_border(car_position, border, screen)) {
            goto _exit;
        }
        refresh();
    }
    _exit: ;
    endwin();
    printf("GAVE OVER\n");
    sleep(DELAY_DURATION);
    return 0;
}

Action next_action() {
    int key = getch();

    if (key == KEY_ESCAPE) {
        return ActionQuit;
    }
      
    if (key == KEY_UP) {
        return ActionMoveUp;
    }
  
    if (key == KEY_DOWN) {
        return ActionMoveDown;
    }
  
    if (key == KEY_LEFT) {
        return ActionMoveLeft;
    }
  
    if (key == KEY_RIGHT) {
        return ActionMoveRight;
    }
    return ActionNothing;
}