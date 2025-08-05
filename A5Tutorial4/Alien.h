#pragma once

#define ALIENS_N 16

typedef enum ALIEN_TYPE {
	ALIEN_TYPE_BUG = 0,
	ALIEN_TYPE_ARROW,
	ALIEN_TYPE_THICCBOI,
	ALIEN_TYPE_N
} ALIEN_TYPE;

typedef struct ALIEN {
	int x, y;
	ALIEN_TYPE type;
	int shot_timer;
	int blink;
	int life;
	bool used;
} ALIEN;

extern ALIEN aliens[ALIENS_N];

void aliens_init();
void aliens_update();
void aliens_draw();