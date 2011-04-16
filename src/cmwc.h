#ifndef __LIB_RNG_CMWC_HEADER__
#define __LIB_RNG_CMWC_HEADER__
#pragma once

#include <stdint.h>
#include "rng.h"

class CMWC : public RNG {
    public:
            CMWC();
            RNG* split();
            void seed(RNG*);
            uint32_t get_uint32();
    private:
            uint32_t _multiply;
            uint32_t _carry;
};

#endif
