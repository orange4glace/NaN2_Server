// rect.h
#ifndef RECT_H
#define RECT_H

#include "vector2.h"

namespace nan2 {

  class Rect {

  private:

    Vector2 center_;
    Vector2 size_;


  public:

    Rect(float x, float y, float w, float h);
    Rect(const Vector2& center, const Vector2& size);

    Rect& operator=(const Rect& v);

    const Vector2& center() const;
    const Vector2& size() const;
    Rect& set_center(const Vector2& v);
    Rect& set_size(const Vector2& v);

    // Check contains the given point
    bool ContainsPoint(const Vector2 &point) const;

    // Get minkowski Difference rectangle
    Rect MinkowskiDifference(const Rect &rect) const;

    // Get closest point from the given point
    Vector2 ClosestPointOnBoundsToPoint(const Vector2& point) const;

    friend std::ostream& operator<<(std::ostream& os, const Rect& v);

  };

};

#endif