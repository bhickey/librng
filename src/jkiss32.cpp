#include "jkiss32.h"

// David Jones's JKISS32 generator, ported from the C source

JKISS32::JKISS32() {
	_x = 123456789;
	_y = 234567891;
	_z = 345678912;
        _w = 456789123;
	_c = 0;
}

RNG*
JKISS32::split() {
	RNG* k = new JKISS32();
	k->seed(this);
	return k;
}

void
JKISS32::seed(uint32_t s)
{
        _x = s;
}

void
JKISS32::seed(RNG *rng)
{
	_x = rng->get_uint32();
	_y = rng->get_uint32();
	_z = rng->get_uint32();
	_w = rng->get_uint32();
}

uint64_t
JKISS32::get_uint64()
{
        return (((uint64_t) get_uint32()) << 32 | get_uint32());
}

uint32_t
JKISS32::get_uint32()
{
        int32_t t;
        int32_t y = _y;
        y ^= (y << 5);
        y ^= (y >> 7);
        y ^= (y << 22);
        _y = y;
        t = _z + _w + _c;
        _z = _w;
        _c = t < 0;
        _w = t & 0x7FFFFFFF;
        _x += 0x542023AB;
	return (_x + _y + _w);
}
