#include <curses.h>
#include <unistd.h>
#include "border.h"


void draw_border(Border border, Screen screen) 
{
    int y;
    int mid_x = screen.ord_x / 2;
    int min_y = 0, max_y = screen.ord_y;
    int r = border.radius; 

    for (y = min_y; y < max_y; ++y) {
        move(y, mid_x - r);
        if (y % 4 == 0) {
            addch('@');    
        } else {
            addch('#');
        }

        move(y, mid_x + r);
        if (y % 4 == 0) {
            addch('@');    
        } else {
            addch('#');
        }
    }
}
