local module = require "funcs"
local env_funcs = require "env_funcs"

module.setImports(env_funcs)
module.init()

local a = module.bindings.Example()
print(a:Get())
a:Toggle()
print(a:Get())

print(module.bindings.global.Answer())
print(module.exports.True())
