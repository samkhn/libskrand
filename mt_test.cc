#include "mt.h"

#include <iostream>
#include <random>

int main() {
  InitializeGenRand(102013);
  std::mt19937 prng(102013);
  for (size_t i = 0; i < 10000; ++i) {
	if (GenRandInt32() != prng()) {
	  std::cout << "ERROR" << std::endl;
	  return 1;
	}
  }
  std::cout << "OK" << std::endl;
  return 0;
}
