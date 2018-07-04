#include <curses.h>
#include <unistd.h>
#include <time.h>
#include "types.h"
#include "screen.h"
#include "track.h"
#include "car.h"
#include "game.h"


#define GETCHAR_TIMEOUT_MILLSEC 100
#define KEY_ESCAPE 27
#define FINISHLINE_DRAWING_OFFSET 20

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
    int i;
    init_screen();

    getmaxyx(stdscr, ord_y, ord_x);
    screen.ord_x = ord_x;
    screen.ord_y = ord_y;

    track.length = 1000;
    track.width  = 40;
    track.fence_count = 3;
    track.fences = fences;
    
    time_t before = time(NULL);
    
    TrackFence f1;
    f1.side = TrackFenceSideLeft;
    f1.y_offset = 4;
    f1.legnth = 6;
    f1.width = 1;

    TrackFence f2;
    f2.side = TrackFenceSideRight;
    f2.y_offset = 7;
    f2.legnth = 6;
    f2.width = 1;

    TrackFence f3;
    f3.side = TrackFenceSideLeft;
    f3.y_offset = 16;
    f3.legnth = 3;
    f3.width = 1;

    TrackFence fences[3];
    fences[0] = f1;
    fences[1] = f2;
    fences[2] = f3;

    int fence[ord_y];
    for (i = 0; i < ord_y; ++i) {
        if (i % 4 == 0) {
            fence[i] = '@';
        } else {
            fence[i] = '#';
        }
    }

    draw_track(track, screen, fence);

    car_position.x = ord_x/2-2;
    car_position.y = ord_y/2;

    draw_car_at_point(car_position);
    refresh();

    while( (action = next_action()) != ActionQuit) {
        time_t after = time(NULL);
        int dt = (int)difftime(after, before);
        Point old_position = car_position;
        handle_move_action(action, old_position, &car_position);
        if (is_car_collide_with_wall(car_position, track, screen)) {
            endwin();
            printf("GAVE OVER\n");
            break;
        }

        distance += SPEED * dt;
        if (distance >= track.length - FINISHLINE_DRAWING_OFFSET) {
            draw_finish(track, screen);
        }

        if (distance >= track.length) {
            endwin();
            printf("YOU WIN\n");
            break;
        }

        draw_track(track, screen, fence);
        draw_edges_of_track(&fence, ord_y);

        draw_track_at_screen_offset(track, screen, fences[0].y_offset);
        draw_track_at_screen_offset(track, screen, fences[1].y_offset);
        draw_track_at_screen_offset(track, screen, fences[2].y_offset);
        
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
    timeout(GETCHAR_TIMEOUT_MILLSEC);
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
