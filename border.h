#ifndef BORDER_H
#define BORDER_H

#include "screen.h"

typedef struct {
	int radius;
} Border;


void draw_border(Border border, Screen screen);
/*void draw_border(Border old_border, Border new_border);

Border get_next_border(Border border);*/


#endif