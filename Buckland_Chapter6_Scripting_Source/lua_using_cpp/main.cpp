extern "C"
{
  #include <lua.h>
  #include <lualib.h>
  #include <lauxlib.h>
}

#pragma comment(lib, "lua.lib")
#pragma comment(lib, "lualib.lib")

#include <iostream>
#include <string>

#include "LuaHelperFunctions.h"
#include "RockPaperScissors.h"
#include "misc/ConsoleUtils.h"




int main()
{
  //create a lua state
  lua_State* pL = lua_open();

  OpenLuaLibraries(pL);

  //register the functions with lua
  lua_register(pL, "cpp_GetAIMove", cpp_GetAIMove);
  lua_register(pL, "cpp_EvaluateTheGuesses", cpp_EvaluateTheGuesses);

  //run the script
  RunLuaScript(pL, "Rock_Paper_Scissors_Using_C++_Funcs.lua");
  
  //tidy up
  lua_close(pL);

  std::cout << "\n\n\n";

  //wait for a keypress before exiting
  PressAnyKeyToContinue();
    
  return 0;
}