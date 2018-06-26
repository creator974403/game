#include <curses.h>
#include <unistd.h>
#include <time.h>
#include "track.h"


void draw_frieze(int x, int y, int part_distance);

void draw_track(Track track, Screen screen, double distance) 
{
    int min_x = 0, max_x = track.width;
    int min_y = 0, max_y = screen.ord_y; 
    
    for (y = min_y; y < max_y; ++y) {
        draw_frieze(min_x, y);
        draw_frieze(max_x, y);
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
