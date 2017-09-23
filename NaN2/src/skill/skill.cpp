// skillbase.cpp
#include "skill/skill.h"

#include "gameobject/character/character.h"

namespace nan2 {

	Skill::Skill(Character* character, bool guaranteed) :
	character_(character),
    guaranteed_(guaranteed) {
	}

    bool Skill::guaranteed() const {
      return guaranteed_;
    }

}