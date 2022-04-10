#include <cstdint>
#include <cstddef>
#include <cstring>

#define any void *

extern "C"
{
    // put environmentally defined function as extern here
    extern void wasm_set(char* ptr, char value, size_t pos);
    extern char wasm_get(const char* ptr, size_t pos);
    extern void* memset(void *ptr, int value, size_t num);
    extern void* memcpy(void *to, const void *from, size_t sz);
    extern size_t strlen(const char *start);
}

// put code here or in the above extern if you want C function symbols
