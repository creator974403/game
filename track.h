#ifndef BORDER_H
#define BORDER_H

#include "screen.h"


typedef struct {
	int width;
	int length;
} Track;


void draw_track(Track track, Screen screen, double distance);
void draw_frieze(int x, int y);


#endif