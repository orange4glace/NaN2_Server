// movable.h
#ifndef MOVABLE_H_
#define MOVABLE_H_

#include "placeable.h"

// [Require Component (Placeable)]
namespace nan2 {

  class Movable : public Component {

  private:
    Placeable* placeable_;

  public:
    Movable(GameObject* go);

    static ComponentType component_type();
    inline ComponentType type() const override {
      return ComponentType::Movable;
    }

    void Awake();

    void set_position(const Vector2& val);
    const Vector2& position() const;

    // Condition check function
    // bool Lambda1(GameObject* game_object)
    // Collision callback function
    // bool Lambda1(GameObject* game_object)
    template <typename Lambda1, typename Lambda2>
    void DiscreteMove252(int dir, float dd, Lambda1&& condition, Lambda2&& collisionCallback, int simulation_time = -1);
    template <typename Lambda1, typename Lambda2>
    void DiscreteMove(float x, float y, Lambda1&& condition, Lambda2&& collisionCallback, int simulation_time = -1);

    template <typename Lambda1, typename Lambda2>
    void ContinuousMove252(int dir, float dist, Lambda1&& condition, Lambda2&& collisionCallback, int simulation_time = -1);
    template <typename Lambda1, typename Lambda2>
    void ContinuousMove(float x, float y, Lambda1&& condition, Lambda2&& collisionCallback, int simulation_time = -1);

  };
}

#include "components/movable.tcc"

#endif