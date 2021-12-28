local module = require "funcs"
local env_funcs = require "env_funcs"

module.setImports(env_funcs)
module.init()

print("start");
local x = module.exports.fill()
print(module.imports.env.wasm_get(x, 0))

--put code here

--object (bindings)
--module.bindings.ClassName()

--global funcs (bindings)
--module.bindings.namespace.Func()

--global funcs (non bindings)
--module.exports.Func()

--imports
--module.imports.Func()