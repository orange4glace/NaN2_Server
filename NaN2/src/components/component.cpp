// component.cpp
#include "components/component.h"

namespace nan2 {

  Component::Component(GameObject* game_object) :
  game_object_(game_object) {
  }

  GameObject* Component::game_object() const {
    return game_object_;
  }

}