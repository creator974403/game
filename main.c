#include "border.h"
#include <curses.h>
#include <unistd.h>
#include "types.h"
#include "car.h"

#define DELAY_DURATION 100
#define KEY_ESCAPE 27

typedef enum {
    ActionNothing,
    ActionQuit,
    ActionMoveLeft,
    ActionMoveRight,
    ActionMoveUp,
    ActionMoveDown,
}   Action;


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

int main() {
    Point car_position;
    Border border;
    int ord_x, ord_y;
    Action action;

    initscr(); /* вызвали библиотеку*/ 
    curs_set(0); /* скрыть курсив клавиатуры */
    cbreak(); /* введеный символ доступен сразу же после ввода */
    keypad(stdscr, 1); /* обработка escape поседовательности */ 
    noecho(); 

    getmaxyx(stdscr, ord_y, ord_x);
    border.min_x = 0;
    border.max_x = ord_x;
    border.min_y = 0;
    border.max_y = ord_y;

    car_position.x = ord_x/2;
    car_position.y = ord_y/2;
    move(car_position.y, car_position.x);
    addch('*');
    refresh();

    while( (action = next_action()) != ActionQuit) {
        Point old_position = car_position;
        switch(action) {
            case ActionMoveUp: {
                car_position = get_next_car_position(car_position, MoveUp, border);
                draw_car_at_point(old_position, car_position);
                break;
            }
            case ActionMoveDown: {
                car_position = get_next_car_position(car_position, MoveDown, border);
                draw_car_at_point(old_position, car_position);
                break;
            }
            case ActionMoveLeft: {
                car_position = get_next_car_position(car_position, MoveLeft, border);
                draw_car_at_point(old_position, car_position);
                break;
            }
            case ActionMoveRight: {
                car_position = get_next_car_position(car_position, MoveRight, border);
                draw_car_at_point(old_position, car_position);
                break;
            }
            default:
                break;
        }
    /*Border old_border = border;
    border = get_next_border(border ... );
    draw_border(old_boder, border);*/
    refresh();
  }

   endwin();
   return 0;
}