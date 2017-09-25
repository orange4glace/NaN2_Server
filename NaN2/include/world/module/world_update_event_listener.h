// world_update_event_listener.h
#ifndef WORLD_MODULE_WORLD_UPDATE_EVENT_LISTENER_H_
#define WORLD_MODULE_WORLD_UPDATE_EVENT_LISTENER_H_

#include "../player.h"

namespace nan2 {

namespace world_module {

class WorldUpdateEventListener {

  virtual void OnUpdate(int dt) = 0;

};

}

}

#endif