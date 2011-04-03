#ifndef __LIB_RNG_XOR32_HEADER__
#define __LIB_RNG_XOR32_HEADER__
#pragma once

#include <stdint.h>
#include "rng.h"

class XOR32 : public RNG {
	public:
		XOR32();
                RNG* split();
                void seed(uint32_t);
		void seed(RNG*);
		uint32_t get_uint32();
	private:
                uint32_t _state;
};

#endif
