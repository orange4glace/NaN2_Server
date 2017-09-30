// event_listener.h
#ifndef MODULE_EVENT_LISTENER_H_
#define MODULE_EVENT_LISTENER_H_

#include <set>

namespace nan2 {

namespace module {

namespace event_listener {

using EventListenerType = int;

template<class Derived>
class EventListener {

protected:
  static std::set<Derived*> listeners_;

  EventListener() {
    auto derived = static_cast<Derived*>(this);
    listeners_.insert(derived);
  }

  ~EventListener() {
    auto derived = static_cast<Derived*>(this);
    listeners_.erase(derived);
  }

public:

};

template<class Derived>
std::set<Derived*> EventListener<Derived>::listeners_ = {};

}

}

}

#endif