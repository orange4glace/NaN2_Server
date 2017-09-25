// player.cpp
#include "world/player.h"

#include "gameobject/character/character.h"

#include "network/proud_server.h"

#include <algorithm>

namespace nan2 {

  Player::Player(PlayerID id) : 
  id_(id),
  recent_ping_(0) {
    character_ = new Character(this);
    World::instance()->AddGameObject(character_);
  }

  Player::~Player() {
    World::instance()->RemoveGameObject(character_);
  }

  Character* const Player::character() {
    return character_;
  }

  Proud::HostID Player::id() const {
    return id_;
  }

  void Player::SendSnapshotsToRemote() const {
    std::vector<RemoteCharacterSnapshot> remotes;
    ProudServer::instance()->IteratePlayers([&](Player* player) -> bool {
      if (player->id() == id_) return true;
      remotes.emplace_back(player->character()->GetRemoteCharacterSnapshot());
      return true;
    });
    ProudServer::instance()->SendCharacterSnapshots(this, character_->GetLocalCharacterSnapshot(), remotes);
  }
  
  void Player::CleanSnapshot() {
    character_->CleanSnapshot();
  }

  int Player::GetRecentPing() {
    auto ping = ProudServer::instance()->GetPlayerPing(this);
    if (ping == -1) return recent_ping_;
    recent_ping_ = ping;
    return ping;
  }
}