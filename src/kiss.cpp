#include "kiss.h"

// George Marsaglia's KISS generator, ported from the C source written 
// by David Jones.

KISS::KISS() {
	_x = 123456789;
	_y = 36243600;
	_z = 521288629;
	_c = 764321;
}

RNG*
KISS::split() {
	RNG* k = new KISS();
	k->seed(this);
	return k;
}

void
KISS::seed(RNG *rng) {
	_x = rng->get_uint32();
	_y = rng->get_nonzero_bits(32);
	_z = rng->get_uint32();
	if(!_z) {
                _c = rng->get_nonzero_bits(32);
	} else {
                _c = rng->get_uint32();
	}
	_buffer_size = 0;
}

uint64_t
KISS::get_uint64()
{
	return (get_bits(64));
}

uint32_t
KISS::get_uint32()
{
	uint64_t t, a;
	a = 698769069ULL;
	_x = 69069 * _x + 12345;
	_y ^= (_y << 13);
	_y ^= (_y >> 17);
	_y ^= (_y << 5);
	t = a * _z + _c;
	_c = t >> 32;
	return (_x+_y+(_z=t));
}

void
KISS::fill_buffer()
{
	_buffer = get_uint32();
        _buffer <<= 32;
        _buffer |= get_uint32();
	_buffer_size = 64;
}
