local ffi = require("ffi")

-------------------------

ffi.cdef[[
const char* testfun();
]]
print(ffi.C.testfun())
print(ffi.string(ffi.C.testfun()))
print("")

-------------------------

ffi.cdef[[
typedef struct airplane airplane;
airplane* new_airplane();
void del_airplane(airplane* air);
void air_setSeat(airplane* air, int _seat);
int air_getSeat(airplane* air);
void air_setType(airplane* air, const char* _type);
const char* air_getType(airplane* air);
]]
local mt = {
	__index = {
		setSeat = ffi.C.air_setSeat,
		getSeat = ffi.C.air_getSeat,
		setType = ffi.C.air_setType,
		getType = ffi.C.air_getType,
	}
}
ffi.metatype("airplane", mt)

--local a = ffi.C.new_airplane()
local a = ffi.gc(ffi.C.new_airplane(), ffi.C.del_airplane)
a:setSeat(250)
a:setType("boeing747")
local airseat = a:getSeat()
local airtype = ffi.string(a:getType())
print("airplane seat: "..airseat)
print("airplane type: "..airtype)

-------------------------

ffi.cdef[[
int printf(const char *fmt, ...);
]]
ffi.C.printf("%s", "\nLuajit test End!\n")

-------------------------