// world_time.h
#ifndef WORLD_TIME_H
#define WORLD_TIME_H

namespace nan2 {

  class Time {

  private:

    Time() {}

    // times will be updated every first of the update by World object.
    static float delta_time_;
    static int idelta_time_;
    static int current_time_;
    static int fixed_delta_time_;
    static int current_fixed_time_;
    static float extra_delta_time_;

  public:

    static void delta_time(float dt);
    static int delta_time();
    static void current_time(int t);
    static int current_time();
    static void fixed_delta_time(int t);
    static int fixed_delta_time();
    static void current_fixed_time(int t);
    static int current_fixed_time();

  };

};

#endif
