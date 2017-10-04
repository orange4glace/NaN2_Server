// player_event_listener.h
#ifndef MODULE_PLAYER_EVENT_LISTENER_H_
#define MODULE_PLAYER_EVENT_LISTENER_H_

#include "event_listener.h"

#include "../../world/player.h"

namespace nan2 {

namespace module {

namespace event_listener {

class PlayerEventListener : public EventListener<PlayerEventListener> {

  virtual void OnPlayerJoin(Player* const player) {};
  virtual void OnPlayerLeave(Player* const player) {};

public:
  inline PlayerEventListener() : EventListener<PlayerEventListener>() {}
  inline PlayerEventListener(Priority priority) : EventListener<PlayerEventListener>(priority) {}

};

}

}

}

#endif