#include "jkiss.h"

// David Jone's JKISS generator, ported from the C source written by the same.

JKISS::JKISS() {
        _x = 123456789;
        _y = 987654321;
        _z = 43219876;
        _c = 6543217;
}

RNG*
JKISS::split()
{
        RNG* k = new JKISS();
        k->seed(this);
        return k;
}

void
JKISS::seed(uint32_t s)
{
        _y = s;        
}

void
JKISS::seed(RNG *rng) 
{
        _x = rng->get_uint32();
        _y = rng->get_nonzero_bits(32);
        _z = rng->get_uint32();
        
        if(!_z) {
                _c = rng->get_nonzero_bits(32);
        } else {
                _c = rng->get_uint32();
        }
}

uint64_t
JKISS::get_uint64()
{
        uint64_t result = get_uint32();
        result <<= 32;
        result |= get_uint32();
        return (result);
}

uint32_t
JKISS::get_uint32()
{
        uint64_t t;
        _x = 314527869 * _x + 1234567; 
        _y ^= _y << 5; 
        _y ^= _y >> 7; 
        _y ^= _y << 22; 
        t = 4294584393ULL * _z + _c; 
        _c = t >> 32; 
        _z = t;
        return (_x + _y + _z);
}
