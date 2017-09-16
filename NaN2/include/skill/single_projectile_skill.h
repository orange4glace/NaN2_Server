// single_projectile_skill.h
#ifndef SINGLE_PROJECTILE_SKILL_H_
#define SINGLE_PROJECTILE_SKILL_H_

#include "skill.h"
#include "../gameobject/weapon/projectile/projectile.h"

namespace nan2 {

	class SingleProjectileSkill : public Skill {
		
	protected:
		Projectile projectile_;

	public:

		SingleProjectileSkill(Character* character, const Projectile& projectile);

		void Cast() override;

	};

}

#endif