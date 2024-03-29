// recorder_interface.h
#ifndef RECORDER_INTERFACE_H_
#define RECORDER_INTERFACE_H_

#include "component.h"

namespace nan2 {

  class RecorderInterface : public Component {

  protected:
    RecorderInterface(GameObject* go);

  public:
    inline static ComponentType component_type() {
      return ComponentType::Recorder;
    }
    inline ComponentType type() const override {
      return ComponentType::Recorder;
    }

    virtual void SaveCurrentRecord() = 0;
    virtual void Rewind(int time) = 0;
    virtual void Restore() = 0;

  };
}

#endif