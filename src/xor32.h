#ifndef __LIB_RNG_KISS_HEADER__
#define __LIB_RNG_KISS_HEADER__
#pragma once

#include <stdint.h>
#include "rng.h"

class XOR32 : RNG {
	public:
		XOR32();
                RNG* split();
                void seed(uint32_t);
		void seed(RNG*);
		uint64_t get_uint64();
		uint32_t get_uint32();
	private:
                uint32_t _state;
};

#endif
