#include "scg.h"

// Synchronized Congruential Generator
// A putatively safely splittable PRNG based
// on multiplicative linear congruential generators and
// L'Eucyer (1998)

SCG::SCG() {
	_x = 123456789;
	_y = 36243600;
    _offset = 0;
}

SCG::SCG(const SCG* rng) {
    _x = rng->_x;
    _y = rng->_y;
    _offset = rng->_offset;
}

RNG*
SCG::split() {
    skip(5 * _offset + 1);
	SCG* k = new SCG(this);
    k->step();
	return k;
}

void
SCG::seed(uint32_t s)
{
    _x = s;
    _y = 36243600;
    _offset = 0;
}

void
SCG::seed(RNG *rng)
{
    _x = rng->get_uint64();
    _y = rng->get_uint64();
    _offset = 0;
}

uint32_t
SCG::get_uint32()
{
    _x *= 0x6a5d39eae116586d;
    _y *= 0x3b91f78bdac4c89d;

    return ((_x + _y) >> 32);
}

void
SCG::step() {
    _x *= 0x6a5d39eae116586d;
    _offset += 1;
}

void
SCG::skip(uint64_t state) {
    uint64_t multiplier = 0x1;
    uint64_t mask = 0x1;
    uint64_t distance = _offset - state;
    for(int ii = 0; ii < 64; ++ii) {
        if(distance & mask) {
            multiplier *= skip_table[ii];
        }
        mask <<= 1;
        ++ii;
    }
    _x *= multiplier;
    _offset = state;
}
