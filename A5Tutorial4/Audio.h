#pragma once
#include <allegro5/allegro_acodec.h>

extern ALLEGRO_SAMPLE* sample_shot;
extern ALLEGRO_SAMPLE* sample_explode[2];

void audio_init();
void audio_deinit();