#ifndef __LIB_RNG_RNG_INTERNAL_HEADER__
#define __LIB_RNG_RNG_INTERNAL_HEADER__ 
#pragma once

#include <math.h>
#include <time.h>
#include <stdint.h>

// LCG included for use only as a seeder of other generators.
// (ie. expanding a 32-bit seed to fill the generator's statespace)
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
