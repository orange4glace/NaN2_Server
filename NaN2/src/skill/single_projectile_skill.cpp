// single_projectile_skill.cpp
#include "skill/single_projectile_skill.h"

#include "gameobject/character/character.h"
#include "world/player.h"

namespace nan2 {

	SingleProjectileSkill::SingleProjectileSkill(Character* character, const Projectile& projectile) :
		Skill(character),
		projectile_(projectile) {

	}

	void SingleProjectileSkill::Cast() {
		int aim = character_->weapon()->dir();
		Projectile* projectile = new Projectile(projectile_);
		auto fire_point = character_->weapon()->GetFirePoint();
		Vector2 offset = MathHelper::instance().RotateVector252(fire_point, MathHelper::instance().biased_direction(aim));
		projectile->set_position(fire_point);
		projectile->set_dir(aim);
		projectile->set_rewind_time(character_->player()->GetRecentPing());
		World::instance()->AddGameObject(projectile);
	}

} 