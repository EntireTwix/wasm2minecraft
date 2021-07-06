local env = {
    --delete operator (C++)
    _ZdlPv = function(reg) reg = nil end,
    
    --new operator (C++)
    _Znwm = function(size) return 0 end,
    _Znwj = function(size) return 0 end,
    
    --memory operations
    memset = function(reg, val, size) return nil end, --yet to be implemented
    memcpy = function(reg0, reg1, size) 
        reg0 = reg1
        return reg0 
    end
    }
    
    return { env = env } 
