// module.h
#ifndef MODULE_MODULE_H_
#define MODULE_MODULE_H_

#include "module_base.h"

#include <string>

namespace nan2 {

namespace module {

template<class Derived>
class Module : public ModuleBase {

protected:
  static Derived* module_;

  Module() {
  }

  inline std::string name() {
    return Derived::GetName();
  }

  virtual void initialize() = 0;
  virtual void destroy() = 0;

public:
  inline static Derived* Activate() {
    module_ = new Derived();
    module_->initialize();
    return module_;
  }

  inline static void Deactivate() {
    module_->destroy();
    delete module_;
  }

  inline static std::string GetName() {
    return Derived::GetName();
  }

  inline static Derived* const GetModule() {
    return module_;
  }

};

}

}

#endif