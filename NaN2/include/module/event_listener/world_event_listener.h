// world_event_listener.h
#ifndef MODULE_WORLD_EVENT_LISTENER_H_
#define MODULE_WORLD_EVENT_LISTENER_H_

#include "event_listener.h"

#include "../../gameobject/game_object.h"

namespace nan2 {

namespace module {

namespace event_listener {

class WorldEventListener : public EventListener<WorldEventListener> {

  virtual void OnGameObjectStaged(GameObject* const go) {};
  virtual void OnGameObjectRemoved(GameObject* const go) {};

public:
  inline WorldEventListener() : EventListener<WorldEventListener>() {}
  inline WorldEventListener(Priority priority) : EventListener<WorldEventListener>(priority) {}

  static void GameObjectStaged(GameObject* const go) {
    for (auto li : listeners_) li->OnGameObjectStaged(go);
  }

  static void GameObjectRemoved(GameObject* const go) {
    for (auto li : listeners_) li->OnGameObjectRemoved(go);
  }

};

}

}

}

#endif