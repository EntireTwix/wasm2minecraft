### Disclaimer: Only works with Lua 5.2+

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
wasm2lua --pureLua -b funcs.idl --libmode funcs.wasm funcs.lua
```

## Tips:

- test your header file before usage
- check out https://github.com/SwadicalRag/wasm2lua/blob/master/HOWTO-BINDINGS.md
- check out https://heycam.github.io/webidl/#introduction
- make sure to initilize your member variables
- if you dont need any bindings for classes simply do step 1, 5, then ```wasm2lua --pureLua funcs.wasm funcs.lua```

## Known Bugs with fixes:

- .env calls are nil

  - define the needed function in env_funcs.lua

- bit is nil

  - wget https://raw.githubusercontent.com/daurnimator/lua-http/master/http/bit.lua

    then replace

    ```lua
    local bit = bit
    ```

    with

    ```lua
    local bit = require "bit"
    ```
    if that fails
    ```lua
    local bit = bit32
    ```

- labels bug out
  - your lua version is too old

- return by value is buggy
  - only use [Value] Tag for non-user defined types

- function __BINDER__.instantiateClass(classBase,ptr,luaOwned) issues
  - replace with
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
  
