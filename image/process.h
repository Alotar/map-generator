#ifndef MAP_GENERATOR_IMAGE_PROCESS_H_
#define MAP_GENERATOR_IMAGE_PROCESS_H_

#include <opencv2/core/core.hpp>

namespace mapgen {
namespace image {

/// Processes component image to output format:
/// * converts to 3 channel image
/// * adds alpha channel
cv::Mat ProcessComponent(const cv::Mat &comp, const cv::Mat &mask);

}  // namespace image
}  // namespace mapgen

#endif  // MAP_GENERATOR_IMAGE_PROCESS_H_
