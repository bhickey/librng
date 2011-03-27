#ifndef __LIB_RNG_Xorshift_HEADER__
#define __LIB_RNG_Xorshift_HEADER__
#pragma once

#include <stdint.h>
#include "rng.h"

template<int x, int y, int z>
class Xorshift : public RNG {
	public:
		Xorshift();
                RNG* split();
                void seed(uint32_t);
		void seed(RNG*);
		uint64_t get_uint64();
		uint32_t get_uint32();
	private:
                uint64_t _state; 
};

#endif
