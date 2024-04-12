#pragma once

namespace TDG
{
  template<typename T>
  bool inList(const T) noexcept { return false; }
  
  template<typename T, typename... Args>
  bool inList(const T a, const T b, const Args... args) noexcept
  {
    if (a==b) return true;
    return inList(a,args...);
  }





}
