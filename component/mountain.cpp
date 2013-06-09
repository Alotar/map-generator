#include "mountain.h"

#include "image/process.h"

namespace mapgen {
namespace component {

Mountain::Mountain() {}

Mountain::~Mountain() {}

cv::Mat Mountain::Generate() {
  Parameters param(cv::Size(51, 51),
                   cv::Point(26, 6),
                   cv::Point(6, 45),
                   cv::Point(45, 45));
  return Generate(param);
}

cv::Mat Mountain::Generate(const Parameters &param) {
  // output generation
  cv::Mat out(param.size, CV_8UC1);
  out = 255;  // paint it white
  cv::line(out, param.apex, param.left_corner, 0);
  cv::line(out, param.apex, param.right_corner, 0);

  // alpha channel mask generation
  cv::Mat mask(param.size, CV_8UC1);
  mask = 255;  // fully opaque

  // output
  return ::mapgen::image::ProcessComponent(out, mask);
}

}  // namespace component
}  // namespace mapgen
