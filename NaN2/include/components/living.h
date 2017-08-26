// Living.h
#ifndef LIVING_H_
#define LIVING_H_

#include "component.h"

#include <vector>
#include <functional>

// [Require Component (Placeable)]
namespace nan2 {

  class Living : public Component {

  private:
    int hp_;

    std::vector<std::function<void(void)>> zero_callbacks_;
    void CallZeroCallbacks();

  public:
    Living(GameObject* go);

    static ComponentType component_type();
    inline ComponentType type() const override {
      return ComponentType::Living;
    }

    void RegisterZeroCallback(std::function<void(void)>&& f);

    int hp() const;
    void set_hp(int val);

    bool IsAlive() const;
    void Subtract(int val);
    void Add(int val);

  };
}

#endif