#include "border.h"
#include <curses.h>
#include <unistd.h>
#include "types.h"
#include "car.h"


void draw_inital_border(int x, int y) 
{
    int i;
    for (i = 0; i < x; ++i) {
        move(0, i);
        addch('*');

        move(y-1, i);
        addch('*');
    }

    for (i = 0; i < y; ++i) {
        move(i, 0);
        addch('*');
        
        move(i, x-1);
        addch('*');
    }
}

void draw_border(Border old_border, Border new_border) {
    /*for (int y = 0; y < SCREEN_HEIGHT; ++y) {
        move(y, old_border[y].left);
        addch(' ');
        move(y, new_border[y].left);
        addch('#');
    
        move(y, old_border[y].right);
        addch(' ');
        move(y, new_border[y]. right);
        addch('#');
    }*/
}