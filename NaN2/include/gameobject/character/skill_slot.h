// skill_slot.h
#ifndef SKILL_SLOT_H_
#define SKILL_SLOT_H_

namespace nan2 {

	namespace SkillSlot {

		enum SkillSlot {
			PRIMARY,
			SECONDARY,
			SKILL1,
			SKILL2,
			SKILL3
		};

	}

}

#define SkillSlot SkillSlot::SkillSlot

#endif