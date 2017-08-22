// Living.cpp
#include "components/living.h"

namespace nan2 {

  Living::Living(GameObject* game_object) :
  Component(game_object) {
  }

  ComponentType Living::type() const {
    return ComponentType::Living;
  }

  void Living::CallZeroCallbacks() {
    for (auto& cb : zero_callbacks_) {
      cb();
    }
  }

  void Living::RegisterZeroCallback(std::function<void(void)>&& f) {
    zero_callbacks_.emplace_back(f);
  }

  int Living::hp() const {
    return hp_;
  }

  void Living::set_hp(int val) {
    hp_ = val;
    if (hp_ <= 0) {
      CallZeroCallbacks();
      hp_ = 0;
    }
  }

  bool Living::IsAlive() const {
    return hp_ > 0;
  }

  void Living::Subtract(int val) {
    hp_ -= val;
    if (hp_ <= 0) {
      CallZeroCallbacks();
      hp_ = 0;
    }
  }

  void Living::Add(int val) {
    hp_ += val;
  }

}