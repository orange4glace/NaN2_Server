// CharacterBase.cpp
#include "rect.h"

#include <cstdlib>

namespace nan2 {

  Rect::Rect(float x, float y, float w, float h) :
    center_(x, y),
    size_(w, h) {
  }
  Rect::Rect(const Vector2& center, const Vector2& size) :
    center_(center),
    size_(size) {
  }
  
  Rect& Rect::operator=(const Rect& r) {
    if (this == &r) return *this;
    center_ = r.center();
    size_ = r.size();
    return *this;
  }

  const Vector2& Rect::center() const {
    return center_;
  }
  const Vector2& Rect::size() const {
    return size_;
  }
  Rect& Rect::set_center(const Vector2& v) {
    center_ = v;
    return *this;
  }
  Rect& Rect::set_size(const Vector2& v) {
    size_ = v;
    return *this;
  }

  bool Rect::ContainsPoint(const Vector2& p) const {
        Vector2 b_ll = center_ - size_ / 2;
        Vector2 b_ur = center_ + size_ / 2;
        if (b_ll.x() <= p.x() &&
            b_ur.x() >= p.x() &&
            b_ll.y() <= p.y() &&
            b_ur.y() >= p.y()) return true;
        return false;
  }
    
  Rect Rect::MinkowskiDifference(const Rect& r) const {
      Vector2 a_ll = center_ - size_ / 2;
      Vector2 b_ur = r.center() + r.size() / 2;
      Vector2 c_ll = a_ll - b_ur;
      Vector2 c_size = size_ + r.size();
      return Rect(c_ll + c_size / 2, c_size);
  }

  Vector2 Rect::ClosestPointOnBoundsToPoint(const Vector2& p) const {
      Vector2 b_ll = center_ - size_ / 2;
      Vector2 b_ur = center_ + size_ / 2;
      float minDist = abs(p.x() - b_ll.x());
      Vector2 ret(b_ll.x(), p.y());
      if (abs(b_ur.x() - p.x()) < minDist) {
          minDist = abs(b_ur.x() - p.x());
          ret.set_x(b_ur.x());
          ret.set_y(p.y());
      }
      if (abs(b_ur.y() - p.y()) < minDist) {
          minDist = abs(b_ur.y() - p.y());
          ret.set_x(p.x());
          ret.set_y(b_ur.y());
      }
      if (abs(b_ll.y() - p.y()) < minDist) {
          minDist = abs(b_ll.y() - p.y());
          ret.set_x(p.x());
          ret.set_y(b_ll.y());
      }
      return ret;
  }

  std::ostream& operator<<(std::ostream& os, const Rect& r) {
      os << "[Rect] " << r.center_ << " " << r.size_;
      return os;
  }
}