#ifndef __LIB_RNG_JKISS_HEADER__
#define __LIB_RNG_JKISS_HEADER__
#pragma once

#include <stdint.h>
#include "rng.h"

class JKISS : public RNG {
        public:
                JKISS();
                RNG* split();
                void seed(uint32_t);
                void seed(RNG*);
                uint32_t get_uint32();
        private:
                uint32_t _x, _y, _z, _c;
};

#endif
