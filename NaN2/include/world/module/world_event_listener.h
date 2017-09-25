// world_event_listener.h
#ifndef WORLD_MODULE_WORLD_EVENT_LISTENER_H_
#define WORLD_MODULE_WORLD_EVENT_LISTENER_H_

#include "../player.h"

namespace nan2 {

namespace world_module {

class WorldEventListener {

  virtual void OnGameObjectStaged(GameObject* const go) = 0;
  virtual void OnGameObjectRemoved(GameObject* const go) = 0;

};

}

}

#endif