// character.cpp
#include "gameobject/character/character.h"

#include "world/player.h"
#include "gameobject/weapon_factory.h"

#include "logger/logger.h"
#include "world_time.h"

namespace nan2 {

  Character::Character(Player* player) : 
  GameObject(GameObjectType::Character, true, true, false),
  player_(player),
  living_(this),
  placeable_(this, Vector2(-20, 5.0f), Vector2(10, 10)),
  movable_(this),
  recorder_(this) {
    weapon_ = WeaponFactory::CreateProjectileWeapon();

    AddComponent(&living_);
    AddComponent(&placeable_);
    AddComponent(&movable_);
    AddComponent(&recorder_);
  }

  Player* const Character::player() {
    return player_;
  }

  void Character::FixedUpdate() {

  }

  void Character::Update() {
    update_chance_time_ += Time::delta_time();
    while (!input_queue_.empty()) {
      auto& input = input_queue_.front();
      if (update_chance_time_ < input.dt) continue;
      update_chance_time_ -= input.dt;
      movable_.DiscreteMove252(input.move_dir, input.dt,
        [](GameObject* object) -> bool {
        return true;
      },
        [](GameObject* object) -> bool {
        return true;
      });
      input_queue_.pop();
    }
  }

  void Character::Rewind(int time) {

  }

  void Character::Restore() {

  }

  void Character::AddInput(const PlayerInputPacket& packet) {
    input_queue_.emplace(packet);
  }
}