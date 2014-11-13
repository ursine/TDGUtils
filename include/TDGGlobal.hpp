#pragma once

namespace TDG
{
  template<typename T>
  bool inList(T a) { return false; }
  
  template<typename T, typename... Args>
  bool inList(T a, T b, Args... args)
  {
    if (a==b) return true;
    return inList(a,args...);
  }





}
