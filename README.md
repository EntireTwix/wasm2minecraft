### Disclaimer: Only works with Lua 5.2+

# Steps

1)write your header

2)write your webidl interface

3)use lua-webidl to generate cpp code

4)append your .hpp code to the top of your generated .cpp file

```
lua-webidl --libmode --cpp funcs.idl funcs.cpp
```

5)use a site like https://mbebenita.github.io/WasmExplorer/ or locally compile your .cpp to WAT

6)use the WASM (WAT) file and bindings to generate the lua file with wasm2lua

```
wasm2lua --pureLua -b funcs.idl --libmode funcs.wasm funcs.lua
```

## Tips:

- test your header file before usage
- check out https://github.com/SwadicalRag/wasm2lua/blob/master/HOWTO-BINDINGS.md
- check out https://heycam.github.io/webidl/#introduction

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
  - just return without [Value] tag and itll still be as value
