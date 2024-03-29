// flag.cpp
#include "module/ctf_module/gameobject/flag.h"

#include "module/ctf_module/ctf_module.h"
#include "module/team_module/team_module.h"

#include "logger/logger.h"

namespace nan2 {

namespace module {

namespace ctf_module {

Flag::Flag(team_module::Team* const team, const Vector2& position) :
GameObject((GameObjectType)0, true, false, true),
placeable_(this, position, Vector2(20, 20), Vector2::ZERO),
movable_(this),
team_(team),
base_position_(position),
returned_(true),
attached_player_(nullptr) {
  AddComponent<Placeable>(&placeable_);
  AddComponent<Movable>(&movable_);
}

void Flag::base_position(const Vector2& position) {
  base_position_ = position;
}

const Vector2& Flag::base_position() const {
  return base_position_;
}

void Flag::Attach(Character* const character) {
  assert(attached_player_ == nullptr);
  returned_ = false;
  CTFModule::GetModule()->ProxyFlagCaptured(this, character->player());
  attached_player_ = character->player();
  L_DEBUG << "[Flag team_id = " << team_->id() << "] Attached to player " << character->player()->id();
}

void Flag::Detach() {
  assert(attached_player_ != nullptr);
  auto pos = attached_player_->character()->GetComponent<Movable>()->position();
  movable_.MoveTo(pos);
  CTFModule::GetModule()->ProxyFlagDropped(this, attached_player_, pos);
  attached_player_ = nullptr;
  L_DEBUG << "[Flag team_id = " << team_->id() << "] Detached";
}

void Flag::Return(Character* const character) {
  returned_ = true;
  movable_.MoveTo(base_position_);
  CTFModule::GetModule()->ProxyFlagReturned(this, character->player());
  L_DEBUG << "[Flag team_id = " << team_->id() << "] Returned by player " << (character == nullptr ? "Scoring" : ""+character->player()->id());
}

void Flag::Score() {
  assert(attached_player_ != nullptr);
  auto attached_player_team = team_module::TeamModule::GetModule()->GetTeam(attached_player_);
  returned_ = true;
  movable_.MoveTo(base_position_);
  attached_player_team->AddScore(1);
  L_DEBUG << "[Flag team_id = " << team_->id() << "] is scored to team " << attached_player_team << " by player " << attached_player_->id();
  Return(attached_player_->character());
  attached_player_ = nullptr;
}

void Flag::Update() {
  if (attached_player_ == nullptr) {
    World::instance()->IterateGameObjects<Character>([&](Character* character) -> bool {
      if (!character->alive()) return true;
      auto placeable = character->GetComponent<Placeable>();
      if (placeable_.Intersect(placeable)) {
        auto team = team_module::TeamModule::GetModule()->GetTeam(character->player());
        if (this->team_ == team) {
          if (!this->returned_)
            Return(character);
        }
        else {
          Attach(character);
        }
        return false;
      }
      return true;
    });
  }
  else {
    auto character = attached_player_->character();
    placeable_.set_position(character->position());
    auto team = team_module::TeamModule::GetModule()->GetTeam(attached_player_);
    auto team_data = CTFModule::GetModule()->team_data(team);
    if (placeable_.Contain(team_data.base_point)) {
      Score();
    }
  }
}

void Flag::OnCharacterDeath(Character* const character) {
  if (attached_player_ == character->player())
    Detach();
}

const Vector2& Flag::position() const {
  return placeable_.position();
}

bool Flag::returned() const {
  return returned_;
}

team_module::Team* const Flag::team() const {
  return team_;
}

const Player* const Flag::attached_player() const {
  return attached_player_;
}

}

}

}