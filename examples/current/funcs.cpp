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

#define __CFUNC(name) \
    __attribute__((__import_module__("webidl_cfuncs"), __import_name__(#name)))
#define export __attribute__((visibility( "default" )))
template <typename T> struct _LuaArray {
    public:
    _LuaArray(size_t inLen) : totalLen(inLen), len(inLen) {array = new T[inLen]; knownLen = true;};
    _LuaArray(size_t inLen,T* inArray) : totalLen(inLen), len(inLen) {array = inArray; knownLen = true; isOwner = false;};
    _LuaArray(T* inArray) {array = inArray; isOwner = false;};
    ~_LuaArray() {if(isOwner) {delete[] array;}};
    bool isOwner = true;
    bool knownLen = false;
    size_t totalLen = 0;
    size_t len = 0;
    T* array;
};
export extern "C" int _webidl_lua_global_Answer() {return Answer() ;};
export extern "C" Example* _webidl_lua_Example_Example() {return new Example() ;};
export extern "C" void _webidl_lua_Example_Toggle(Example* self) { self->Toggle() ;};
export extern "C" bool _webidl_lua_Example_Get(Example* self) {return self->Get() ;};
export extern "C" void _webidl_lua_Example__delete_void(Example* self) {delete self;};
#undef __CFUNC
#undef export
extern "C" void _webidl_main_yield() __attribute__((__import_module__("webidl_internal"), __import_name__("main_yield")));
int main() {_webidl_main_yield(); return 0;}
