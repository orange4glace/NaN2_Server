// flag.cpp
#include "module/ctf_module/gameobject/flag.h"

namespace nan2 {

namespace module {

namespace ctf_module {

Flag::Flag(team_module::Team* const team, const Vector2& position) :
GameObject((GameObjectType)0, true, true, true),
placeable_(this, position, Vector2(0, 0), Vector2::ZERO),
movable_(this),
team_(team),
base_position_(position),
attached_player_(nullptr) {

}

void Flag::base_position(const Vector2& position) {
  base_position_ = position;
}

const Vector2& Flag::base_position() const {
  return base_position_;
}

void Flag::Attach(Player* const player) {
#ifdef _DEBUG
  if (attached_player_ != nullptr)
    throw std::string("[Flag] Already attached to " + player->id());
#endif
  attached_player_ = player;
}

void Flag::Detach() {
#ifdef _DEBUG
  if (attached_player_ != nullptr)
    throw std::string("[Flag] Not attached.");
#endif
  attached_player_ = nullptr;
}

void Flag::Update() {
  if (attached_player_ == nullptr) {
    World::instance()->IterateGameObjects<Character>([&](Character* character) -> bool {
      auto placeable = character->GetComponent<Placeable>();
      if (placeable_.Intersect(placeable)) {
        Attach(character->player());
        return false;
      }
      return true;
    });
  }
}

}

}

}