#ifndef MAP_GENERATOR_COMPONENT_MOUNTAIN_H_
#define MAP_GENERATOR_COMPONENT_MOUNTAIN_H_

#include <opencv2/core/core.hpp>

#include "component.h"

namespace mapgen {
namespace component {

class Mountain : public Component {
//STRUCTS
 public:
  struct Parameters {
    cv::Size size;

    cv::Point apex;
    cv::Point left_corner;
    cv::Point right_corner;

    Parameters(cv::Size size_ = cv::Size(),
               cv::Point apex_ = cv::Point(),
               cv::Point left_corner_ = cv::Point(),
               cv::Point right_corner_ = cv::Point())
    : size(size_),
      apex(apex_),
      left_corner(left_corner_),
      right_corner(right_corner_)
    {}
  };

//FUNCTIONS
 public:
  Mountain();
  virtual ~Mountain();

  /// generate mountain using default parameters
  virtual cv::Mat Generate();

  /// generate mountain with parameters
  virtual cv::Mat Generate(const Parameters &param);

//VARIABLES
};

}  // namespace component
}  // namespace mapgen

#endif  // MAP_GENERATOR_COMPONENT_MOUNTAIN_H_
