#include "Powerup.h"
#include "Util.h"
#include "Display.h"
#include "Sprites.h"
#include "Ship.h"

Powerup powerup[POWERUP_N];

void powerup_init() {
	for (int i = 0; i < POWERUP_N; i++) {
		powerup[i].used = false;
	}
}

void powerup_update() {
	int new_quota = (frames % 120) ? 0 : 1;
	int new_x = between(10, BUFFER_W - 50);

	for (int i = 0; i < POWERUP_N; i++) {
		if (!powerup[i].used) {
			if (new_quota > 0) {
				new_x += between(40, 80);
				if (new_x > (BUFFER_W - 60)) {
					new_x -= (BUFFER_W - 60);
				}

				powerup[i].x = new_x;
				powerup[i].y = between(-40, -30);
				powerup[i].used = true;
				powerup[i].rarity = static_cast<POWERUP_RARITY>(between(0, POWERUP_RARITY_N));

				new_quota--;
			}
			continue;
		}

		if (frames % 2) powerup[i].y++;

		if (powerup[i].y >= BUFFER_H) {
			powerup[i].used = false;
			continue;
		}

		powerup_collide(ship.x, ship.y, SHIP_W, SHIP_H);
	}
}

void powerup_draw() {
	for (int i = 0; i < POWERUP_N; i++) {
		if (!powerup[i].used) {
			continue;
		}

		int frame_display = powerup[i].frame / 2;

		switch (powerup[i].rarity) {
		case POWERUP_COMMON:
			al_draw_tinted_bitmap(sprites.powerup[frame_display], al_map_rgba_f(1, 0, 0, 1), powerup[i].x, powerup[i].y, 0);
			break;
		case POWERUP_UNCOMMON:
			al_draw_tinted_bitmap(sprites.powerup[frame_display], al_map_rgba_f(0, 1, 0, 1), powerup[i].x, powerup[i].y, 0);
			break;
		case POWERUP_RARE:
			al_draw_tinted_bitmap(sprites.powerup[frame_display], al_map_rgba_f(0, 0, 1, 1), powerup[i].x, powerup[i].y, 0);
			break;
		}
	}
}

ITEMS powerup_collide(int x, int y, int w, int h) {
	for (int i = 0; i < POWERUP_N; i++) {
		if (!powerup[i].used) {
			continue;
		}

		int sw = POWERUP_W;
		int sh = POWERUP_H;

		if (collide(x, y, x + w, y + h, powerup[i].x, powerup[i].y, powerup[i].x + sw, powerup[i].y + sh)) {
			powerup[i].used = false;
			score += 1000;
			return items_get(powerup[i].rarity);
		}
	}

	return ITEM_N;
}