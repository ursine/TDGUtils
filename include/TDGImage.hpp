#pragma once

#include <stdint.h>
#include "TDGGlobal.hpp"
#include <valarray>

namespace TDG {

  class Point
  {
  private:
    uintmax_t x;
    uintmax_t y;
  };
  
  class Shape
  {
    virtual bool is_inside(Point p) = 0;
  };
  
  class Rect
  {
  private:
    uintmax_t x;
    uintmax_t y;
    intmax_t  width;
    intmax_t  height;
  };

  
  template<typename T>
  class working_buffer
  {
  public:
    
    using value_type = T;
    using buffer_type = std::valarray<T>;

    working_buffer() : 
      width(0), height(0), stride(0), buf() {}

  private:
    uintmax_t   width;
    uintmax_t   height;
    intmax_t    stride;
    buffer_type buf;
  };

  /*
  class PPMImage {

bool write_ppm(const unsigned char* buf, 
               unsigned width, 
               unsigned height, 
               const char* file_name)
{
    FILE* fd = fopen(file_name, "wb");
    if(fd)
    {
        fprintf(fd, "P6 %d %d 255 ", width, height);
        fwrite(buf, 1, width * height * 3, fd);
        fclose(fd);
        return true;
    }
    return false;
}

  };
  */

}
