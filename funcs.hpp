#include <cstdint>
#include <cstddef>

#define INLINE constexpr
#define any void *

extern "C"
{
    // extern put environmentally defined function here
    extern void wasm_set(char* ptr, char value, size_t pos);
    extern char wasm_get(const char* ptr, size_t pos);
}

// put code here or in the above extern if you want C function symbols
