// marshaler.h
#ifndef NAN2_MARSHALER_H_
#define NAN2_MARSHALER_H_

#include <ProudNetServer.h>

#include <nan2/math/vector2.h>

using namespace nan2;

namespace Proud {

inline CMessage& operator >> (CMessage &a, nan2::Vector2& vector) {
  float x, y;
  a >> x >> y;
  vector.set_x(x);
  vector.set_y(y);
  return a;
}

inline CMessage& operator << (CMessage &a, const nan2::Vector2& vector) {
  a << vector.x() << vector.y();
  return a;
}

inline void AppendTextOut(String &a, nan2::Vector2& vector) {
}

}

#endif