// character.cpp
#include "gameobject/character/character.h"

#include "world/player.h"
#include "gameobject/weapon/weapon_factory.h"

#include "logger/logger.h"
#include "world_time.h"

namespace nan2 {

  Character::Character(Player* player) : 
  GameObject(GameObjectType::Character, true, true, false),
  player_(player),
  living_(this),
  placeable_(this, Vector2(-20, 5.0f), Vector2(10, 10)),
  movable_(this),
  recorder_(this),
  speed_(30.0f) {
    weapon_ = WeaponFactory::CreateProjectileWeapon(this);

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
      if (update_chance_time_ < input.dt) break;
      update_chance_time_ -= input.dt;
      float dd = (input.dt) / 1000.f * speed_;
      movable_.DiscreteMove252(input.move_dir, dd,
        [](GameObject* object) -> bool {
        return true;
      },
        [](GameObject* object) -> bool {
        return true;
      });
      last_acked_input_sequence_ = input.sequence;
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

  const CharacterRecord Character::GetRecord() const {
    return CharacterRecord{
      living_.hp(),
      movable_.position()
    };
  }

  void Character::ApplyRecord(const CharacterRecord& record) {
    living_.set_hp(record.hp);
    movable_.set_position(record.position);
  }

  const LocalCharacterSnapshot Character::GetLocalCharacterSnapshot() const {
    auto& pos = placeable_.position();
    return{
      last_acked_input_sequence_,
      pos.x(),
      pos.y(),
      (uint8_t)living_.hp()
    };
  }

  const RemoteCharacterSnapshot Character::GetRemoteCharacterSnapshot() const {
    auto& pos = placeable_.position();
    return{
      pos.x(),
      pos.y(),
      (uint8_t)living_.hp()
    };
  }

}