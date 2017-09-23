// character.cpp
#include "gameobject/character/character.h"

#include "world/player.h"
#include "gameobject/weapon/weapon_factory.h"
#include "skill/single_projectile_skill.h"
#include "skill/instant_clear_skill.h"
#include "network/skill_cast_snapshot.h"

#include "logger/logger.h"
#include "world_time.h"

#include "network/proud_server.h"

namespace nan2 {

  Character::Character(Player* player) : 
  GameObject(GameObjectType::Character, true, true, false),
  player_(player),
  living_(this, 30),
  placeable_(this, Vector2(0, 0), Vector2(8, 20), Vector2(0, 3)),
  movable_(this),
  recorder_(this),
  speed_(60.0f) {
    weapon_ = WeaponFactory::CreateProjectileWeapon(this);

    AddComponent(&living_);
    AddComponent(&placeable_);
    AddComponent(&movable_);
    AddComponent(&recorder_);

    placeable_.AddLayer(Layer::CHARACTER);
    placeable_.AddTargetLayer(Layer::STATIC_COLLIDER);
    placeable_.AddTargetLayer(Layer::CHARACTER);

	SingleProjectileSkill* skill1 = new SingleProjectileSkill(this, Projectile(Vector2(0, 0), Vector2(0, 0), 0, 30.f, 10));
    InstantClearSkill* skill2 = new InstantClearSkill(this);

	SetSkill(SkillSlot::PRIMARY, skill1);
    SetSkill(SkillSlot::SECONDARY, skill2);

    registerRecorder(static_cast<RecorderInterface*>(&recorder_));
  }

  Skill* const Character::GetSkill(SkillSlot slot) {
	  return skills_[slot];
  }

  void Character::SetSkill(SkillSlot slot, Skill* const skill) {
	  skills_[slot] = skill;
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
  	  weapon_->set_dir(input.aim_dir);
        weapon_->set_position(movable_.position() + weapon_->CalculateCharacterWeaponPivot());

  	  if (input.skill_type != -1) {
        L_DEBUG << "[Skill casted] Type = " << input.skill_type << ", Aim = " << (int)input.aim_dir;

  		  auto skill = GetSkill((SkillSlot)input.skill_type);
  		  auto fired = skill->Cast();

        if (fired) {
          if (skill->guaranteed()) {
            ProudServer::instance()->SendSkillCastSnapshot(player_, SkillCastSnapshot{
              input.skill_type,
              0,
              0,
              0
            });
          }
          else {
            weapon_fire_snapshots_.push_back({
              input.skill_type,
              movable_.position().x(),
              movable_.position().y(),
              input.aim_dir,
              Time::current_time()
            });
          }
        }
	    }
	  
  // if (input.fire_dir < 252) {
  //   weapon_->set_dir(input.fire_dir);
  //   weapon_->set_position(movable_.position() +  weapon_->CalculateCharacterWeaponPivot());
  //   bool fired = weapon_->Fire1();

  //   if (fired)
  //     weapon_fire_snapshots_.push_back({
  //       movable_.position().x(),
  //       movable_.position().y(),
  //       input.fire_dir,
  //       Time::current_time()
  //   });
  // }
	  
      last_acked_input_sequence_ = input.sequence;
      input_queue_.pop();
    }
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
      player_->id(),
      pos.x(),
      pos.y(),
      (uint8_t)living_.hp(),
      weapon_fire_snapshots_
    };
  }

  void Character::CleanSnapshot() {
    weapon_fire_snapshots_.clear();
  }

  Weapon* const Character::weapon() {
	  return weapon_;
  }

}