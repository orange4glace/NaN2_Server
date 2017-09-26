// world_event_listener.h
#ifndef MODULE_WORLD_EVENT_LISTENER_H_
#define MODULE_WORLD_EVENT_LISTENER_H_

#include "../player.h"

namespace nan2 {

namespace module {

class WorldEventListener {

  virtual void OnGameObjectStaged(GameObject* const go) = 0;
  virtual void OnGameObjectRemoved(GameObject* const go) = 0;

};

}

}

#endif