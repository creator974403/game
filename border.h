#ifndef BORDER_H
#define BORDER_H


typedef struct {
    int min_x, max_x;
    int min_y, max_y;
} Border;

typedef struct {
    int right;
    int left;
} Borders;


void draw_inital_border(int x, int y);
/*void draw_border(Border old_border, Border new_border);

Border get_next_border(Border border);*/


#endif