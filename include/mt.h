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

static unsigned long mersenne_twister[kN];
static int mersenne_twister_index = kN + 1;

void InitializeGenRand(unsigned long s);
unsigned long GenRandInt32();

}	// namespace MT19937
}	// namespace Random
}	// namespace SKTL

#endif	// _SKTL_RAND_MT_H_
