#ifndef __LIB_RNG_KISS_HEADER__
#define __LIB_RNG_KISS_HEADER__
#pragma once

#include <stdint.h>
#include "rng.h"

class KISS : public RNG {
	public:
		KISS();
		void seed(RNG*);
		KISS split();
		uint64_t get_uint64();
		uint32_t get_uint32();
	private:
		void fill_buffer();
		uint32_t _x, _y, _z, _c;
};

#endif
