#include "border.h"
#include <curses.h>
#include <unistd.h>

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

/*void draw_border(Border old_border, Boredr new_border) 
{
    for (int y = 0; y < border.max_y; ++y) {
        move(y, old_border.left);
        addch(' ');
        move(y, new_border.left);
        addch('#');
    
        move(y, old_border.right);
        addch(' ');
        move(y, new_border.right);
        addch('#');
    }
}

Border get_next_border(Border border)
{
    border b;
    b.x = border.min_x+10;
    b.y = border.min_y;

    return b;
}*/