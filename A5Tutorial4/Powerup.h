#pragma once
#include "Items.h"

#define POWERUP_N 8

//rarity decided on spawn, item decided on pickup
typedef enum POWERUP_RARITY {
	POWERUP_COMMON = 0,
	POWERUP_UNCOMMON,
	POWERUP_RARE,
	POWERUP_RARITY_N
} POWERUP_RARITY;

typedef struct Powerup {
	int x, y;
	int frame;
	bool used;
	POWERUP_RARITY rarity;
} Powerup;

extern Powerup powerup[POWERUP_N];

void powerup_init();
void powerup_update();
void powerup_draw();
ITEMS powerup_collide(int x, int y, int w, int h);