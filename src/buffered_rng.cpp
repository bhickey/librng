#include "buffered_rng.h"

BufferedRNG::BufferedRNG(RNG *rng) {
        _innerRNG = rng;
        _index = RNG_BUFFER_SIZE;
}

RNG*
BufferedRNG::split() {
	RNG* k = _innerRNG->split();
        return new BufferedRNG(k);	
}

void
BufferedRNG::seed(RNG *rng)
{
        _innerRNG->seed(rng);
        buffer();
}

void
BufferedRNG::buffer()
{
        for(int ii = 0; ii < RNG_BUFFER_SIZE; ++ii) 
        {
                _buffer[ii] = _innerRNG->get_uint64();
        }
        _index = 0;
}

uint64_t
BufferedRNG::get_uint64()
{
        if(_index == RNG_BUFFER_SIZE)
        {
                buffer();
        }

        return _buffer[_index++];
}

inline uint32_t
BufferedRNG::get_uint32()
{
        return (get_uint64() & 0xFFFFFFFF);
}
