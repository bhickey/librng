#ifndef __LIB_RNG_RNG_INTERNAL_HEADER__
#define __LIB_RNG_RNG_INTERNAL_HEADER__ 
#pragma once

#include <math.h>
#include <time.h>
#include <stdint.h>

class RNG {
        public:
                virtual void seed(RNG*) = 0;
                virtual RNG* split() = 0;
                virtual uint32_t get_uint32() = 0;
                virtual uint64_t get_uint64() = 0;
                
                void seed_with(uint32_t);
                int get_int();
                int get_int(int);
                double get_normal(double mu = 0.0, double sigma = 0.0);
                double get_double();
                float get_float();
                bool get_bool();
                uint64_t get_bits(short);
                uint64_t get_nonzero_bits(short);

};

class LCG : public RNG {
        public:
                LCG();
                LCG(uint32_t);
                void seed(RNG*);
                RNG* split();
                uint32_t get_uint32();
                uint64_t get_uint64();
        private:
                uint32_t _state;
};
#endif
