// flag.cpp
#include "module/ctf_module/gameobject/flag.h"

#include "module/ctf_module/ctf_module.h"
#include "module/team_module/team_module.h"

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

}

void Flag::base_position(const Vector2& position) {
  base_position_ = position;
}

const Vector2& Flag::base_position() const {
  return base_position_;
}

void Flag::Attach(Character* const character) {
#ifdef _DEBUG
  if (attached_player_ != nullptr)
    throw std::string("[Flag] Already attached to " + character->player()->id());
#endif
  returned_ = false;
  CTFModule::GetModule()->ProxyFlagCaptured(this, character->player());
  attached_player_ = character->player();
  L_DEBUG << "[Flag team_id = " << team_->id() << "] Attached to player " << character->player()->id();
}

void Flag::Detach() {
#ifdef _DEBUG
  if (attached_player_ != nullptr)
    throw std::string("[Flag] Not attached.");
#endif
  auto pos = attached_player_->character()->GetComponent<Movable>()->position();
  movable_.MoveTo(pos);
  attached_player_ = nullptr;
  CTFModule::GetModule()->ProxyFlagDropped(this, attached_player_, pos);
  L_DEBUG << "[Flag team_id = " << team_->id() << "] Detached";
}

void Flag::Return(Character* const character) {
  returned_ = true;
  movable_.MoveTo(base_position_);
  CTFModule::GetModule()->ProxyFlagReturned(this, character->player());
  L_DEBUG << "[Flag team_id = " << team_->id() << "] Returned by player " << character->player()->id();
}

void Flag::Score() {
#ifdef _DEBUG
  if (attached_player_ == nullptr)
    throw std::string("[Flag] Try to score while not attached.");
#endif
  auto attached_player_team = team_module::TeamModule::GetModule()->GetTeam(attached_player_);
  returned_ = true;
  movable_.MoveTo(base_position_);
  attached_player_team->AddScore(1);
  L_DEBUG << "[Flag team_id = " << team_->id() << "] is scored to team " << attached_player_team << " by player " << attached_player_->id();
  attached_player_ = nullptr;
}

void Flag::Update() {
  if (attached_player_ == nullptr) {
    World::instance()->IterateGameObjects<Character>([&](Character* character) -> bool {
      auto placeable = character->GetComponent<Placeable>();
      if (placeable_.Intersect(placeable)) {
        auto team = team_module::TeamModule::GetModule()->GetTeam(character->player());
        if (this->team_ == team) {
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
    auto team = team_module::TeamModule::GetModule()->GetTeam(attached_player_);
    auto team_data = CTFModule::GetModule()->team_data(team);
    if (placeable_.Contain(team_data.base_point)) {
      Score();
    }
  }
}

void Flag::OnCharacterDeath(Character* const character) {
  if (attached_player_->character() == character)
    Detach();
}

const Vector2& Flag::position() const {
  return placeable_.position();
}

bool Flag::returned() const {
  return returned_;
}

const Player* const Flag::attached_player() const {
  return attached_player_;
}

}

}

}