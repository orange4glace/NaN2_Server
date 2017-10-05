// scheduler.h
#ifndef NAN2_SSCHEDULER_H_
#define NAN2_SSCHEDULER_H_

#include <queue>
#include <functional>

namespace nan2 {

struct SchedulerTask {
  int id;
  int time;
  int dtime;
  std::function<void()> functor;
  int repeat;

  SchedulerTask(int id, int dtime, int time, std::function<void()>& functor, int repeat) {
    this->id = id;
    this->dtime = dtime;
    this->time = time;
    this->functor = functor;
    this->repeat = repeat;
  }

  bool operator<(const SchedulerTask& rhs) const {
    if (rhs.time == rhs.time) return this < &rhs;
    return time < rhs.time;
  }
};

class Scheduler {

  std::priority_queue<SchedulerTask> tasks_;
  int next_task_id_;

public:
  Scheduler();

  int Timeout(int time, std::function<void()>&& functor);
  int Interval(int time, std::function<void()>&& functor, int repeat = 0);

  void Update(int time);

};

}

#endif