// vector2.cpp
#include "vector2.h"

#include <math.h>

#define E_PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062f

namespace nan2 {

  Vector2::Vector2() :
    x_(0),
    y_(0) {
  }

  Vector2::Vector2(float x, float y) :
    x_(x),
    y_(y) {
  }

  float Vector2::GetMagnitude() {
    return sqrt(x_ * x_ + y_ * y_);
  }

  Vector2 Vector2::operator+(const Vector2& v) const {
    return Vector2(x_ + v.x(), y_ + v.y());
  }

  Vector2 Vector2::operator-(const Vector2& v) const {
    return Vector2(x_ - v.x(), y_ - v.y());
  }

  Vector2 Vector2::operator*(float v) const {
    return Vector2(x_ * v, y_ * v);
  }

  Vector2 Vector2::operator/(float v) const {
    return Vector2(x_ / v, y_ / v);
  }

  Vector2& Vector2::operator+=(const Vector2& v) {
    x_ += v.x(); y_ += v.y();
    return *this;
  }

  Vector2& Vector2::operator-=(const Vector2& v) {
    x_ -= v.x(); y_ -= v.y();
    return *this;
  }

  Vector2& Vector2::operator*=(float v) {
    x_ *= v; y_ *= v;
    return *this;
  }

  Vector2& Vector2::operator/=(float v) {
    x_ /= v; y_ /= v;
    return *this;
  }

  Vector2& Vector2::operator=(const Vector2& v) {
    if (&v == this) return *this;
    x_ = v.x();
    y_ = v.y();
    return *this;
  }

  const float Vector2::x() const {
    return x_;
  }

  const float Vector2::y() const {
    return y_;
  }

  Vector2& Vector2::set_x(float x) {
    x_ = x;
    return *this;
  }

  Vector2& Vector2::set_y(float y) {
    y_ = y;
    return *this;
  }

  float Vector2::cross(const Vector2& vec) const {
    return x_ * vec.y() - y_ * vec.x();
  }

  // Static member
  const Vector2 Vector2::ZERO = Vector2(0, 0);

  // Static function
  Vector2 Vector2::FromAngle(float angle) {
    float rad = E_PI / 180 * angle;
    return Vector2(cos(rad), sin(rad));
  }

  std::ostream& operator<<(std::ostream& os, const Vector2& v) {
      os << "Vector2(" << v.x_ << ", " << v.y_ << ") ";
      return os;
  }
}