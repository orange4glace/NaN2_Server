// scheduler.cpp
#include "world/scheduler.h"

#include "world_time.h"

#include "logger/logger.h"

namespace nan2 {

Scheduler::Scheduler() : next_task_id_(0) {}

int Scheduler::Timeout(int time, std::function<void()>&& functor) {
  int task_id = next_task_id_++;
  int dtime = Time::current_time() + time;
  tasks_.emplace(SchedulerTask(task_id, dtime, time, functor, 1));
  return task_id;
}

int Scheduler::Interval(int time, std::function<void()>&& functor, int repeat) {
  int task_id = next_task_id_++;
  int dtime = Time::current_time() + time;
  tasks_.emplace(SchedulerTask(task_id, dtime, time, functor, repeat));
  return task_id;
}

void Scheduler::Update(int time) {
  int siz = tasks_.size();
  int cnt = 0;
  while (cnt != siz) {
    auto task = tasks_.top();
    if (task.dtime <= time) {
      tasks_.pop();
      cnt++;
      task.functor();
      if (task.repeat != 1) {
        task.repeat--;
        if (task.repeat == -1) task.repeat = 0;
        task.dtime = Time::current_time() + task.time;
        tasks_.emplace(task);
      }
    }
    else break;
  }
}

}