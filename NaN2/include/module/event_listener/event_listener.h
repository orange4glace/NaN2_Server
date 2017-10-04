// event_listener.h
#ifndef MODULE_EVENT_LISTENER_H_
#define MODULE_EVENT_LISTENER_H_

#include <set>

namespace nan2 {

namespace module {

namespace event_listener {

enum Priority {
  LOWEST,
  LOWER,
  NORMAL,
  HIGHER,
  HIGHEST
};

template<class Derived>
struct ListenerComparator {
  bool operator() (const Derived* lhs, const Derived* rhs) const {
    if (lhs->priority_ == rhs->priority_) return lhs < rhs;
    return lhs->priority_ > rhs->priority_;
  }
};

template<class Derived>
class EventListener {
  friend struct ListenerComparator<Derived>;

protected:
  static std::set<Derived*, ListenerComparator<Derived>> listeners_;

  Priority priority_;

  EventListener() : EventListener(NORMAL) {
  }

  EventListener(Priority priority) {
    priority_ = priority;
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
std::set<Derived*, ListenerComparator<Derived>> EventListener<Derived>::listeners_ = {};

}

}

}

#endif