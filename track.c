#include <curses.h>
#include <unistd.h>
#include <time.h>
#include "track.h"


void draw_frieze(int x, int y, int part_distance);

void draw_track(Track track, Screen screen, double distance) 
{
    int y;
    int left_border = screen.ord_x / 2 - track.width / 2;
    int right_border= screen.ord_x / 2 + track.width / 2;
    int min_y = 0, max_y = screen.ord_y; 
    
    for (y = min_y; y < max_y; ++y) {
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
