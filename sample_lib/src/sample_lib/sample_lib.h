#ifndef __SAMPLE_LIB_H__
#define __SAMPLE_LIB_H__

#include <cstdint>

namespace samplelib {
class SampleLib {
 public:
  SampleLib();
  int32_t Add(int32_t a, int32_t b) const;
};
}  // namespace samplelib

#endif  // __SAMPLE_LIB_H__
