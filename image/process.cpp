#include "process.h"

#include <cassert>
#include <vector>

namespace mapgen {
namespace image {

cv::Mat ProcessComponent(const cv::Mat &comp, const cv::Mat &mask) {
  assert(comp.size() == mask.size());
  assert(comp.channels() == 1 || comp.channels() == 3);
  assert(mask.channels() == 1);

  std::vector<cv::Mat> ins;
  ins.push_back(comp);
  ins.push_back(mask);

  std::vector<cv::Mat> outs;
  cv::Mat remix(comp.size(), CV_8UC4);
  outs.push_back(remix);

  int mixer[8];
  if (comp.channels() == 1) {
    mixer[0] = 0; mixer[1] = 0;
    mixer[2] = 0; mixer[3] = 1;
    mixer[4] = 0; mixer[5] = 2;
    mixer[6] = 1; mixer[7] = 3;
  } else {
    mixer[0] = 0; mixer[1] = 0;
    mixer[2] = 1; mixer[3] = 1;
    mixer[4] = 2; mixer[5] = 2;
    mixer[6] = 3; mixer[7] = 3;
  }

  cv::mixChannels(ins, outs, mixer, 4);
  return remix;
}

}  // namespace image
}  // namespace mapgen
