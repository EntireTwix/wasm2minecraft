#include <cstdint>
#include <cstddef>

#define INLINE __attribute__((always_inline)) inline
#define any void *

template <typename T>
void lua_memset(T *ptr, T val, size_t sz)
{
    for (size_t i = 0; i < sz; ++i)
    {
        ptr[i] = val;
    }
}

template <typename T, typename T2>
void lua_memcpy(T *to, T2 *from, size_t sz)
{
    for (size_t i = 0; i < sz; ++i)
    {
        from[i] = to[i];
    }
}

extern "C"
{
    size_t lua_strlen(const char *start)
    {
        const char *end = start;
        for (; *end != '\0'; ++end)
            ;
        return end - start;
    }
}

// put code here
