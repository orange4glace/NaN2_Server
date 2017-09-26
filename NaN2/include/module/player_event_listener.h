// player_event_listener.h
#ifndef MODULE_PLAYER_EVENT_LISTENER_H_
#define MODULE_PLAYER_EVENT_LISTENER_H_

#include "../player.h"

namespace nan2 {

namespace module {

class PlayerEventListener {
  
  virtual void OnPlayerJoin(Player* const player) = 0;
  virtual void OnPlayerLeave(Player* const player) = 0;

};

}

}

#endif