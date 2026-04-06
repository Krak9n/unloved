#include <iostream>
#include "math/vec3.hpp"
#include "math/ray.hpp"
#include "general/color.hpp"

// sphere radius
// x^2 + y^2 + z^2 = r^2
bool hit_sphere(
    const point3& center, 
    double radius, 
    const ray& r) {
  vec3 oc = center - r.origin();
  auto a = dot(r.direction(), r.direction());
  auto b = -2.0 * dot(r.direction(), oc);
  auto c = dot(oc, oc) - radius * radius;

  auto discriminant = b * b - 4 * a * c;
  return (discriminant > 0);
}

color ray_color(const ray& r) {
  if (hit_sphere(point3(0,0,-1), 0.5, r)) return color(1.0, 0.0, 0.0);
  else {
    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5 * (unit_direction.y() + 1.0);
    return color(0,0,0); 
  }
}

int main(void) {
  auto aspect_ratio = 16.0 / 9.0;
  unsigned int img_w = 400;

  // ensure that the img height is at least one
  unsigned int img_h = int(img_w / aspect_ratio);
  img_h = (img_h < 1) ? 1 : img_h;

  // shitty camera
  auto focal_length = 1.0;
  auto viewport_h = 2.0;
  auto viewport_w = viewport_h * (double(img_w)/img_h);
  auto camera_center = point3(0,0,0); // stttaaaart

  // calculating vectors across the horizontal and down the 
  // vertical viewport edges
  auto viewport_u = vec3(viewport_w, 0, 0);
  auto viewport_v = vec3(0, -viewport_w, 0);
  //calculate horizontal and vertical delta vectors
  //from pixel to pixel
  auto pixel_delta_u = viewport_u / img_w;
  auto pixel_delta_v = viewport_v / img_h;

  auto viewport_upper_left = camera_center - vec3(0, 0, focal_length)
    - viewport_u / 2 - viewport_v / 2;
  auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

  //rendering starts here
  //magic bytes first
  std::cout << "P3\n" << img_w << " " << img_h << "\n255\n";
  for (int y = 0; y < img_w; ++y) {
    for (int x = 0; x < img_h; ++x) {
      auto pixel_center = pixel00_loc + (x * pixel_delta_u) + (y * pixel_delta_v);
      auto ray_direction = pixel_center - camera_center;
      ray r(camera_center, ray_direction);

      color pixel_color = ray_color(r);
      write_color(std::cout, pixel_color);
    }
  }

  return 0;
}
