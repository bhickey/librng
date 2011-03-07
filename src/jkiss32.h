#ifndef __LIB_RNG_KISS_HEADER__
#define __LIB_RNG_KISS_HEADER__
#pragma once

#include <stdint.h>
#include "rng.h"

class JKISS32 : RNG {
	public:
		JKISS32();
                RNG* split();
		void seed(RNG*);
		uint64_t get_uint64();
		uint32_t get_uint32();
	private:
		uint32_t _x, _y, _z, _w, _c;
};

#endif
