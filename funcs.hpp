#include <cstdint>
#include <cstddef>

#define INLINE __attribute__((always_inline)) inline
#define any void *

extern "C"
{
    void* lua_memcpy(void *to, const void *from, size_t sz)
    {
        char* cto = (char*)to;
        char* cfrom = (char*)from;
        for (size_t i = 0; i < sz; ++i)
        {
            cto[i] = cfrom[i];
        }
        return to;
    }
    
    size_t lua_strlen(const char *start)
    {
        const char *end = start;
        for (; *end != '\0'; ++end)
            ;
        return end - start;
    }
}

// put code here
