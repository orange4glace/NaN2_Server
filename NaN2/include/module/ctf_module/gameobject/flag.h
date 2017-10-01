// module.h
#ifndef MODULE_CTF_MODULE_FLAG_H_
#define MODULE_CTF_MODULE_FLAG_H

#include "../../../gameobject/game_object.h"

#include "../../../components/placeable.h"
#include "../../../components/movable.h"

#include "../../team_module/team.h"

#include "../../event_listener/world_event_listener.h"

namespace nan2 {

namespace module {

namespace ctf_module {

class Flag : public GameObject, public event_listener::WorldEventListener {

  Placeable placeable_;
  Movable movable_;

  team_module::Team* team_;
  Vector2 base_position_;

  Player* attached_player_;

public:
  Flag(team_module::Team* const team, const Vector2& position);

  void base_position(const Vector2& position);
  const Vector2& base_position() const;

  void Attach(Player* const player);
  void Detach();

  void Update() override;

  void OnGameObjectStaged(GameObject* const go) override;
  void OnGameObjectRemoved(GameObject* const go) override;

};

}

}

}

#endif