#pragma once

namespace TDG
{
  template<typename T>
  const bool inList(T a) noexcept { return false; }
  
  template<typename T, typename... Args>
  const bool inList(T a, T b, Args... args) noexcept
  {
    if (a==b) return true;
    return inList(a,args...);
  }





}
