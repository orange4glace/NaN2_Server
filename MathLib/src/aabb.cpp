// aabb.cpp
#include "aabb.h"

#include <iostream>

namespace nan2 {

  AABB::AABB(float x, float y, float w, float h) :
    center_(x, y),
    size_(w, h) {
  }
  AABB::AABB(const Vector2& center, const Vector2& size) :
    center_(center),
    size_(size) {
  }
  
  AABB& AABB::operator=(const AABB& r) {
    if (this == &r) return *this;
    center_ = r.center();
    size_ = r.size();
    return *this;
  }

  const Vector2& AABB::center() const {
    return center_;
  }
  const Vector2& AABB::size() const {
    return size_;
  }

  AABB& AABB::set_center(const Vector2& v) {
    center_ = v;
    return *this;
  }
  
  AABB& AABB::set_size(const Vector2& v) {
    size_ = v;
    return *this;
  }

  bool AABB::ContainsPoint(const Vector2& p) const {
        Vector2 b_ll = center_ - size_ / 2;
        Vector2 b_ur = center_ + size_ / 2;
        if (b_ll.x() <= p.x() &&
            b_ur.x() >= p.x() &&
            b_ll.y() <= p.y() &&
            b_ur.y() >= p.y()) return true;
        return false;
  }
    
  AABB AABB::MinkowskiDifference(const AABB& r) const {
      Vector2 a_ll = center_ - size_ / 2;
      Vector2 b_ur = r.center() + r.size() / 2;
      Vector2 c_ll = a_ll - b_ur;
      Vector2 c_size = size_ + r.size();
      return AABB(c_ll + c_size / 2, c_size);
  }

  Vector2 AABB::ClosestPointOnBoundsToPoint(const Vector2& p) const {
      Vector2 b_ll = center_ - size_ / 2;
      Vector2 b_ur = center_ + size_ / 2;
      float minDist = std::abs(p.x() - b_ll.x());
      Vector2 ret(b_ll.x(), p.y());
      if (std::abs(b_ur.x() - p.x()) < minDist) {
          minDist = std::abs(b_ur.x() - p.x());
          ret.set_x(b_ur.x());
          ret.set_y(p.y());
      }
      if (std::abs(b_ur.y() - p.y()) < minDist) {
          minDist = std::abs(b_ur.y() - p.y());
          ret.set_x(p.x());
          ret.set_y(b_ur.y());
      }
      if (std::abs(b_ll.y() - p.y()) < minDist) {
          minDist = std::abs(b_ll.y() - p.y());
          ret.set_x(p.x());
          ret.set_y(b_ll.y());
      }
      return ret;
  }

  float AABB::SweptAABB(const AABB& src, const Vector2& srcDelta, const AABB& tar, const Vector2& tarDelta, bool& out_collided) {
    out_collided = false;
    AABB minkowski = tar.MinkowskiDifference(src);
    Vector2 relative_delta = srcDelta - tarDelta;

    float h = AABB::GetRayIntersectionFraction(minkowski, Vector2::ZERO, relative_delta);
    if (h < INFINITY) {
      out_collided = true;
      return h;
    }
    else return 1;
  }

  Vector2 AABB::SimpleAABB(const AABB& src, const AABB& tar, bool& out_collided) {
    AABB minkowski = tar.MinkowskiDifference(src);
    if (!minkowski.ContainsPoint(Vector2::ZERO)) {
      out_collided = false;
      return Vector2::ZERO;
    }
    out_collided = true;
    return minkowski.ClosestPointOnBoundsToPoint(Vector2::ZERO);
  }

  float AABB::GetRayIntersectionFractionOfFirstRay(const Vector2& oA, const Vector2& eA, const Vector2& oB, const Vector2& eB) {
    Vector2 r = eA - oA;
    Vector2 s = eB - oB;
    Vector2 oAoB = oB - oA;

    float numerator = oAoB.cross(r);
    float denominator = r.cross(s);

    if (numerator == 0 && denominator == 0) {
      // Colinear
      return INFINITY;
    }
    if (denominator == 0) {
      // parallel
      return INFINITY;
    }

    float u = numerator / denominator;
    float t = oAoB.cross(s) / denominator;

    if ((t >= 0) && (t <= 1) && (u >= 0) && (u <= 1)) return t;
    return INFINITY;
  }

  float AABB::GetRayIntersectionFraction(const AABB& b, const Vector2& o, const Vector2& dir) {
    Vector2 e = o + dir;
    Vector2 b_ll = b.center() - b.size() / 2;
    Vector2 b_ur = b.center() + b.size() / 2;

    float minv = AABB::GetRayIntersectionFractionOfFirstRay(o, e, Vector2(b_ll.x(), b_ll.y()), Vector2(b_ll.x(), b_ur.y()));
    float x;
    x = AABB::GetRayIntersectionFractionOfFirstRay(o, e, Vector2(b_ll.x(), b_ur.y()), Vector2(b_ur.x(), b_ur.y()));
    if (x < minv) minv = x;
    x = AABB::GetRayIntersectionFractionOfFirstRay(o, e, Vector2(b_ur.x(), b_ur.y()), Vector2(b_ur.x(), b_ll.y()));
    if (x < minv) minv = x;
    x = AABB::GetRayIntersectionFractionOfFirstRay(o, e, Vector2(b_ur.x(), b_ll.y()), Vector2(b_ll.x(), b_ll.y()));
    if (x < minv) minv = x;
    return minv;
  }

  std::ostream& operator<<(std::ostream& os, const AABB& r) {
      os << "[AABB] " << r.center_ << " " << r.size_;
      return os;
  }
}