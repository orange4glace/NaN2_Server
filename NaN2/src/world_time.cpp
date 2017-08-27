// world_time.cpp
#include "world_time.h"

#include "logger/logger.h"

namespace nan2 {

  float Time::delta_time_ = 0;
  int Time::idelta_time_ = 0;
  int Time::current_time_ = 0;
  int Time::fixed_delta_time_ = 0;
  int Time::current_fixed_time_ = 0;

  float Time::extra_delta_time_ = 0;

  void Time::delta_time(int mdt) {
    // dt += Time::extra_delta_time_;
    Time::delta_time_ = mdt / 1000.f;
    Time::idelta_time_ = mdt;
    // Time::extra_delta_time_ = 0;
  }
  int Time::delta_time() {
    return Time::idelta_time_;
  }
  float Time::f_delta_time() {
    return Time::delta_time_;
  }
  void Time::current_time(int t) {
    Time::current_time_ = t;
  }
  int Time::current_time() {
    return Time::current_time_;
  }
  void Time::fixed_delta_time(int t) {
    Time::fixed_delta_time_ = t;
  }
  int Time::fixed_delta_time() {
    return Time::fixed_delta_time_;
  }
  void Time::current_fixed_time(int t) {
    Time::current_fixed_time_ = t;
  }
  int Time::current_fixed_time() {
    return Time::current_fixed_time_;
  }
  
}
