// obtainable.h
#ifndef OBTAINABLE_H_
#define OBTAINABLE_H_

#include "component.h"

namespace nan2 {

  class Obtainable : public Component {

  private:

  public:
    Obtainable(GameObject* go);

    ComponentType type() const;

  };

}

#endif