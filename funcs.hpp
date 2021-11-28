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

// put code here
