#include "Items.h"
#include "Util.h"
#include "Powerup.h"

ITEM_ATTR item[ITEMS_N];

void items_init() {
	item[ITEM_DMG_UP].rarity = POWERUP_COMMON;
	item[ITEM_FIRE_DMG].rarity = POWERUP_UNCOMMON;
	item[ITEM_EXTRA_LIFE].rarity = POWERUP_RARE;
	item[ITEM_DMG_UP_2].rarity = POWERUP_RARE;
}

ITEMS items_get(POWERUP_RARITY rarity) {
	ITEMS items[ITEMS_N];
	int count = 0;

	for (int i = 0; i < ITEMS_N; i++) {
		if (item[i].rarity == rarity) {
			items[count++] = (ITEMS)i;
		}
	}

	if (count == 0) {
		return ITEM_DMG_UP;
	}
	else if (count == 1) {
		int index = 0;
		return items[index];
	}

	int index = between(0, count - 1);
	return items[index];
}