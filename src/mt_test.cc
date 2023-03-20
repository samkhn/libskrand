#include "mt.h"

#include <iostream>
#include <random>

int main() {
	SKTL::Random::MT19937::InitializeGenRand(102013);
	std::mt19937 prng(102013);
	for (size_t i = 0; i < 10000; ++i) {
		if (SKTL::Random::MT19937::GenRandInt32() != prng()) {
			std::cout << "ERROR\n";
			return 1;
		}
	}
	std::cout << "OK\n";
	return 0;
}
