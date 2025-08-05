#pragma once
#include <allegro5/allegro_font.h>

extern ALLEGRO_FONT* font;
extern long score_display;

void hud_init();
void hud_deinit();
void hud_update();
void hud_draw();