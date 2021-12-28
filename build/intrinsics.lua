__IMPORTS__.env.wasm_set=function(a,b,c)__MEMORY_WRITE_8__(mem_0,bit_tobit(a+c),b)end;
__IMPORTS__.env.wasm_get=function(a,b)local c;c=__MEMORY_READ_8__(mem_0,bit_tobit(a+b))c=bit_arshift(bit_lshift(c,24),24)return c end;
__IMPORTS__.env.memset=function(a,b,c)local d,e;if(c==0 and 1 or 0)~=0 then goto f end;d=0;e=bit_arshift(bit_lshift(b,24),24)b=e;while true do::g::__IMPORTS__.env.wasm_set(a,b,d)e=bit_tobit(d+1)d=e;if(c~=d and 1 or 0)~=0 then goto g end;break end::f::do return a end end
__IMPORTS__.env.memcpy=function(a,b,c)local d,f;if(c==0 and 1 or 0)~=0 then goto g end;d=a;while true do::h::f=__MEMORY_READ_8__(mem_0,b)__MEMORY_WRITE_8__(mem_0,d,f)f=bit_tobit(d+1)d=f;f=bit_tobit(b+1)b=f;f=bit_tobit(c+-1)c=f;if c~=0 then goto h end;break end::g::do return a end end;
__IMPORTS__.env.strlen=function(a)local b,c;b=bit_tobit(a+-1)while true do::i::c=bit_tobit(b+1)b=c;c=__MEMORY_READ_8__(mem_0,b)if c~=0 then goto i end;break end;do return bit_tobit(b-a)end end
__IMPORTS__.env._Znwm=function(a)MALLOC(a)end
__IMPORTS__.env._Znwj=function(a)MALLOC(a)end
__IMPORTS__.env._Znam=function(a)MALLOC(a)end
__IMPORTS__.env._Znaj=function(a)MALLOC(a)end