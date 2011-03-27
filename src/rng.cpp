#include "rng_internal.h"

void
RNG::seed_with(uint32_t s) {
        if(!s) {
                s = time(NULL);
        }
        LCG g(s);
        this->seed(&g);
}

/* Produces a pseudo-random int on the interval [0,2^32) */
inline int
RNG::get_int()
{
        return (get_uint32() & 0x7FFFFFFF);
}

/* Produces a pseudo-random integer on the interval [0,n)
 * uses rejection sampling.
 * Given a well behaved generator, in the worst case this will require
 * two invocations of get_uint32().
 * Not guaranteed to halt given a sufficiently pathological generator.
 */
int
RNG::get_int(int n)
{
        int v = n;
        v--;
        v |= v >> 1;
        v |= v >> 2;
        v |= v >> 4;
        v |= v >> 8;
        v |= v >> 16;
        
        int result;
        do {
                result = get_uint32() & v;
        } while(result > n);

        return (result);
}

float
RNG::get_float()
{
	return ((float) (0x3f800000 | (get_uint32() & ((1 << 23) - 1))) - 1.0);
}

double
RNG::get_double() {
	return ((double) (0x3ff0000000000000 | (get_uint64() & ((1ULL << 52) -1))) - 1.0);
}

double
RNG::get_normal(double mu, double sigma) {
        double x, y, r;

        do {
                x = 2.0 * get_double();
                y = 2.0 * get_double();
                r = x * x + y * y;
        }while(r == 0.0 || r >= 1.0);

        r = sqrt((-2.0 * log(r)) / r);

        return (x * r * sigma + mu);
}

bool
RNG::get_bool()
{
	return ((bool) get_uint32());
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
        if(n <= 32) {
                return (get_uint32() & (1ULL << n) - 1);
        } else {
                return (get_uint64() & (1ULL << n) - 1);
        }
}

/* Linear Congruential Generator for seeding other generators provided a 32-bit
 * seed. A rather poor choice of generator, this isn't exposed outside of this
 * class. Uses the same parameterization as glibc.
 */
LCG::LCG()
{
        _state = 214013;
}

LCG::LCG(uint32_t seed)
{
        _state = seed;
        get_uint32();
}

uint32_t
LCG::get_uint32() {
        _state = 1103515245 * _state + 12345;
        return _state;
}

uint64_t
LCG::get_uint64() {
        uint64_t result = get_uint32();
        result <<= 32;
        return (result |= get_uint32());
}

RNG*
LCG::split()
{
        RNG* gen = new LCG();
        gen->seed(this);
        return gen;
}

void
LCG::seed(RNG* gen)
{
        // This offers no robustness guarantees.
        _state = get_uint32() ^ 0xFFFFFFFF * 1664525 + 1013904223;
}
