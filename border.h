#ifndef BORDER_H
#define BORDER_H

#include "screen.h"


typedef struct {
	int radius;
} Border;


void draw_border(Border border, Screen screen);


#endif