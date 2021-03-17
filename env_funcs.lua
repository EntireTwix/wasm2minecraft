local env = {
--delete operator (C++)
_ZdlPv = function(reg) reg = nil end,

--new operator (C++)
_Znwm = function(size) return 0 end,
_Znwj = function(size) return 0 end
}

--lua dumb
local all = { env = env } 
return all
