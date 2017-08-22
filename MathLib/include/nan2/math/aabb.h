// aabb.h
#ifndef AABB_H
#define AABB_H

#include "vector2.h"

#include <math.h>

namespace nan2 {

  class AABB {

  private:

    Vector2 center_;
    Vector2 size_;

    static float GetRayIntersectionFractionOfFirstRay(const Vector2& oA, const Vector2& eA, const Vector2& oB, const Vector2& eB);
    static float GetRayIntersectionFraction(const AABB& b, const Vector2& o, const Vector2& dir);

  public:

    AABB(float x, float y, float w, float h);
    AABB(const Vector2& center, const Vector2& size);

    AABB& operator=(const AABB& r);

    const Vector2& center() const;
    const Vector2& size() const;
    AABB& set_center(const Vector2& v);
    AABB& set_size(const Vector2& v);

    // Check contains the given point
    bool ContainsPoint(const Vector2 &point) const;

    // Get minkowski Difference AABBangle
    AABB MinkowskiDifference(const AABB &AABB) const;

    // Get closest point from the given point
    Vector2 ClosestPointOnBoundsToPoint(const Vector2& point) const;

    // Swept AABB collision detection for fast objects.
    static float SweptAABB(const AABB& r1, const Vector2& r1v, const AABB& r2, const Vector2& r2v, bool& out_collided);
    
    // Simple AABB collsion detection for regular speed objects.
    static Vector2 SimpleAABB(const AABB& r1, const AABB& r2, bool& out_collided);

    friend std::ostream& operator<<(std::ostream& os, const AABB& v);

  };

};

#endif