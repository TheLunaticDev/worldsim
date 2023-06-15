#include "shutdown.h"
#include "eventqueue.h"
#include "display.h"
#include "render_timer.h"
#include "engine_options.h"

int system_shutdown()
{
  al_destroy_timer(render_timer);
  al_destroy_event_queue(queue);
  al_destroy_display(main_display);
  shutdown_engine_options();
  return 0;
}
