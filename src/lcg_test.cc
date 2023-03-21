#include "lcg.h"

#include <iostream>
#include <random>

int main() {
	unsigned seed = 10217;
	auto g = SKTL::Random::LCG::InitializeMinStdRand(seed);
	std::minstd_rand sg(seed);
	unsigned sktl_n, stl_n;
	for (int i = 0; i < 10000; ++i) {
		sktl_n = SKTL::Random::LCG::GenRandInt32(g);
		stl_n = sg();
		if (sktl_n != stl_n) {
			std::cout << "FAIL: Got " << sktl_n << ". Want: " << stl_n << "\n";
			return 1;
		}
	}
	std::cout << "OKAY\n";
	return 0;
}
