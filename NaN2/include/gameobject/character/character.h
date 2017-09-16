// character.h
#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "../game_object.h"

#include "../../components/living.h"
#include "../../components/placeable.h"
#include "../../components/movable.h"

#include "../weapon/weapon.h"
#include "../../skill/skill.h"
#include "skill_slot.h"

#include "character_record.h"
#include "character_recorder.h"

#include "network/player_input_packet.h"
#include "network/local_character_snapshot.h"
#include "network/remote_character_snapshot.h"
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
	std::map<int, Skill*> skills_;

    std::queue<PlayerInputPacket> input_queue_;
    std::vector<WeaponFireSnapshot> weapon_fire_snapshots_;

    float speed_;

    int update_chance_time_;
    int last_acked_input_sequence_;

  protected:
	  void SetSkill(SkillSlot id, Skill* const skill);

  public:
    Character(Player* player);

    Player* const player();

    void FixedUpdate();
    void Update();

    void AddInput(const PlayerInputPacket& packet);
     
    const CharacterRecord GetRecord() const;
    void ApplyRecord(const CharacterRecord& record);
    const LocalCharacterSnapshot GetLocalCharacterSnapshot() const;
    const RemoteCharacterSnapshot GetRemoteCharacterSnapshot() const;
    void CleanSnapshot();

	Weapon* const weapon();
    
  };

}

#endif