#include <valarray>
#include <string>
#include <stdint.h>
#include <iostream>
#include <fstream>
#include <vector>

class Image
{
public:
  using csize = uint8_t;
  
  Image() :
    Image(320,200) {}

  Image(const uintmax_t w, const uintmax_t h) :
    image(w * h * 3 * sizeof(csize)),
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
  
private:
  std::vector<uint8_t> image;
  uintmax_t _width;
  uintmax_t _height;
};

int main()
{
  Image i;
  i.fill(255,0,0);
  i.writeppm("testfile.ppm");
}

