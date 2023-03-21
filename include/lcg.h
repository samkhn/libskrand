#ifndef _SKTL_RAND_LCG_H_
#define _SKTL_RAND_LCG_H_

#include <iostream>

namespace SKTL {
namespace Random {
namespace LCG {

struct LinearCongruentialGenerator {
  // TODO: perhaps each struct should carry a valid int where 0 means
  // uninitialized, 1 means has values but unverified, 2 means initialized
  // and verified.
  unsigned long long a;  // multiplier term
  unsigned long long c;  // increment term
  unsigned long long m;  // modulus term
  unsigned long long x;
};

bool Valid(const LinearCongruentialGenerator &lcg) {
  return (lcg.a != 0 && lcg.a < lcg.m && lcg.c < lcg.m && lcg.x < lcg.m);
}

unsigned GenRandInt32(LinearCongruentialGenerator &lcg) {
  lcg.x = (lcg.a * lcg.x + lcg.c) % lcg.m;
  return lcg.x;
}

LinearCongruentialGenerator InitializeMinStdRand(unsigned seed) {
  return LinearCongruentialGenerator{48271UL, 0UL, 2147483647UL, seed};
}

}  // namespace LCG
}  // namespace Random
}  // namespace SKTL

#endif  // _SKTL_RAND_LCG_H_
