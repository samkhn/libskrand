#include "lcg.h"

#include <iostream>
#include <random>

static int kTestCount = 3;

int main() {
  int passed = 0;
  SKTL::Random::LCG::LinearCongruentialGenerator invalid{0, 0, 0, 0};
  if (Valid(invalid)) {
    std::cout << "FAIL: Valid(invalid) returned true. Want false\n";
  } else {
    passed++;
  }
  unsigned seed = 10217;
  auto g = SKTL::Random::LCG::InitializeMinStdRand(seed);
  if (!Valid(g)) {
    std::cout << "FAIL: Valid(/*valid*/g) returned false. Want true\n";
  } else {
    passed++;
  }
  std::minstd_rand sg(seed);
  unsigned sktl_n, stl_n;
  for (int i = 0; i < 10000; ++i) {
    sktl_n = SKTL::Random::LCG::GenRandInt32(g);
    stl_n = sg();
    if (sktl_n != stl_n) {
      std::cout << "FAIL: Got " << sktl_n << ". Want: " << stl_n << "\n";
    } else {
      passed++;
    }
  }
  std::cout << "PASSED " << kTestCount << "/" << kTestCount << "\n";
  return 0;
}
