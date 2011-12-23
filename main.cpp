#include <iostream>
#include "include/airplane.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#define APIEXPORT __declspec(dllexport)
#else
#define APIEXPORT
#endif

extern "C"{
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

using namespace std;

extern "C"{
    __declspec(dllexport) const char* testfun()
    {
        return "This is a test function";
    }

    __declspec(dllexport) airplane* new_airplane(){
        return new airplane;
    }

    __declspec(dllexport) void del_airplane(airplane* air){
        delete air;
    }

    __declspec(dllexport) void air_setSeat(airplane* air, int _seat){
        air->setSeat(_seat);
    }

    __declspec(dllexport) int air_getSeat(airplane* air){
        return air->getSeat();
    }

    __declspec(dllexport) void air_setType(airplane* air, const char* _type){
        air->setType(_type);
    }

    __declspec(dllexport) const char* air_getType(airplane* air){
        return air->getType();
    }
}

int main()
{
    cout << "Luajit test Strat!\n" << endl;

    lua_State* L = luaL_newstate();
	luaL_openlibs(L);
    luaL_dofile(L, "script.lua");
    lua_close(L);

    return 0;
}
