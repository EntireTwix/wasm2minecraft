#include <cstdint>
#include <cstddef>

#define INLINE __attribute__((always_inline)) inline
#define any void *

extern "C"
{
    static void* wasm_memcpy(void *to, const void *from, size_t sz)
    {
        char* cto = (char*)to;
        char* cfrom = (char*)from;
        for (size_t i = 0; i < sz; ++i)
        {
            cto[i] = cfrom[i];
        }
        return to;
    }
    
    static size_t wasm_strlen(const char *start)
    {
        const char *end = start;
        for (; *end != '\0'; ++end)
            ;
        return end - start;
    }
}

// put code here or in the above extern if you want C function symbols
