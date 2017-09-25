// player_event_listener.h
#ifndef WORLD_MODULE_PLAYER_EVENT_LISTENER_H_
#define WORLD_MODULE_PLAYER_EVENT_LISTENER_H_

#include "../player.h"

namespace nan2 {

namespace world_module {

class PlayerEventListener {
  
  virtual void OnPlayerJoin(Player* const player) = 0;
  virtual void OnPlayerLeave(Player* const player) = 0;

};

}

}

#endif