// snapshot.h
#ifndef MODULE_CTF_MODULE_SNAPSHOT_H_
#define MODULE_CTF_MODULE_SNAPSHOT_H_

#include <ProudNetServer.h>

namespace nan2 {

namespace module {

namespace ctf_module {

struct Snapshot {

};

}

}

}

namespace Proud {
using namespace nan2::module::ctf_module;

inline CMessage& operator >> (CMessage& a, Snapshot& packet) {
  return a;
}

inline CMessage& operator << (CMessage& a, const Snapshot& packet) {
  return a;
}

inline void AppendTextOut(String& str, const Snapshot& packet) {

}

}


#endif