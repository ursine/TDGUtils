#pragma once

namespace TDG
{
  template<typename T>
  bool inList(T) noexcept { return false; }
  
  template<typename T, typename... Args>
  bool inList(T a, T b, Args... args) noexcept
  {
    if (a==b) return true;
    return inList(a,args...);
  }





}
