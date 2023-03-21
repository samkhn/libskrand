#ifndef _SKTL_RAND_LCG_H_
#define _SKTL_RAND_LCG_H_

#include <iostream>

namespace SKTL {
namespace Random {
namespace LCG {

// TODO: assert a != 0, a < m, c < m, x < m.
struct LinearCongruentialGenerator {
	unsigned long long a; // multiplier term
	unsigned long long c; // increment term
	unsigned long long m; // modulus term
	unsigned long long x;
};

unsigned GenRandInt32(LinearCongruentialGenerator &lcg) {
	lcg.x = (lcg.a * lcg.x + lcg.c) % lcg.m;
	return lcg.x;
}

LinearCongruentialGenerator InitializeMinStdRand(unsigned seed) {
	return LinearCongruentialGenerator{48271UL, 0UL, 2147483647UL, seed};
}

}	// namespace LCG
}	// namespace Random
}	// namespace SKTL

#endif	// _SKTL_RAND_LCG_H_
