// math_helper.cpp
#include "math_helper.h"

#include "logger/logger.h"
#include <cmath>

#define PI 3.14159265f

namespace nan2 {

  MathHelper* MathHelper::instance_;

  MathHelper::MathHelper() {}
  
  const MathHelper& MathHelper::instance() {
    if (instance_ == nullptr) {
      instance_ = new MathHelper();

      float x252[252] = {1.0f,0.99969f,0.99876f,0.9972f,0.99503f,0.99224f,0.98883f,0.98481f,0.98017f,0.97493f,0.96908f,0.96262f,0.95557f,0.94793f,0.93969f,0.93087f,0.92148f,0.91151f,0.90097f,0.88987f,0.87822f,0.86603f,0.85329f,0.84003f,0.82624f,0.81194f,0.79713f,0.78183f,0.76604f,0.74978f,0.73305f,0.71587f,0.69824f,0.68017f,0.66169f,0.64279f,0.62349f,0.6038f,0.58374f,0.56332f,0.54255f,0.52144f,0.5f,0.47825f,0.45621f,0.43388f,0.41129f,0.38843f,0.36534f,0.34202f,0.31849f,0.29476f,0.27084f,0.24676f,0.22252f,0.19815f,0.17365f,0.14904f,0.12434f,0.09957f,0.07473f,0.04985f,0.02493f,0.0f,-0.02493f,-0.04985f,-0.07473f,-0.09957f,-0.12434f,-0.14904f,-0.17365f,-0.19815f,-0.22252f,-0.24676f,-0.27084f,-0.29476f,-0.31849f,-0.34202f,-0.36534f,-0.38843f,-0.41129f,-0.43388f,-0.45621f,-0.47825f,-0.5f,-0.52144f,-0.54255f,-0.56332f,-0.58374f,-0.6038f,-0.62349f,-0.64279f,-0.66169f,-0.68017f,-0.69824f,-0.71587f,-0.73305f,-0.74978f,-0.76604f,-0.78183f,-0.79713f,-0.81194f,-0.82624f,-0.84003f,-0.85329f,-0.86603f,-0.87822f,-0.88987f,-0.90097f,-0.91151f,-0.92148f,-0.93087f,-0.93969f,-0.94793f,-0.95557f,-0.96262f,-0.96908f,-0.97493f,-0.98017f,-0.98481f,-0.98883f,-0.99224f,-0.99503f,-0.9972f,-0.99876f,-0.99969f,-1.0f,-0.99969f,-0.99876f,-0.9972f,-0.99503f,-0.99224f,-0.98883f,-0.98481f,-0.98017f,-0.97493f,-0.96908f,-0.96262f,-0.95557f,-0.94793f,-0.93969f,-0.93087f,-0.92148f,-0.91151f,-0.90097f,-0.88987f,-0.87822f,-0.86603f,-0.85329f,-0.84003f,-0.82624f,-0.81194f,-0.79713f,-0.78183f,-0.76604f,-0.74978f,-0.73305f,-0.71587f,-0.69824f,-0.68017f,-0.66169f,-0.64279f,-0.62349f,-0.6038f,-0.58374f,-0.56332f,-0.54255f,-0.52144f,-0.5f,-0.47825f,-0.45621f,-0.43388f,-0.41129f,-0.38843f,-0.36534f,-0.34202f,-0.31849f,-0.29476f,-0.27084f,-0.24676f,-0.22252f,-0.19815f,-0.17365f,-0.14904f,-0.12434f,-0.09957f,-0.07473f,-0.04985f,-0.02493f,0.0f,0.02493f,0.04985f,0.07473f,0.09957f,0.12434f,0.14904f,0.17365f,0.19815f,0.22252f,0.24676f,0.27084f,0.29476f,0.31849f,0.34202f,0.36534f,0.38843f,0.41129f,0.43388f,0.45621f,0.47825f,0.5f,0.52144f,0.54255f,0.56332f,0.58374f,0.6038f,0.62349f,0.64279f,0.66169f,0.68017f,0.69824f,0.71587f,0.73305f,0.74978f,0.76604f,0.78183f,0.79713f,0.81194f,0.82624f,0.84003f,0.85329f,0.86603f,0.87822f,0.88987f,0.90097f,0.91151f,0.92148f,0.93087f,0.93969f,0.94793f,0.95557f,0.96262f,0.96908f,0.97493f,0.98017f,0.98481f,0.98883f,0.99224f,0.99503f,0.9972f,0.99876f,0.99969f};
      float y252[252] = {0.0f,0.02493f,0.04985f,0.07473f,0.09957f,0.12434f,0.14904f,0.17365f,0.19815f,0.22252f,0.24676f,0.27084f,0.29476f,0.31849f,0.34202f,0.36534f,0.38843f,0.41129f,0.43388f,0.45621f,0.47825f,0.5f,0.52144f,0.54255f,0.56332f,0.58374f,0.6038f,0.62349f,0.64279f,0.66169f,0.68017f,0.69824f,0.71587f,0.73305f,0.74978f,0.76604f,0.78183f,0.79713f,0.81194f,0.82624f,0.84003f,0.85329f,0.86603f,0.87822f,0.88987f,0.90097f,0.91151f,0.92148f,0.93087f,0.93969f,0.94793f,0.95557f,0.96262f,0.96908f,0.97493f,0.98017f,0.98481f,0.98883f,0.99224f,0.99503f,0.9972f,0.99876f,0.99969f,1.0f,0.99969f,0.99876f,0.9972f,0.99503f,0.99224f,0.98883f,0.98481f,0.98017f,0.97493f,0.96908f,0.96262f,0.95557f,0.94793f,0.93969f,0.93087f,0.92148f,0.91151f,0.90097f,0.88987f,0.87822f,0.86603f,0.85329f,0.84003f,0.82624f,0.81194f,0.79713f,0.78183f,0.76604f,0.74978f,0.73305f,0.71587f,0.69824f,0.68017f,0.66169f,0.64279f,0.62349f,0.6038f,0.58374f,0.56332f,0.54255f,0.52144f,0.5f,0.47825f,0.45621f,0.43388f,0.41129f,0.38843f,0.36534f,0.34202f,0.31849f,0.29476f,0.27084f,0.24676f,0.22252f,0.19815f,0.17365f,0.14904f,0.12434f,0.09957f,0.07473f,0.04985f,0.02493f,0.0f,-0.02493f,-0.04985f,-0.07473f,-0.09957f,-0.12434f,-0.14904f,-0.17365f,-0.19815f,-0.22252f,-0.24676f,-0.27084f,-0.29476f,-0.31849f,-0.34202f,-0.36534f,-0.38843f,-0.41129f,-0.43388f,-0.45621f,-0.47825f,-0.5f,-0.52144f,-0.54255f,-0.56332f,-0.58374f,-0.6038f,-0.62349f,-0.64279f,-0.66169f,-0.68017f,-0.69824f,-0.71587f,-0.73305f,-0.74978f,-0.76604f,-0.78183f,-0.79713f,-0.81194f,-0.82624f,-0.84003f,-0.85329f,-0.86603f,-0.87822f,-0.88987f,-0.90097f,-0.91151f,-0.92148f,-0.93087f,-0.93969f,-0.94793f,-0.95557f,-0.96262f,-0.96908f,-0.97493f,-0.98017f,-0.98481f,-0.98883f,-0.99224f,-0.99503f,-0.9972f,-0.99876f,-0.99969f,-1.0f,-0.99969f,-0.99876f,-0.9972f,-0.99503f,-0.99224f,-0.98883f,-0.98481f,-0.98017f,-0.97493f,-0.96908f,-0.96262f,-0.95557f,-0.94793f,-0.93969f,-0.93087f,-0.92148f,-0.91151f,-0.90097f,-0.88987f,-0.87822f,-0.86603f,-0.85329f,-0.84003f,-0.82624f,-0.81194f,-0.79713f,-0.78183f,-0.76604f,-0.74978f,-0.73305f,-0.71587f,-0.69824f,-0.68017f,-0.66169f,-0.64279f,-0.62349f,-0.6038f,-0.58374f,-0.56332f,-0.54255f,-0.52144f,-0.5f,-0.47825f,-0.45621f,-0.43388f,-0.41129f,-0.38843f,-0.36534f,-0.34202f,-0.31849f,-0.29476f,-0.27084f,-0.24676f,-0.22252f,-0.19815f,-0.17365f,-0.14904f,-0.12434f,-0.09957f,-0.07473f,-0.04985f,-0.02493f};
      float angle = 0;
      float dangle = 360 / 252.0f;
      for (int i = 0; i < 252; i ++) {
        Vector2 nv(x252[i], y252[i]);
        (*instance_).vec_normal_252_[i] = nv;
        angle += dangle;
      }
    }
    return *instance_;
  }

