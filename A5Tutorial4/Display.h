#pragma once
#include <allegro5/allegro5.h>

#define BUFFER_W 320
#define BUFFER_H 240

#define DISP_SCALE 4
#define DISP_W (BUFFER_W * DISP_SCALE)
#define DISP_H (BUFFER_H * DISP_SCALE)

extern ALLEGRO_DISPLAY* display;
extern ALLEGRO_BITMAP* buffer;

void disp_init();
void disp_deinit();
void disp_pre_draw();
void disp_post_draw();