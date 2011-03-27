#include "xorshift.h"

// A templated version of the Xorshift generator

template<uint8_t x, uint8_t y, uint8_t z>
Xorshift<x,y,z>::Xorshift() {
        _state = 88172645463325252LL;
}


template<uint8_t x, uint8_t y, uint8_t z>
RNG*
Xorshift<x,y,z>::split() {
	RNG* k = new Xorshift();
	k->seed(this);
	return k;
}

template<uint8_t x, uint8_t y, uint8_t z>
void
Xorshift<x,y,z>::seed(uint32_t s)
{
        _state = s;
}

template<uint8_t x, uint8_t y, uint8_t z>
void
Xorshift<x,y,z>::seed(RNG *rng) {
        _state ^= rng->get_uint32();
        _state = 1490024343005336237ULL * _state + 123456789;
}

template<uint8_t x, uint8_t y, uint8_t z>
uint32_t
Xorshift<x,y,z>::get_uint32()
{
        return (get_uint32() & 0xFFFFFFFF);
}

template<uint8_t x, uint8_t y, uint8_t z>
uint64_t
Xorshift<x,y,z>::get_uint64()
{
        uint64_t local = _state;
        local ^= (local << x);
        local ^= local >> y;
        return (_state = local ^ (local << z));
}
