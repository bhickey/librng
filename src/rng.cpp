#include "rng.h"

float
RNG::get_float() {
	return ((float) (0x3f800000 | get_bits(23)) - 1.0);
}

double
RNG::get_double() {
	return ((double) (0x3ff0000000000000 | get_bits(52)) - 1.0);
}

bool
RNG::get_bool()
{
	return ((bool) get_bits(1));
}

uint64_t
RNG::get_nonzero_bits(short n)
{
	uint64_t result = 0;
	while(!result) 
	{
		result = get_bits(n);
	}
	return (result);
}

uint64_t
RNG::get_bits(short n)
{
	uint64_t result;
	if(_buffer_size < n)
	{
		result = _buffer;
		result <<= _buffer_size;
		n -= _buffer_size;
		fill_buffer();
	}
	result |= _buffer & (1 << n) - 1;
	_buffer_size -= n;
	_buffer >>= n;
	return (result);
}
