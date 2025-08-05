#pragma once
#include "Display.h"

#define STARS_N ((BUFFER_W / 2) - 1)

typedef struct STAR {
	float y;
	float speed;
} STAR;

extern STAR stars[STARS_N];

void stars_init();
void stars_update();
void stars_draw();