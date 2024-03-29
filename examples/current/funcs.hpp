#include <cstdint>
#include <cstddef>
#include <cstring>

#define INLINE constexpr
#define any void *

extern "C"
{
    // extern put environmentally defined function here
    extern void wasm_set(char* ptr, char value, size_t pos);
    extern char wasm_get(const char* ptr, size_t pos);
    
    bool True() 
    {
        return true;
    }
}

class Example
{
private:
    bool a;
    
public:
    void Toggle()
    {
        a = !a;
    }
    bool Get() const
    {
        return a;
    }
};

INLINE int Answer()
{
    return 42;
}
