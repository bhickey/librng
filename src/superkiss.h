#ifndef __LIB_RNG_SuperKISS_HEADER__
#define __LIB_RNG_SuperKISS_HEADER__
#pragma once

#include <stdint.h>
#include "rng.h"

class SuperKISS : RNG {
	public:
		SuperKISS();
                RNG* split();
                void seed(uint32_t);
		void seed(RNG*);
		uint64_t get_uint64();
		uint32_t get_uint32();
	private:
                uint32_t refill();
                uint32_t _Q[41790];
		uint32_t _index, _carry, _xcng, _xs;
};

#endif
