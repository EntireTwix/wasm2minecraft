#include <random>
std::default_random_engine generator;
std::uniform_real_distribution<double> distribution(0.0, 1.0);

extern "C"
{
    double GetRandom() { return distribution(generator); }
}
