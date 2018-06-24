#ifndef BORDER_H
#define BORDER_H

#include "screen.h"

#define LENGTH_TRACK 1000
#define WIDTH_TRACK 40

typedef struct {
	int width;
	int length;
} Track;


void draw_track(int LENGTH_TRACK,Track track, Screen screen);
void draw_frieze(int x, int y);


#endif