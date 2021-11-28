#include <stdint.h>

struct RGB
{
    RGB() {}
    RGB(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b) {}

    uint8_t r, g, b;
};
