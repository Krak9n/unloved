#ifndef COLOR_HPP
#define COLOR_HPP

#pragma once
// fix this path shit later
#include "../math/vec3.hpp"

using color = vec3;
void write_color(std::ostream& out, const color& pixel_color) {
  auto r = pixel_color.x();
  auto g = pixel_color.y();
  auto b = pixel_color.z();
  // byte range translation
  int ir = int(255.999 * r);
  int ig = int(255.999 * g);
  int ib = int(255.999 * b);

  std::cout << ir << " " << ig << " " << ib << std::endl;
  return;
}

#endif
