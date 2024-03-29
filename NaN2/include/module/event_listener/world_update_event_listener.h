// world_update_event_listener.h
#ifndef MODULE_WORLD_UPDATE_EVENT_LISTENER_H_
#define MODULE_WORLD_UPDATE_EVENT_LISTENER_H_

#include "event_listener.h"

#include "../../world/player.h"

namespace nan2 {

namespace module {

namespace event_listener {

class WorldUpdateEventListener : public EventListener<WorldUpdateEventListener> {

  virtual void OnUpdate(int dt) {};

public:
  inline WorldUpdateEventListener() : EventListener<WorldUpdateEventListener>() {}
  inline WorldUpdateEventListener(Priority priority) : EventListener<WorldUpdateEventListener>(priority) {}

};

}

}

}

#endif