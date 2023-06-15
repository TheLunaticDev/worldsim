#include <allegro5/allegro.h>
#ifndef ENGINE_OPTIONS_H
#define ENGINE_OPTIONS_H

typedef struct engine_options engine_options;
void initialize_engine_options(ALLEGRO_CONFIG* config);
void shutdown_engine_options();

int get_display_width();
int get_display_height();
int get_render_refresh_rate();
ALLEGRO_COLOR get_display_background();
int get_world_width();
int get_world_height();
int get_world_size();
int get_world_positionx();
int get_world_positiony();
int get_world_thickness();
ALLEGRO_COLOR get_world_color();
#endif