  const Vector2& MathHelper::normal_dir_252(int x) const {
    assert(x >= 0 && x < 256);
    if (x >= 252) return Vector2::ZERO;
    return vec_normal_252_[x];
  }

  float MathHelper::normal_angle_252(int x) const {
    assert(x >= 0 && x < 256);
    return normal_angle_252_[x];
  }

  int MathHelper::is_right_direction(int x) const {
    assert(x >= 0 && x < 256);
    return biased_direction(x) == x ? 1 : -1;
  }

  bool MathHelper::is_upper_direction(int x) const {
    assert(x >= 0 && x < 256);
    auto bdir = biased_direction(x);
    return (bdir >= 190 && bdir < 252) ? false : true;
  }

  int MathHelper::biased_direction(int x) const {
    assert(x >= 0 && x < 256);
    if (x > 63 && x <= 189) {
      return biased_direction_map_[x - 64];
    }
    else {
      return x;
    }
  }

  Vector2 MathHelper::RotateVector252(const Vector2& vec, int x) const {
    assert(x >= 0 && x < 256);
    float cos_ = cos252_[x];
    float sin_ = sin252_[x];
    return Vector2(vec.x() * cos_ - vec.y() * sin_, vec.x() * sin_ + vec.y() * cos_);
  }

  Vector2 MathHelper::RotateVector2(const Vector2& vec, float rad) const {
    float cos_ = cos(rad);
    float sin_ = sin(rad);
    return Vector2(vec.x() * cos_ - vec.y() * sin_,
                   vec.x() * sin_ + vec.y() * cos_);
  }

  float MathHelper::DegToRad(float deg) const {
    return deg / 180 * PI;
  }

}