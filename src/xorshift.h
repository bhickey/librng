#ifndef __LIB_RNG_Xorshift_HEADER__
#define __LIB_RNG_Xorshift_HEADER__
#pragma once

#include <stdint.h>
#include "rng.h"

template<int x, int y, int z>
class Xorshift : public RNG {
	public:
		Xorshift() {
                        _state = 88172645463325252LL;
                }

                RNG* split() {
                 	RNG* k = new Xorshift();
	                k->seed(this);
	                return k;
                }

                void seed(RNG *rng)
                {
                        _state ^= rng->get_uint64();
                        _state = 1490024343005336237ULL * _state + 123456789;
                }

		uint64_t get_uint64()
                {
                        uint64_t local = _state;
                        local ^= (local << x);
                        local ^= local >> y;
                        return (_state = local ^ (local << z));
                }

		uint32_t get_uint32()
                {
                        return (get_uint64() & 0xFFFFFFFF);
                }
	private:
                uint64_t _state; 
};

#endif
