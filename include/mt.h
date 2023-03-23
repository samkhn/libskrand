#ifndef _SKTL_RAND_MT_H_
#define _SKTL_RAND_MT_H_

namespace SKTL {
namespace Random {
namespace MT19937 {

static constexpr int kN = 624;
static constexpr int kM = 397;
static constexpr unsigned long kMatrixA = 0x9908b0dfUL;
static constexpr unsigned long kUpperMask = 0x80000000UL;
static constexpr unsigned long kLowerMask = 0x7fffffffUL;

struct Generator {
  unsigned long mersenne_twister[kN];
  int mersenne_twister_index = kN + 1;
  
  void InitializeGenRand(unsigned long s) {
    mersenne_twister[0] = s & 0xffffffffUL;
    for (mersenne_twister_index = 1; mersenne_twister_index < kN;
         ++mersenne_twister_index) {
      mersenne_twister[mersenne_twister_index] =
          (1812433253UL * (mersenne_twister[mersenne_twister_index - 1] ^
                           mersenne_twister[mersenne_twister_index - 1] >> 30) +
           mersenne_twister_index);
      mersenne_twister[mersenne_twister_index] &= 0xffffffffUL;
    }
  }
    
  unsigned long GenRandInt32() {
    unsigned long y;
    static unsigned long mag01[2] = {0x0UL, kMatrixA};
    if (mersenne_twister_index >= kN) {
      int kk;
      if (mersenne_twister_index == kN + 1)
        InitializeGenRand(5489UL);
      for (kk = 0; kk < kN - kM; ++kk) {
        y = (mersenne_twister[kk] & kUpperMask) |
            (mersenne_twister[kk + 1] & kLowerMask);
        mersenne_twister[kk] =
            mersenne_twister[kk + kM] ^ (y >> 1) ^ mag01[y & 0x1UL];
      }
      for (; kk < kN - 1; ++kk) {
        y = (mersenne_twister[kk] & kUpperMask) |
            (mersenne_twister[kk + 1] & kLowerMask);
        mersenne_twister[kk] =
            mersenne_twister[kk + (kM - kN)] ^ (y >> 1) ^ mag01[y & 0x1UL];
      }
      y = (mersenne_twister[kN - 1] & kUpperMask) |
          (mersenne_twister[0] & kLowerMask);
      mersenne_twister[kN - 1] =
          mersenne_twister[kM - 1] ^ (y >> 1) ^ mag01[y & 0x1UL];
      mersenne_twister_index = 0;
    }
    y = mersenne_twister[mersenne_twister_index++];
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680UL;
    y ^= (y << 15) & 0xefc60000UL;
    y ^= (y >> 18);
    return y;
  }
};

}  // namespace MT19937
}  // namespace Random
}  // namespace SKTL

#endif  // _SKTL_RAND_MT_H_
