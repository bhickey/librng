#ifndef __LIB_RNG_RNG_HEADER__
#define __LIB_RNG_RNG_HEADER__ 
#pragma once

#include <stdint.h>

class RNG {
        public:
                virtual void seed(RNG*) = 0;
                virtual RNG* split() = 0;
                virtual uint32_t get_uint32() = 0;
                virtual uint64_t get_uint64() = 0;

                double get_double();
                float get_float();
                bool get_bool();
                uint64_t get_bits(short);
                uint64_t get_nonzero_bits(short);

};

#endif
