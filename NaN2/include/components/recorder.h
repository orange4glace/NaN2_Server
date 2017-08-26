// Recorder.h
#ifndef RECORDER_H_
#define RECORDER_H_

#include "recorder_interface.h"

#include <utility>
#include <vector>

namespace nan2 {

  template <class T>
  class Recorder : public RecorderInterface {

  private:
    std::vector<std::pair<int, T>> records_;
    T getInterpolatedData(int time);
    T current_record_;

  protected:
    virtual void applyRecord(const T& record) = 0;
    virtual const T saveCurrentRecord() const = 0;

  public:
    Recorder(GameObject* go);
    
    static ComponentType component_type();
    inline ComponentType type() const override {
      return ComponentType::Recorder;
    }

    void SaveCurrentRecord() override;
    void Rewind(int time) override;
    void Restore() override;

  };
}

#include "components/recorder.tcc"

#endif