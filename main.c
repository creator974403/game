#include <curses.h>
#include <unistd.h>
#include <time.h>
#include "types.h"
#include "screen.h"
#include "track.h"
#include "car.h"
#include "game.h"


#define WAIT_TIME 100
#define KEY_ESCAPE 27

typedef enum {
    ActionNothing,
    ActionQuit,
    ActionMoveLeft,
    ActionMoveRight,
    ActionMoveUp,
    ActionMoveDown,
} Action;


Action next_action();
void init_screen();
void handle_move_action(Action action, Point old_position, Point *car_position);


int main() 
{
    Point car_position;
    Track track;
    int ord_x, ord_y;
    Action action;
    Screen screen;
    int distance = 0;

    init_screen();

    getmaxyx(stdscr, ord_y, ord_x);
    screen.ord_x = ord_x;
    screen.ord_y = ord_y;

    track.length = 1000;
    track.width  = 40;
    time_t before = time(NULL);
    draw_track(track, screen, distance);

    car_position.x = ord_x/2-2;
    car_position.y = ord_y/2;

    draw_car_at_point(car_position);
    refresh();

    while( (action = next_action()) != ActionQuit) {
        time_t after = time(NULL);
        int dt = (int)difftime(after, before);
        Point old_position = car_position;
        handle_move_action(action, old_position, &car_position);
        if (is_car_collide_with_track(car_position, track, screen)) {
            endwin();
            printf("GAVE OVER\n");
            break;
        }

        distance += SPEED * dt;
        if (distance >= track.length - 20) {
            draw_finish(track, screen);
        }

        if (distance >= track.length) {
            endwin();
            printf("YOU WIN\n");
            break;
        }

        draw_track(track, screen);
        refresh();
    }
    return 0;
}

Action next_action()
{
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

void init_screen()
{
    initscr(); 
    curs_set(0); 
    cbreak(); /* введеный символ доступен сразу же после ввода */
    keypad(stdscr, 1); /* обработка escape поседовательности */ 
    noecho(); 
    timeout(WAITE_TIME);
}

void handle_move_action(Action action, Point old_position, Point *car_position)
{
    switch (action) {
        case ActionMoveUp: {
            *car_position = get_next_car_position(*car_position, MoveUp);
            break;
        }
        case ActionMoveDown: {
            *car_position = get_next_car_position(*car_position, MoveDown);
            break;
        }
        case ActionMoveLeft: {
            *car_position = get_next_car_position(*car_position, MoveLeft);
            break;
        }
        case ActionMoveRight: {
            *car_position = get_next_car_position(*car_position, MoveRight);
            break;
        }

        default:
            break;
    }
    clear_car_at_position(old_position);
    draw_car_at_point(*car_position);
}
