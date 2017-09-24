// Recorder.tcc

#include "world_time.h"

#include "logger/logger.h"

namespace nan2 {

  template <class T>
  Recorder<T>::Recorder(GameObject* game_object) :
  RecorderInterface(game_object) {
  }

  template <class T>
  ComponentType Recorder<T>::component_type() {
    return ComponentType::Recorder;
  }

  template <class T>
  T Recorder<T>::getInterpolatedData(int time) {
    if (records_.size() == 0) return T();
    int st = 0, ed = records_.size() - 1;
    int mid;
    while (st <= ed) {
      mid = (st + ed) / 2;
      auto& pair = records_[mid];
      if (pair.first < time)
        st = mid + 1;
      else if (pair.first > time)
        ed = mid - 1;
      else
        return pair.second;
    }
    std::pair<int, T>& record_pair = records_.at(mid);
    while (record_pair.first > time && mid > 0)
      record_pair = records_[--mid];
    if (record_pair.first > time || mid == records_.size() - 1) {
      return record_pair.second;
    }
    auto& next_record_pair = records_[mid + 1];
    if (next_record_pair.first == record_pair.first) return record_pair.second;
    float t = (float)(next_record_pair.first - time) / (next_record_pair.first - record_pair.first);
    return T::Interpolate(record_pair.second, next_record_pair.second, t);
  }

  template <class T>
  void Recorder<T>::SaveCurrentRecord() {
    records_.emplace_back(std::pair<int, T>{ Time::current_time(), saveCurrentRecord() });
  }

  template <class T>
  void Recorder<T>::Rewind(int time) {
    L_DEBUG << "Rewind " << time;
    current_record_ = saveCurrentRecord();
    auto data = getInterpolatedData(time);
    applyRecord(data);
  }

  template <class T>
  void Recorder<T>::Restore() {
    applyRecord(current_record_);
  }

}