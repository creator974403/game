#ifndef BORDER_H
#define BORDER_H

#include "screen.h"


typedef enum {
  TrackFenceSideLeft  = 1, // слева
  TrackFenceSideRight = 2, // справа
} TrackFenceSide;

typedef struct {
  TrackFenceSide side; // сторона
  int y_offset;
  int length;
  int width;
} TrackFence; // бордюрчик

typedef struct {
	int width;
	int length;
	int fence_count;
  	TrackFence *fences;
} Track;


void draw_track(Track track, Screen screen, int *fence);
void draw_finish(Track track, Screen screen);
void draw_edges_of_track(int *fence, int ord_y);
void draw_track_at_screen_offset(Track track, Screen screen, int screen_y_offset);
void draw_fence(int y_offset, int length, TrackFenceSide side, int width, Track track, Screen screen);

#endif