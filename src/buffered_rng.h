#ifndef __LIB_RNG_BUFFERED_RNG_HEADER__
#define __LIB_RNG_BUFFERED_RNG_HEADER__
#pragma once

#include <stdint.h>
#include "rng.h"

#define RNG_BUFFER_SIZE 4096

class BufferedRNG : public RNG {
	public:
		BufferedRNG(RNG*);
                RNG* split();
		void seed(RNG*);
		uint64_t get_uint64();
		uint32_t get_uint32();
	private:
                void buffer();
                RNG* _innerRNG;
                uint16_t _index;
                uint64_t _buffer[RNG_BUFFER_SIZE];

};

#endif
