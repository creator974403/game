#include <curses.h>
#include <unistd.h>
#include <time.h>
#include "track.h"


void draw_track(Track track, Screen screen, int *fence) 
{
    int y;
    int temp;
    int left_border = (screen.ord_x - track.width) / 2;
    int right_border = (screen.ord_x  + track.width) / 2;
    int min_y = 0, max_y = screen.ord_y; 
    
    for (y = min_y; y < max_y; ++y) {
        move(y, left_border);
        addch(fence[y]);
        move(y, right_border);
        addch(fence[y]);
    }
    
}

void draw_finish(Track track, Screen screen)
{
    int x, y;
    int left_border = (screen.ord_x - track.width) / 2;
    int right_border = (screen.ord_x + track.width) / 2;
    int min_y = 5, max_y = 10;
    
    for (y = min_y; y <= max_y; y++) {
        for (x = left_border; x <= right_border; ++x) {
            move(y, x);
            addch('*');
        }
    }
}

void draw_edges_of_track(int *fence, int ord_y)
{
    int y = ord_y - 1;
    int temp;

    temp = fence[y];
    for (; y >= 0; --y) {
        fence[y + 1] = fence[y];
    }
    fence[0] = temp;
}