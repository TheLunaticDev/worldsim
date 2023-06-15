#include <allegro5/allegro.h>
#include <string.h>
#include "engine_options.h"
#include "error_handling.h"
#include "utility.h"


struct engine_options
{
  int display_width;
  int display_height;
  int render_refresh_rate;
  ALLEGRO_COLOR display_background;
  int world_width;
  int world_height;
  int world_size;
  int world_positionx;
  int world_positiony;
  int world_thickness;
  ALLEGRO_COLOR world_color;
};

engine_options* options = NULL;

void initialize_display_resolution(ALLEGRO_CONFIG* config);
void paint_display_background(ALLEGRO_CONFIG* config);
void initialize_render_rate(ALLEGRO_CONFIG* config);

void initialize_engine_options(ALLEGRO_CONFIG* config)
{
  options = malloc(sizeof(engine_options));
  if (options == NULL)
    handle_installation_error(MEMORY_ALLOCATION_FAILED_OPTIONS);

  initialize_display_resolution(config);
  paint_display_background(config);
  initialize_render_rate(config);
  
  options->world_width = atoi(al_get_config_value(config, "world", "width"));
  options->world_height = atoi(al_get_config_value(config, "world", "height"));
  options->world_size = atoi(al_get_config_value(config, "world", "size"));
  options->world_positionx = atoi(al_get_config_value(config, "world", "positionx"));
  options->world_positiony = atoi(al_get_config_value(config, "world", "positiony"));
  options->world_thickness = atoi(al_get_config_value(config, "world", "thickness"));
  options->world_color = hex_to_color(al_get_config_value(config, "world", "color"));
}

void shutdown_engine_options()
{
  free(options);
}

void initialize_display_resolution(ALLEGRO_CONFIG* config)
{
  const char* resolution = al_get_config_value(config, "display", "resolution");
  
  int width, height;
  int chosen = 0;

  if (resolution == NULL)
    {
      width = 800;
      height = 600;
      chosen = 1;
    }

  if (!chosen && (strcmp(resolution, "720x400") == 0))
    {
      width = 720;
      height = 400;
      chosen = 1;
    }

  if (!chosen && (strcmp(resolution, "640x480") == 0))
    {
      width = 640;
      height = 480;
      chosen = 1;
    }
  
  if (!chosen && (strcmp(resolution, "800x600") == 0))
    {
      width = 800;
      height = 600;
      chosen = 1;
    }
  
  if (!chosen && (strcmp(resolution, "1024x768") == 0))
    {
      width = 1024;
      height = 768;
      chosen = 1;
    }

  if (!chosen && (strcmp(resolution, "1360x768") == 0))
    {
      width = 1360;
      height = 768;
      chosen = 1;
    }

  if (!chosen && (strcmp(resolution, "1366x768") == 0))
    {
      width = 1366;
      height = 768;
      chosen = 1;
    }

  if (!chosen)
    {
      width = 800;
      height = 600;
    }

  options->display_width = width;
  options->display_height = height;
}

void paint_display_background(ALLEGRO_CONFIG* config)
{
  const char* color = al_get_config_value(config, "display", "background");
  if (color == NULL)
    color = "#282a36";
  options->display_background = hex_to_color(color);
}

void initialize_render_rate(ALLEGRO_CONFIG* config)
{
  const char* render_rate = al_get_config_value(config, "engine", "render rate");
  if (render_rate == NULL)
    render_rate = "60";

  int r_rate = atoi(render_rate);

  if (r_rate <= 0)
    r_rate = 60;
  
  options->render_refresh_rate = atoi(render_rate);
}

int get_display_width()
{
  return options->display_width;
}

int get_display_height()
{
  return options->display_height;
}

int get_render_refresh_rate()
{
  return options->render_refresh_rate;
}

ALLEGRO_COLOR get_display_background()
{
  return options->display_background;
}

int get_world_width()
{
  return options->world_width;
}

int get_world_height()
{
  return options->world_height;
}

int get_world_size()
{
  return options->world_size;
}

int get_world_positionx()
{
  return options->world_positionx;
}

int get_world_positiony()
{
  return options->world_positiony;
}

int get_world_thickness()
{
  return options->world_thickness;
}

ALLEGRO_COLOR get_world_color()
{
  return options->world_color;
}

