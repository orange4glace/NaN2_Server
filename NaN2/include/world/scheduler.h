// scheduler.h
#ifndef NAN2_SSCHEDULER_H_
#define NAN2_SSCHEDULER_H_

#include <queue>
#include <set>
#include <map>
#include <functional>

namespace nan2 {

struct SchedulerTask {
  void* owner;
  int id;
  int time;
  int dtime;
  std::function<void()> functor;
  int repeat;

  SchedulerTask(void* owner, int id, int dtime, int time, std::function<void()>& functor, int repeat) {
    this->owner = owner;
    this->id = id;
    this->dtime = dtime;
    this->time = time;
    this->functor = functor;
    this->repeat = repeat;
  }

  bool operator<(const SchedulerTask& rhs) const {
    return dtime > rhs.dtime;
  }
};

class Scheduler {

  std::set<int> removes_;
  std::map<void*, std::set<int> > owner_map_;
  std::priority_queue<SchedulerTask> tasks_;
  int next_task_id_;

public:
  Scheduler();

  int Timeout(int time, std::function<void()>&& functor, void* owner = nullptr);
  int Interval(int time, std::function<void()>&& functor, void* owner = nullptr, int repeat = 0);

  void RemoveSchedule(int id);
  void RemoveSchedule(void* owner);

  void Update(int time);

};

}

#endif