local module = require "funcs"
local env_funcs = require "env_funcs"

module.setImports(env_funcs)
module.init()

--put code here

--object (bindings)
--module.bindings.ClassName()

--global funcs (bindings)
--module.bindings.namespace.Func()

--global funcs (non bindings)
--module.exports.Func()

--imports
--module.imports.Func()