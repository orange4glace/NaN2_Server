// player.cpp
#include "world/player.h"

#include "gameobject/character/character.h"

#include <algorithm>

namespace nan2 {

  Player::Player(Proud::HostID id) : 
  id_(id),
  character_(this) {
    World::instance()->AddGameObject(&character_);
  }

  Player::~Player() {

  }

  Character* const Player::character() {
    return &character_;
  }

  Proud::HostID Player::id() const {
    return id_;
  }
}