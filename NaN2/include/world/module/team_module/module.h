// module.h
#ifndef WORLD_MODULE_TEAM_MODULE_MODULE_H_
#define WORLD_MODULE_TEAM_MODULE_MODULE_H_

#include "../module.h"

#include "team.h"

#include <vector>

namespace nan2 {

namespace world_module {

namespace team_module {

class Module : public ::nan2::world_module::Module {

  std::vector<Team> teams_;

};

}

}

}

#endif