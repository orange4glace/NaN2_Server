// instant_clear_skill.h
#ifndef INSTANT_CLEAR_SKILL_H_
#define INSTANT_CLEAR_SKILL_H_

#include "skill.h"

namespace nan2 {

  class InstantClearSkill : public Skill {

  protected:

  public:

    InstantClearSkill(Character* character);

    bool Cast() override;

  };

}

#endif