#include <curses.h>
#include <unistd.h>
#include <time.h>
#include "track.h"


void draw_track(Track track, Screen screen, int *fence) 
{
    int y;
    int left_border = (screen.ord_x - track.width) / 2;
    int right_border = (screen.ord_x  + track.width) / 2;
    int min_y = 0, max_y = screen.ord_y; 
    
    for (y = min_y; y < max_y; ++y) {
        move(y, left_border);
        addch(fence[y]);
        move(y, right_border);
        addch(fence[y]);
    }
    
}

void draw_finish(Track track, Screen screen)
{
    int x, y;
    int left_border = (screen.ord_x - track.width) / 2;
    int right_border = (screen.ord_x + track.width) / 2;
    int min_y = 5, max_y = 10;
    
    for (y = min_y; y <= max_y; y++) {
        for (x = left_border; x <= right_border; ++x) {
            move(y, x);
            addch('*');
        }
    }
}

void draw_edges_of_track(int *fence, int ord_y)
{
    int y = ord_y - 1;
    int temp;

    temp = fence[y];
    for (; y >= 0; --y) {
        fence[y + 1] = fence[y];
    }
    fence[0] = temp;
}

void draw_track_at_screen_offset(Track track, Screen screen, int screen_y_offset) 
{
    TrackFence *fences = track.fences;
    int fences_count = track.fences_count;
    int i;

    for (i = 0; i < fences_count; ++i) {
        TrackFence f = fences[i];
        if (f.y_offset > screen_y_offset + screen.ord_y) {
            break;
        }
        if (f.y_offset + f.length < screen_y_offset) {
            continue;
        }
        if (f.y_offset < screen_y_offset) {
            int l = f.y_offset + f.length - screen_y_offset;
            draw_fence(0, l, f.side, f.width, track, screen);
        } else {
            draw_fence(f.y_offset - screen_y_offset, f.length, f.width, f.side, track, screen);
        }
    }
}

void draw_fence(int y_offset, 
                int length,
                TrackFenceSide side, 
                int width,
                Track track, Screen screen)
{
  int left = (screen.ord_x - track.width) / 2;
  int right = (screen.ord_x + track.width) / 2;
  int y;
  for (y = y_offset; y < length; ++y) {
    if (side == TrackFenceSideLeft) {
        int x;
        for (x = 0; x < width; ++x) {
            move(y, left + x);
            addch('#');
        }
    } else {
        int x;
        for (x = 0; x < width; ++x) {
            move(y, right - x);
            addch('#');
      }
    }
  }
}
