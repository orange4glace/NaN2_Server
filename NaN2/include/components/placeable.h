// placeable.h
#ifndef PLACEABLE_H_
#define PLACEABLE_H_

#include "component.h"
#include "layer.h"

#include <nan2/math/vector2.h>
#include <nan2/math/aabb.h>

namespace nan2 {

  class Placeable : public Component {

  private:
    Vector2 position_;
    AABB aabb_;
    Vector2 offset_;
    int layermask_;
    int target_layermask_;

  public:
    Placeable(GameObject* go, const Vector2& position, const Vector2& size, const Vector2& offset = Vector2(0, 0));

    static ComponentType component_type();
    inline ComponentType type() const override {
      return ComponentType::Placeable;
    }

    void set_position(const Vector2& position);
    void set_position(float x, float y);
    const Vector2& position() const;

    void set_size(const Vector2& position);
    const Vector2& size() const;

    int layermask() const;
    int target_layermask() const;

    void AddLayer(int layer);
    void AddLayers(int layermask);
    bool HasLayer(int layer);
    bool HasLayers(int layermask);

    void AddTargetLayer(int layer);
    void AddTargetLayers(int layermask);
    bool HasTargetLayer(int layer);
    bool HasTargetLayers(int layermask);

    const AABB& aabb() const;
  };

}

#endif