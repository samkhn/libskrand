#include "mt.h"

#include <iostream>
#include <random>

int main() {
  unsigned seed = 102013;
  SKTL::Random::MT19937::InitializeGenRand(seed);
  std::mt19937 sg(seed);
  unsigned sktl_n, stl_n;
  for (size_t i = 0; i < 10000; ++i) {
    sktl_n = SKTL::Random::MT19937::GenRandInt32();
    stl_n = sg();
    if (sktl_n != stl_n) {
      std::cout << "FAIL: Got " << sktl_n << ". Want: " << stl_n << "\n";
      return 1;
    }
  }
  std::cout << "PASS\n";
  return 0;
}
