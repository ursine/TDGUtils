#include <valarray>
#include <string>
#include <stdint.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "lcms2.h"

class Image
{
public:
  using csize = uint8_t;
  constexpr static size_t bsize = sizeof(csize) * 3;
  
  Image() :
    Image(320,200) {}

  Image(const uintmax_t w, const uintmax_t h) :
    image(w * h * bsize),
    _byteWidth(w * bsize),
    _width(w),
    _height(h) {}
   
  ~Image() {}

  void writeppm(const std::string filename)
  {
    std::ofstream tfile;
    tfile.open(filename, std::ios::out | std::ios::binary);
    tfile << "P6 " << _width << " " << _height << " 255 ";
    tfile.write(reinterpret_cast<const char*>(image.data()),image.size());
    tfile.close();
  }

  uintmax_t width() const  { return _width;  }
  uintmax_t height() const { return _height; }

  void fill(const uint8_t r, const uint8_t g, const uint8_t b)
  {
    for(uintmax_t i = 0; i < image.size(); i+=3)
      {
	    image[i+0] = r;
	    image[i+1] = g;
	    image[i+2] = b;
      }
  }

  void color(const uint8_t r, const uint8_t g, const uint8_t b)
  {
    red = r; green = g; blue = b; 
  }
  
  void set(const uintmax_t x, const uintmax_t y)
  {
    const size_t tbyte = (y * _byteWidth) + (bsize * x);
    image[tbyte + 0] = red;
    image[tbyte + 1] = green;
    image[tbyte + 2] = blue;
  }
  
private:
  uint8_t red;
  uint8_t blue;
  uint8_t green;
  
  std::vector<uint8_t> image;

  size_t    _byteWidth;
  uintmax_t _width;
  uintmax_t _height;
};

int main()
{
  Image i;
  i.fill(255,0,0);

  i.color(0,0,255);

  for(int x=0; x < 200; x++) { i.set(x,x); }
  
  i.writeppm("testfile.ppm");
}

