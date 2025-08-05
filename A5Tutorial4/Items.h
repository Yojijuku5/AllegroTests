#pragma once

#define ITEMS_N ITEM_N

typedef enum POWERUP_RARITY POWERUP_RARITY;

typedef enum ITEMS {
	ITEM_DMG_UP = 0,
	ITEM_FIRE_DMG,
	ITEM_EXTRA_LIFE,
	ITEM_DMG_UP_2,
	ITEM_N
} ITEMS;

typedef struct ITEM_ATTR {
	POWERUP_RARITY rarity;
} ITEM_ATTR;

extern ITEM_ATTR item[ITEMS_N];

void items_init();
ITEMS items_get(POWERUP_RARITY rarity);

//pickup item, go through items array, search for item of same rarity, return value