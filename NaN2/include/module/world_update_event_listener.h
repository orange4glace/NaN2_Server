// world_update_event_listener.h
#ifndef MODULE_WORLD_UPDATE_EVENT_LISTENER_H_
#define MODULE_WORLD_UPDATE_EVENT_LISTENER_H_

#include "../player.h"

namespace nan2 {

namespace module {

class WorldUpdateEventListener {

  virtual void OnUpdate(int dt) = 0;

};

}

}

#endif