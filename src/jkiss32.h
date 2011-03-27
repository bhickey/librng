#ifndef __LIB_RNG_JKISS32_HEADER__
#define __LIB_RNG_JKISS32_HEADER__
#pragma once

#include <stdint.h>
#include "rng.h"

class JKISS32 : public RNG {
	public:
		JKISS32();
                RNG* split();
                void seed(uint32_t);
		void seed(RNG*);
		uint64_t get_uint64();
		uint32_t get_uint32();
	private:
		uint32_t _x, _y, _z, _w, _c;
};

#endif
