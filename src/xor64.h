#ifndef __LIB_RNG_XOR64_HEADER__
#define __LIB_RNG_XOR64_HEADER__
#pragma once

#include <stdint.h>
#include "rng.h"

class XOR64 : public RNG {
    public:
            XOR64();
            RNG* split();
            void seed(RNG*);
            uint64_t get_uint64();
    private:
            uint64_t _state;
};

#endif
