#ifndef BORDER_H
#define BORDER_H

#include "screen.h"


typedef struct {
	int radius;
} Track;


void draw_track(Track track, Screen screen);


#endif