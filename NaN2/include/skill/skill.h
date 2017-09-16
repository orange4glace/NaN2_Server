// skillbase.h
#ifndef SKILL_BASE_H_
#define SKILL_BASE_H_

namespace nan2 {

	class Character;

	class Skill {

	protected:
		Skill(Character* character);

		Character* character_;

	public:
		virtual void Cast() = 0;

	};

}

#endif