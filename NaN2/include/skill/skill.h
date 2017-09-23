// skillbase.h
#ifndef SKILL_BASE_H_
#define SKILL_BASE_H_

namespace nan2 {

	class Character;

	class Skill {

	protected:
		Skill(Character* character, bool guaranteed);

		Character* character_;
        bool guaranteed_;

	public:
		virtual bool Cast() = 0;

        bool guaranteed() const;

	};

}

#endif