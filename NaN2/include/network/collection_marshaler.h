// collection_marshaler.h
// http://help.nettention.com/cpp/1.7.35013-master/collection_marshal.ndn/
#ifndef COLLECTION_MARSHALER_H_
#define COLLECTION_MARSHALER_H_

#include <ProudNetServer.h>

#include <stdint.h>

namespace Proud
{
  template<typename elem>
  inline CMessage& operator >> (CMessage &a, std::vector<elem> &b)
  {
    int size;
    a >> size;
    if (size<0 || size >= CNetConfig::MessageMaxLength)
      ThrowExceptionOnReadArray(size);
    b.reserve(size);
    b.resize(0);
    elem e;
    for (int i = 0; i < size; i++)
    {
      a >> e;
      b.push_back(e);
    }
    return a;
  }

  template<typename elem>
  inline CMessage& operator<<(CMessage &a, const std::vector<elem> &b)
  {
    int size = (int)b.size();
    a << size;
    for (typename std::vector<elem>::const_iterator i = b.begin(); i != b.end(); i++)
    {
      a << (*i);
    }
    return a;
  }
  template<typename elem>
  inline void AppendTextOut(String &a, std::vector<elem> &b)
  {
    // a += L"<vector>";
  }
}

#endif