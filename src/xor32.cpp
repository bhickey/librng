#include "xor32.h"

// 32-bit version of George Marsaglia's Xorshift generator

XOR32::XOR32() {
        _state = 2463534242;
}

RNG*
XOR32::split() {
	RNG* k = new XOR32();
	k->seed(this);
	return k;
}

void
XOR32::seed(uint32_t s)
{
        _state = s;
}

void
XOR32::seed(RNG *rng) {
        _state ^= rng->get_uint32();
        _state = 1490024343005336237ULL * _state + 123456789;
}

uint64_t
XOR32::get_uint64()
{
        uint64_t s = get_uint32();
        return ((s << 32) | get_uint32());
}

uint32_t
XOR32::get_uint32()
{
        _state ^= (_state << 13);
        _state ^= (_state >> 17);
        return (_state ^= (_state << 5));
}
