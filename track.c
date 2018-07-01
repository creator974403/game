#include <curses.h>
#include <unistd.h>
#include <time.h>
#include "track.h"


void draw_track(Track track, Screen screen, double distance) 
{
    int y;
    int i = 0;
    int left_border = screen.ord_x / 2 - track.width / 2;
    int right_border = screen.ord_x / 2 + track.width / 2;
    int min_y = 0, max_y = screen.ord_y; 
    
    for (y = min_y; y < max_y; ++y) {
        (i <= 4) ? (++i) : (i = 0);
        y += i;
        draw_frieze(left_border, y);
        draw_frieze(right_border, y);
    }
}

void draw_frieze(int x, int y)
{
    move(y, x);
    if (y % 4 == 0) {
        addch('@');    
    } else {
        addch('#');
    }    
}

void draw_finish(Track track, Screen screen)
{
    int x, y;
    int left_border = screen.ord_x / 2 - track.width / 2;
    int right_border = screen.ord_x / 2 + track.width / 2;
    int min_y = 5, max_y = 10;
    
    for (y = min_y; y <= max_y; y++) {
        for (x = left_border; x <= right_border; ++x) {
            move(y, x);
            addch('*');
        }
    }
}
