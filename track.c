#include <curses.h>
#include <unistd.h>
#include <time.h>
#include "track.h"

#define SPEED 40


void draw_frieze(int x, int y, int part_distance);

void draw_track(int length_track, Track track, Screen screen) 
{
    int y;
    int mid_x = screen.ord_x / 2;
    int min_y = 0, max_y = screen.ord_y;
    int r = track.radius; 
    
    int passed_the_time = (int)(clock() / CLOCK_PER_SEC);
    int distance = SPEED * passed_the_time;
    int part_distance = length_track / distance;

    for (y = min_y; y < max_y; ++y) {
        draw_frieze(mid_x - r, y, part_distance);
        draw_frieze(mid_x + r, y, part_distance);
    }
}

void draw_frieze(int x, int y, int part_distance)
{
    move(y, x);
        if (y % part_distance == 0) {
            addch('@');    
        } else {
            addch('#');
        }    
}
