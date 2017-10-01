// flag.cpp
#include "module/ctf_module/gameobject/flag.h"

#include "module/ctf_module/ctf_module.h"
#include "module/team_module/team_module.h"

namespace nan2 {

namespace module {

namespace ctf_module {

Flag::Flag(team_module::Team* const team, const Vector2& position) :
GameObject((GameObjectType)0, true, false, true),
placeable_(this, position, Vector2(0, 0), Vector2::ZERO),
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
}

void Flag::Return(Character* const character) {
  returned_ = true;
  movable_.MoveTo(base_position_);
  CTFModule::GetModule()->ProxyFlagReturned(this, character->player());
}

void Flag::Score() {
#ifdef _DEBUG
  if (attached_player_ == nullptr)
    throw std::string("[Flag] Try to score while not attached.");
#endif
  returned_ = true;
  movable_.MoveTo(base_position_);
  CTFModule::GetModule()->ProxyScored(attached_player_);
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
    auto team_info = CTFModule::GetModule()->team_info(team);
    if (placeable_.Contain(team_info.base_point)) {
      Score();
    }
  }
}

void Flag::OnCharacterDeath(Character* const character) {
  if (attached_player_->character() == character)
    Detach();
}

}

}

}