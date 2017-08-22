// vector2.h
#ifndef VECTOR2_H
#define VECTOR2_H

#include <iostream>

namespace nan2 {

  class Vector2 {

  private:
    float x_, y_;

  public:

    Vector2();
    Vector2(float x, float y);
    float GetMagnitude();

    Vector2 operator+(const Vector2& v) const;
    Vector2 operator-(const Vector2& v) const;
    Vector2 operator*(float v) const;
    Vector2 operator/(float v) const;
    Vector2& operator+=(const Vector2& v);
    Vector2& operator-=(const Vector2& v);
    Vector2& operator*=(float v);
    Vector2& operator/=(float v);
    Vector2& operator=(const Vector2& v);

    float cross(const Vector2& vec) const;

    const float x() const;
    const float y() const;
    Vector2& set_x(float x);
    Vector2& set_y(float y);

    friend std::ostream& operator<<(std::ostream& os, const Vector2& v);

    static const Vector2 ZERO;
    static Vector2 FromAngle(float angle);

  };

};

#endif