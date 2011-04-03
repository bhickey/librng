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

uint32_t
JKISS::get_uint32()
{
        uint64_t t;
        uint32_t y = _y;
        _x = 314527869 * _x + 1234567; 
        y ^= y << 5; 
        y ^= y >> 7; 
        y ^= y << 22; 
        _y = y;
        t = 4294584393ULL * _z + _c; 
        _c = t >> 32; 
        _z = t;
        return (_x + y + _z);
}
