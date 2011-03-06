#include "jlkiss64.h"

// A 64-bit variant of George Marsaglia's KISS generator designed by David 
// Jones, and ported from the C sources written by the same.

JLKISS64::JLKISS64() {
        _x = 123456789123ULL;
        _y = 987654321987ULL;
        _z1 = 43219876;
        _z2 = 21987643;
        _c1 = 6543217; 
        _c2 = 1732654;
}

RNG*
JLKISS64::split() {
        RNG* k = new JLKISS64();
        k->seed(this);
        return k;
}

void
JLKISS64::seed(RNG *rng) {
        _x  = rng->get_uint64();
        _z1 = rng->get_uint32();
        _z2 = rng->get_uint32();
        _c1 = rng->get_uint32();
        _c2 = rng->get_uint32();
        do {
                _y  = rng->get_uint64();
        } while(!_y);

        _buffer_size = 0;
}

uint64_t
JLKISS64::get_uint64()
{
        uint64_t t;
        _x = 1490024343005336237ULL * _x + 123456789; 
        _y ^= _y << 21; 
        _y ^= _y >> 17; 
        _y ^= _y << 30; /* Do not set y=0! */ 
        t = 4294584393ULL * _z1 + _c1; 
        _c1 = t >> 32; 
        _z1 = t; 
        t = 4246477509ULL * _z2 + _c2; 
        _c2 = t >> 32; 
        _z2 = t;
        return (_x + _y + _z1 + ((uint64_t)_z2 << 32)); 
}

uint32_t
JLKISS64::get_uint32()
{
        return ((uint32_t) get_bits(32));
}

void
JLKISS64::fill_buffer()
{
        _buffer = get_uint64();
        _buffer_size = sizeof(_buffer) * 8;
}
