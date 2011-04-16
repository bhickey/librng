#include "xor64.h"

// 64-bit version of George Marsaglia's Xorshift generator

XOR64::XOR64() {
        _state = 88172645463325252LL;
}

RNG*
XOR64::split() {
	RNG* k = new XOR64();
	k->seed(this);
	return k;
}

void
XOR64::seed(RNG *rng) {
        _state ^= rng->get_uint64();
        _state = 1490024343005336237ULL * _state + 123456789;
}

uint64_t
XOR64::get_uint64()
{
        uint64_t local = _state;
        local ^= (local << 13);
        local ^= (local >> 7);
        return (_state = (local ^= (local << 17)));
}
