// module.h
#ifndef MODULE_MODULE_H_
#define MODULE_MODULE_H_

#include "module_base.h"

#include "../logger/logger.h"

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

public:
  inline static Derived* Activate(void* args...) {
    module_ = new Derived();
#ifdef _DEBUG
    if (module_ == nullptr)
      throw std::string("Access to unactivated mod. " + Derived::GetName());
    L_DEBUG << "Module " << Derived::GetName() << " Activated.";
#endif
    module_->Initialize(args);
#ifdef _DEBUG
    L_DEBUG << "Module " << Derived::GetName() << " Initialized.";
#endif
    return module_;
  }

  inline static void Deactivate() {
    module_->Destroy();
#ifdef _DEBUG
    if (module_ != nullptr)
      throw std::string("Access to unactivated mod. " + Derived::GetName());
    L_DEBUG << "Module " << Derived::GetName() << " Deactivated.";
#endif
    delete module_;
  }

  inline static std::string GetName() {
    return Derived::GetName();
  }

  inline static Derived* const GetModule() {
#ifdef _DEBUG
    if (module_ == nullptr) {
      throw std::string("Access to unactivated mod. " + Derived::GetName());
    }
#endif
    return module_;
  }

  virtual void Initialize(const void* args ...) = 0;
  virtual void Destroy() = 0;

};

template<class Derived>
Derived* Module<Derived>::module_ = nullptr;

}

}

#endif