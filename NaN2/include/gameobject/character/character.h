// character.h
#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "../game_object.h"

#include "../../components/living.h"
#include "../../components/placeable.h"
#include "../../components/movable.h"

#include "../weapon.h"

#include "character_recorder.h"

#include "../../network/player_input_packet.h"
#include <queue>

namespace nan2 {

  class Player;

  class Character : public GameObject {

    Player* player_;

    Living living_;
    Placeable placeable_;
    Movable movable_;

    CharacterRecorder recorder_;

    Weapon* weapon_;

    std::queue<PlayerInputPacket> input_queue_;

    float speed_;

    int update_chance_time_;

  public:
    Character(Player* player);

    Player* const player();

    void FixedUpdate();
    void Update();

    void Rewind(int time);
    void Restore();

    void AddInput(const PlayerInputPacket& packet);
  };

}

#endif