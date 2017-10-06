// scheduler.cpp
#include "world/scheduler.h"

#include "world_time.h"

#include "logger/logger.h"

namespace nan2 {

Scheduler::Scheduler() : next_task_id_(0) {}

int Scheduler::Timeout(int time, std::function<void()>&& functor, void* owner) {
  int task_id = next_task_id_++;
  int dtime = Time::current_time() + time;
  tasks_.emplace(SchedulerTask(owner, task_id, dtime, time, functor, 1));
  owner_map_[owner].insert(task_id);
  return task_id;
}

int Scheduler::Interval(int time, std::function<void()>&& functor, void* owner, int repeat) {
  int task_id = next_task_id_++;
  int dtime = Time::current_time() + time;
  tasks_.emplace(SchedulerTask(owner, task_id, dtime, time, functor, repeat));
  owner_map_[owner].insert(task_id);
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
      if (removes_.count(task.id)) continue;
      assert(owner_map_[task.owner].count(task.id));
      task.functor();
      if (task.repeat != 1) {
        task.repeat--;
        if (task.repeat == -1) task.repeat = 0;
        task.dtime = Time::current_time() + task.time;
        tasks_.emplace(task);
      }
      else owner_map_.at(task.owner).erase(task.id);
    }
    else break;
  }
}

void Scheduler::RemoveSchedule(int id) {
  removes_.insert(id);
}

void Scheduler::RemoveSchedule(void* owner) {
  auto& ids = owner_map_.at(owner);
  for (auto id : ids) removes_.insert(id);
  owner_map_.erase(owner);
}

}