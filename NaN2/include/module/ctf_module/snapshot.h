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

inline CMessage& operator >> (CMessage& a, nan2::module::ctf_module::Snapshot& packet) {
  return a;
}

inline CMessage& operator << (CMessage& a, const nan2::module::ctf_module::Snapshot& packet) {
  return a;
}

inline void AppendTextOut(String& str, const nan2::module::ctf_module::Snapshot& packet) {

}

}


#endif