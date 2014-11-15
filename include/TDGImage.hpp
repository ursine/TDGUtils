#pragma once

#include <valarray>

namespace TDG {
  /*
  template<typename T>
  class working_buffer {

  private:
    size_t width;
    size_t height;
    std::valarray<T> buf;
  };
  
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
