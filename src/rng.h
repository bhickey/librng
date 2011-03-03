#ifndef __LIB_RNG_RNG_HEADER__
#define __LIB_RNG_RNG_HEADER__ 
#pragma once

#include <stdint.h>

class RNG {
        public:
                virtual void seed(RNG*);
                virtual RNG split();
                virtual uint32_t get_uint32();
                virtual uint64_t get_uint64();
                double get_double();
                float get_float();
                bool get_bool();
        protected:
                virtual void fill_buffer();
                uint64_t get_bits(short);
                uint64_t _buffer;
                uint8_t  _buffer_size;
};

#endif
