#ifndef MAP_GENERATOR_COMPONENT_COMPONENT_H_
#define MAP_GENERATOR_COMPONENT_COMPONENT_H_

#include <opencv2/core/core.hpp>

namespace mapgen {
namespace component {

/// Abstract class for component generators
class Component {
//FUNCTIONS
 public:
  Component() {}
  virtual ~Component() {}

  virtual cv::Mat Generate() = 0;

//VARIABLES
};

}  // namespace component
}  // namespace mapgen

#endif  // MAP_GENERATOR_COMPONENTS_COMPONENT_H_
