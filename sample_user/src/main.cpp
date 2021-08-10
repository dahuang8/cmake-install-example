#include "sample_lib.h"

#include <iostream>

int main(int argc, const char* argv[]) {
  samplelib::SampleLib adder;
  int32_t a = 10;
  int32_t b = 20;
  std::cout << "Sum of " << a << " and " << b << " is " << adder.Add(a, b)
            << std::endl;
  return 0;
}
