### Disclaimer: Only works with Lua 5.2+ and requires wasm2lua: https://github.com/SwadicalRag/wasm2lua
### Disclaimer 2: I did not make wasm2lua, this repo is simply explicit setup/tips for OpenComputers mod 
# Steps

1)write your header

2)write your webidl interface

3)use lua-webidl to generate cpp code
```
lua-webidl --libmode --cpp funcs.idl funcs.cpp
```

4)append your .hpp code to the top of your generated .cpp file

5)use a site like https://mbebenita.github.io/WasmExplorer/ or https://wasdk.github.io/WasmFiddle/ or locally compile your .cpp to WAT

6)use the WASM (WAT) file and bindings to generate the lua file with wasm2lua

```
wasm2lua --pureLua -b funcs.idl --libmode test.wasm funcs.lua --discardExportSymbols
```

## Tips:

- test your header file before usage
- check out https://github.com/SwadicalRag/wasm2lua/blob/master/HOWTO-BINDINGS.md
- check out https://heycam.github.io/webidl/#introduction
- make sure to initilize your member variables
- if you dont need any bindings for classes simply do step 1, 5, then ```wasm2lua --pureLua test.wasm funcs.lua --discardExportSymbols```, heavily consider wrapping C functions in `extern "C" { }` for simplicity
- if you're using bindings, `INLINE` all functions that are going to be bound before pasting into the generated `funcs.cpp`

## Known Bugs with fixes:

- .env calls are nil

  define the needed function in env_funcs.lua 
  
- labels bug out

  your lua version is too old

- return by value is buggy

  only use [Value] Tag for non-user defined types

- function __BINDER__.instantiateClass(classBase,ptr,luaOwned) issues
  
  replace with
  ```lua
  function __BINDER__.instantiateClass(classBase,ptr,luaOwned)
    local ins = setmetatable({__ptr = ptr,__luaOwned = luaOwned},classBase)
    ins.__gcproxy = {}
    if ins:__gc() ~= nil then
      getmetatable(ins.__gcproxy).__gc = function() ins:__gc() end
    end
    classBase.__cache[ptr] = ins
    return ins
  end
  ```
  
- `__MALLOC__`, replace with
  ```lua
  local heap_start = 0
  local __MALLOC__ = function(size) 
    local temp = heap_start 
    heap_start = heap_start + size + 1
    return temp
  end
  local __FREE__ = function() return end
  ```
