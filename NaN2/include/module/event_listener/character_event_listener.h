// player_event_listener.h
#ifndef MODULE_CHARACTER_EVENT_LISTENER_H_
#define MODULE_CHARACTER_EVENT_LISTENER_H_

#include "event_listener.h"

#include "../../gameobject/character/character.h"

namespace nan2 {

namespace module {

namespace event_listener {

class CharacterEventListener : public EventListener<CharacterEventListener> {

  virtual void OnCharacterSpawn(Character* const character) {};
  virtual void OnCharacterDeath(Character* const character) {};

public:
  inline CharacterEventListener() : EventListener<CharacterEventListener>() {}
  inline CharacterEventListener(Priority priority) : EventListener<CharacterEventListener>(priority) {}

  static void CharacterSpawn(Character* const character) {
    for (auto li : listeners_) li->OnCharacterSpawn(character);
  }

  static void CharacterDeath(Character* const character) {
    for (auto li : listeners_) li->OnCharacterDeath(character);
  }

};

}

}

}

#endif