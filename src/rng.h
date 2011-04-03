#ifndef __LIB_RNG_RNG_HEADER__
#define __LIB_RNG_RNG_HEADER__ 
#pragma once

#include <math.h>
#include <stdint.h>

class RNG {
        public:
                virtual void seed(RNG*) = 0;
                virtual RNG* split() = 0;
                virtual uint32_t get_uint32();
                virtual uint64_t get_uint64();

                void seed_with(uint32_t);
                int get_int();
                int get_int(int);
                double get_normal(double mu = 0.0, double sigma = 0.0);
                double get_double();
                float get_float();
                bool get_bool();
                int get_geometric();
                uint64_t get_bits(short);
                uint64_t get_nonzero_bits(short);

};

#endif
