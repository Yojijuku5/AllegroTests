#pragma once

#define FX_N 128

typedef struct FX {
	int x, y;
	int frame;
	bool spark;
	bool used;
} FX;

extern FX fx[FX_N];

void fx_init();
void fx_add(bool spark, int x, int y);
void fx_update();
void fx_draw();

