#include <iostream>
#include "math/vec3.hpp"
#include "general/color.hpp"

int main() {
  unsigned int img_w = 256;
  unsigned int img_h = 256;
  // magic bytes
  std::cout << "P3\n" << img_w << " " << img_h << "\n255\n";
  for (int y = 0; y < img_w; ++y) {
    std::clog << "shit started with remaining: " 
      << (img_w - y) << std::endl;
    for (int x = 0; x < img_h; ++x) {
      auto pixel_color = color(double(x)/(img_w-1), double(y)/(img_h-1),0);
      write_color(std::cout, pixel_color);
    }
  }

  return 0;
}
