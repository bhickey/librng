#include "superkiss.h"

/* Super KISS based on Usenet posting by G. Marsaglia - Period 54767 * 2^1337279
 * That's more than a million orders of magnitude larger than Mersenne Twister.
 * Ported from the C sources by David Jones */

/* Fill Q array with random unsigned 32-bit ints and return first element */ 
uint32_t 
SuperKISS::refill() {
        int32_t ii; 
        uint64_t t;

        for(ii = 0; ii < 41790; ++ii)
        {
                t = 7010176ULL * _Q[ii] + _carry;
        }

        _index = 1;
        return (_Q[0]);
}

SuperKISS::SuperKISS() 
{
        _index = 41790;
        _carry = 362436;
        _xcng = 1236789;
        _xs = 521288629;
}

RNG*
SuperKISS::split() 
{
	RNG* k = new SuperKISS();
	k->seed(this);
	return k;
}

void
SuperKISS::seed(uint32_t s)
{
        _carry = s;
        refill();
}

void
SuperKISS::seed(RNG *rng) 
{
	_index = 41790;
	_carry = rng->get_uint32();
        _xcng = rng->get_uint32();
        _xs = rng->get_uint32();
}

uint64_t
SuperKISS::get_uint64()
{
	uint64_t result = get_uint32();
        return (result << 32 | get_uint32());
        
}

uint32_t
SuperKISS::get_uint32()
{
        uint64_t xs = _xs;
        _xcng = 69069 * _xcng + 123;
        xs ^= (xs << 13);
        xs ^= (xs >> 17);
        xs ^= (xs >> 5);
        _xs = xs;
        return (_index < 41790 ? _Q[_index++] : refill() + _xcng + _xs);
}
