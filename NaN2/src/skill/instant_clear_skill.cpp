// instant_clear_skill.cpp
#include "skill/instant_clear_skill.h"

#include "gameobject/character/character.h"
#include "world/world.h"
#include "world/player.h"

namespace nan2 {

  InstantClearSkill::InstantClearSkill(Character* character) :
    Skill(character, true) {

  }

  bool InstantClearSkill::Cast() {
    L_DEBUG << "[Skill Casted] Instant Clear Skill Casted";
    World::instance()->IterateGameObjects([](GameObject* go)-> bool {
      if (go->type() == GameObjectType::Projectile) {
        World::instance()->RemoveGameObject(go);
        L_DEBUG << "Destroy Projectile " << go->internal_id();
      }
      return true;
    });
    return true;
  }

}