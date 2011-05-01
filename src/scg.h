#ifndef __LIB_RNG_SCG_HEADER__
#define __LIB_RNG_SCG_HEADER__
#pragma once

#include <stdint.h>
#include "rng.h"

class SCG : public RNG {
    public:
        SCG();
        SCG(const SCG*);
        RNG* split();
        void seed(uint32_t);
        void seed(RNG*);
        uint32_t get_uint32();
        void skip(uint64_t);
        void step();
    private:
        uint64_t _x, _y, _offset;
};

#endif
