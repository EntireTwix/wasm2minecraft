#include <cstdint>
#include <cstddef>

#define INLINE __attribute__((always_inline)) inline

#include <random>
std::default_random_engine generator;
std::uniform_real_distribution<double> distribution(0.0, 1.0);

double GetRandom() { return distribution(generator); }
