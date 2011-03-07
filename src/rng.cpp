#include "rng.h"

float
RNG::get_float() {
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
        }while(r== 0.0 || r >= 1.0);

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
