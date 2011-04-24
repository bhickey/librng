#include "cmwc.h"

// A complementary-multiplyiply with carry generator.
//  a = 4293967651
//  b = 2^32
//  p = ab + 1
//  period ~= 2^57 

CMWC::CMWC() {
        _multiply = 1234567890;
        _carry = 654321098;
}

RNG*
CMWC::split() {
	RNG* k = new CMWC();
	k->seed(this);
	return k;
}

void
CMWC::seed(RNG *rng) {
    _carry = 0;
    _multiply = 0;

    while(!_carry && !_multiply) {
        _carry = rng->get_uint32();
        _multiply = rng->get_uint32();
    }
}

uint32_t
CMWC::get_uint32()
{
    uint64_t t = 0xFFF0BF23 * _multiply + _carry;
    _carry = t >> 32;
    return (_multiply = 0xFFFFFFFF - (0xFFFFFFFF & t));
}
