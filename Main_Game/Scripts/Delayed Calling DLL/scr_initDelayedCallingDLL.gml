global.delayCallDLL_removeDelayedFunctionCall  = external_define("CallDelayedFunctions.dll", "removeDelayedFunctionCall",  dll_cdecl, ty_real,   0);
global.delayCallDLL_getInputText               = external_define("CallDelayedFunctions.dll", "getInputText",               dll_cdecl, ty_string, 1, ty_real);
global.delayCallDLL_getInputNumber             = external_define("CallDelayedFunctions.dll", "getInputNumber",             dll_cdecl, ty_real,   1, ty_real);
global.delayCallDLL_getInputType               = external_define("CallDelayedFunctions.dll", "getInputType",               dll_cdecl, ty_real,   1, ty_real);
global.delayCallDLL_getFunction                = external_define("CallDelayedFunctions.dll", "getFunction",                dll_cdecl, ty_real,   0);
global.delayCallDLL_setDelayedOutput           = external_define("CallDelayedFunctions.dll", "setDelayedOutput",           dll_cdecl, ty_real,   1, ty_real);
global.delayCallDLL_getHasOutput               = external_define("CallDelayedFunctions.dll", "getHasOutput",               dll_cdecl, ty_real,   0);
global.delayCallDLL_isThereDelayedFunctionCall = external_define("CallDelayedFunctions.dll", "isThereDelayedFunctionCall", dll_cdecl, ty_real,   0);

scr_delayCallDLL_exportWrapperFunctions();

global.init_dll_function_call_loop = external_define("CallDelayedFunctions.dll", "init_dll_function_call_loop", dll_cdecl, ty_real, 0);
global.call_dll_function = external_define("CallDelayedFunctions.dll", "call_dll_function", dll_cdecl, ty_real, 1, ty_real);
global.is_dll_function_call_complete = external_define("CallDelayedFunctions.dll", "is_dll_function_call_complete", dll_cdecl, ty_real, 0);
global.prime_argument_real = external_define("CallDelayedFunctions.dll", "prime_argument_real", dll_cdecl, ty_real, 2, ty_real, ty_real);
global.prime_argument_string = external_define("CallDelayedFunctions.dll", "prime_argument_string", dll_cdecl, ty_real, 2, ty_real, ty_string);

global.gameLoopInit = scr_get_DLL_function("CallDelayedFunctions.dll", "gameLoopInit");
global.gameLoopBeginStep = scr_get_DLL_function("CallDelayedFunctions.dll", "gameLoopBeginStep");
global.gameLoopStep = scr_get_DLL_function("CallDelayedFunctions.dll", "gameLoopStep");
global.gameLoopDraw = scr_get_DLL_function("CallDelayedFunctions.dll", "gameLoopDraw");

external_call(global.init_dll_function_call_loop);
