#include "shutdown.h"
#include "eventqueue.h"
#include "display.h"
#include "render_timer.h"
#include "engine_options.h"

int system_shutdown()
{
  destroy_event_queue();
  destroy_render_timer();
  destroy_main_display();
  shutdown_engine_options();
  al_uninstall_system();
  return 0;
}
