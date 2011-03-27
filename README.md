#libRNG

libRNG is a [public domain](http://unlicense.org/) collection of pseudo-random number generators for C++. It provides several efficient and statistically robust generators.

## Usage

* Build using `make`.
* Link against individual objects, or use `build/librng.so`.

## Notes

`split()` returns a new generator, seeded from `this`. There is no guarantee that the generators will be independent in any robust sense, but the implementations of `split()` make a good faith effort to do something reasonable.

`seed_with(uint32_t)` constructs a linear-congrugential generator (LCG), which is then used as the argument to `seed(RNG*)`. LCGs have some bad properties: correlation between sequential outputs, and distribution of outputs in a few hyperplanes. This will be replaced with a 32-bit Xorshift generator, or a complementary multiply with carry generator.

## Acknowledgements
The generators presented here are largely adapted from the public domain C sources in David Jones's manuscript _Good   
Practice in (Pseudo) Random Number Generation for Bioinformatics Applications_ ([pdf](http://www.cs.ucl.ac.uk/staff/d.jones/GoodPracticeRNG.pdf)).

The interface is inspired by Haskell's [System.Random](http://www.haskell.org/ghc/docs/7.0.2/html/libraries/random-1.0.0.3/System-Random.html).
