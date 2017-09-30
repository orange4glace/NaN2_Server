//  ctf_module.h
//  Dependencies
//    TeamModule
#ifndef MODULE_CTF_MODULE_CTF_MODULE_H_
#define MODULE_CTF_MODULE_CTF_MODULE_H_

#include "../module.h"
#include "../team_module/team_module.h"
#include "../player_event_listener.h"

namespace nan2 {

namespace module {

namespace ctf_module {

class CTFModule : public Module<CTFModule> {
  friend class Module<CTFModule>;

protected:

public:
  CTFModule();

  inline static std::string GetName() {
    return "CTFModule";
  }

  void Initialize(const void* args ...) override;
  void Destroy() override;

};

}

}

}

#endif