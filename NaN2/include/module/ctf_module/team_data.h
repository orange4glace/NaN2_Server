// team_info.h
#ifndef MODULE_CTF_MODULE_TEAM_INFO_H_
#define MODULE_CTF_MODULE_TEAM_INFO_H_

#include "gameobject/flag.h"

#include <nan2/math/vector2.h>

namespace nan2 {

namespace module {

namespace ctf_module {

struct TeamData {

  int team_id;
  Vector2 base_point;
  Flag* flag;

};

}

}

}


#endif