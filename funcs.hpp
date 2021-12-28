#include <cstdint>
#include <cstddef>

#define INLINE __attribute__((always_inline)) inline
#define any void *

extern "C"
{
    // extern put environmentally defined function here
    extern void wasm_set(char* ptr, char value, size_t pos);
    extern char wasm_get(const char* ptr, size_t pos);
    extern void* memset(void *ptr, int value, size_t num);
    extern void* memcpy(void *to, const void *from, size_t sz);
    extern size_t strlen(const char *start);
}

// put code here or in the above extern if you want C function symbols
