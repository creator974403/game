#ifndef BORDER_H
#define BORDER_H

#include "screen.h"


typedef struct {
	int width;
	int length;
} Track;


void draw_track(Track track, Screen screen, int *fence);
void draw_finish(Track track, Screen screen);
void draw_edges_of_track(int *fence, int ord_y);

#endif