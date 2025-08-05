#pragma once

#define SHOTS_N 128

typedef struct SHOT {
	int x, y, dx, dy;
	int frame;
	bool ship;
	bool used;
} USED;

extern SHOT shots[SHOTS_N];

void shots_init();
bool shots_add(bool ship, bool straight, int x, int y);
void shots_update();
bool shots_collide(bool ship, int x, int y, int w, int h);
void shots_draw();