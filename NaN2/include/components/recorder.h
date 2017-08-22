// Recorder.h
#ifndef RECORDER_H_
#define RECORDER_H_

#include "component.h"

#include <utility>
#include <vector>

namespace nan2 {

  template <class T>
  class Recorder : public Component {

  private:
    std::vector<std::pair<int, T>> data_;

  public:
    Recorder(GameObject* go);

    ComponentType type() const;
    void AddRecord(int time, T data);
    virtual T GetInterpolatedData(int time) = 0;

  };
}

#include "components/recorder.tcc"

#endif