global.delayCallDLL_removeDelayedFunctionCall  = external_define("CallDelayedFunctions.dll", "removeDelayedFunctionCall",  dll_cdecl, ty_real,   0);
global.delayCallDLL_getInputText               = external_define("CallDelayedFunctions.dll", "getInputText",               dll_cdecl, ty_string, 1, ty_real);
global.delayCallDLL_getInputNumber             = external_define("CallDelayedFunctions.dll", "getInputNumber",             dll_cdecl, ty_real,   1, ty_real);
global.delayCallDLL_getInputType               = external_define("CallDelayedFunctions.dll", "getInputType",               dll_cdecl, ty_real,   1, ty_real);
global.delayCallDLL_getFunction                = external_define("CallDelayedFunctions.dll", "getFunction",                dll_cdecl, ty_real,   0);
global.delayCallDLL_setDelayedOutput           = external_define("CallDelayedFunctions.dll", "setDelayedOutput",           dll_cdecl, ty_real,   1, ty_real);
global.delayCallDLL_getHasOutput               = external_define("CallDelayedFunctions.dll", "getHasOutput",               dll_cdecl, ty_real,   0);
global.delayCallDLL_isThereDelayedFunctionCall = external_define("CallDelayedFunctions.dll", "isThereDelayedFunctionCall", dll_cdecl, ty_real,   0);

global.delayCallDLL_export_d3d_draw_block = external_define("CallDelayedFunctions.dll", "export_d3d_draw_block", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_d3d_draw_block, scr_wrapper_d3d_draw_block);

global.delayCallDLL_export_d3d_draw_cylinder = external_define("CallDelayedFunctions.dll", "export_d3d_draw_cylinder", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_d3d_draw_cylinder, scr_wrapper_d3d_draw_cylinder);

global.delayCallDLL_export_d3d_draw_cone = external_define("CallDelayedFunctions.dll", "export_d3d_draw_cone", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_d3d_draw_cone, scr_wrapper_d3d_draw_cone);

global.delayCallDLL_export_d3d_draw_ellipsoid = external_define("CallDelayedFunctions.dll", "export_d3d_draw_ellipsoid", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_d3d_draw_ellipsoid, scr_wrapper_d3d_draw_ellipsoid);

global.delayCallDLL_export_d3d_draw_wall = external_define("CallDelayedFunctions.dll", "export_d3d_draw_wall", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_d3d_draw_wall, scr_wrapper_d3d_draw_wall);

global.delayCallDLL_export_d3d_draw_floor = external_define("CallDelayedFunctions.dll", "export_d3d_draw_floor", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_d3d_draw_floor, scr_wrapper_d3d_draw_floor);

global.delayCallDLL_export_d3d_transform_set_identity = external_define("CallDelayedFunctions.dll", "export_d3d_transform_set_identity", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_d3d_transform_set_identity, scr_wrapper_d3d_transform_set_identity);

global.delayCallDLL_export_d3d_transform_add_rotation_x = external_define("CallDelayedFunctions.dll", "export_d3d_transform_add_rotation_x", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_d3d_transform_add_rotation_x, scr_wrapper_d3d_transform_add_rotation_x);

global.delayCallDLL_export_d3d_transform_add_rotation_y = external_define("CallDelayedFunctions.dll", "export_d3d_transform_add_rotation_y", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_d3d_transform_add_rotation_y, scr_wrapper_d3d_transform_add_rotation_y);

global.delayCallDLL_export_d3d_transform_add_rotation_z = external_define("CallDelayedFunctions.dll", "export_d3d_transform_add_rotation_z", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_d3d_transform_add_rotation_z, scr_wrapper_d3d_transform_add_rotation_z);

global.delayCallDLL_export_d3d_transform_add_translation = external_define("CallDelayedFunctions.dll", "export_d3d_transform_add_translation", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_d3d_transform_add_translation, scr_wrapper_d3d_transform_add_translation);

global.delayCallDLL_export_d3d_transform_add_rotation_axis = external_define("CallDelayedFunctions.dll", "export_d3d_transform_add_rotation_axis", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_d3d_transform_add_rotation_axis, scr_wrapper_d3d_transform_add_rotation_axis);

global.delayCallDLL_export_sprite_get_texture = external_define("CallDelayedFunctions.dll", "export_sprite_get_texture", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_sprite_get_texture, scr_wrapper_sprite_get_texture);

global.delayCallDLL_export_d3d_primitive_begin = external_define("CallDelayedFunctions.dll", "export_d3d_primitive_begin", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_d3d_primitive_begin, scr_wrapper_d3d_primitive_begin);

global.delayCallDLL_export_d3d_vertex = external_define("CallDelayedFunctions.dll", "export_d3d_vertex", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_d3d_vertex, scr_wrapper_d3d_vertex);

global.delayCallDLL_export_d3d_vertex_color = external_define("CallDelayedFunctions.dll", "export_d3d_vertex_color", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_d3d_vertex_color, scr_wrapper_d3d_vertex_color);

global.delayCallDLL_export_d3d_primitive_end = external_define("CallDelayedFunctions.dll", "export_d3d_primitive_end", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_d3d_primitive_end, scr_wrapper_d3d_primitive_end);

global.delayCallDLL_export_d3d_model_draw = external_define("CallDelayedFunctions.dll", "export_d3d_model_draw", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_d3d_model_draw, scr_wrapper_d3d_model_draw);

global.delayCallDLL_export_d3d_model_create = external_define("CallDelayedFunctions.dll", "export_d3d_model_create", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_d3d_model_create, scr_wrapper_d3d_model_create);

global.delayCallDLL_export_d3d_model_load = external_define("CallDelayedFunctions.dll", "export_d3d_model_load", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_d3d_model_load, scr_wrapper_d3d_model_load);

global.delayCallDLL_export_sprite_add = external_define("CallDelayedFunctions.dll", "export_sprite_add", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_sprite_add, scr_wrapper_sprite_add);

global.delayCallDLL_export_draw_sprite = external_define("CallDelayedFunctions.dll", "export_draw_sprite", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_draw_sprite, scr_wrapper_draw_sprite);

global.delayCallDLL_export_d3d_transform_add_scaling = external_define("CallDelayedFunctions.dll", "export_d3d_transform_add_scaling", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_d3d_transform_add_scaling, scr_wrapper_d3d_transform_add_scaling);

global.delayCallDLL_export_d3d_set_projection_ortho = external_define("CallDelayedFunctions.dll", "export_d3d_set_projection_ortho", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_d3d_set_projection_ortho, scr_wrapper_d3d_set_projection_ortho);

global.delayCallDLL_export_d3d_set_projection_perspective = external_define("CallDelayedFunctions.dll", "export_d3d_set_projection_perspective", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_d3d_set_projection_perspective, scr_wrapper_d3d_set_projection_perspective);

global.delayCallDLL_export_d3d_set_projection = external_define("CallDelayedFunctions.dll", "export_d3d_set_projection", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_d3d_set_projection, scr_wrapper_d3d_set_projection);

global.delayCallDLL_export_d3d_model_primitive_begin = external_define("CallDelayedFunctions.dll", "export_d3d_model_primitive_begin", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_d3d_model_primitive_begin, scr_wrapper_d3d_model_primitive_begin);

global.delayCallDLL_export_d3d_model_vertex_texture = external_define("CallDelayedFunctions.dll", "export_d3d_model_vertex_texture", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_d3d_model_vertex_texture, scr_wrapper_d3d_model_vertex_texture);

global.delayCallDLL_export_d3d_model_primitive_end = external_define("CallDelayedFunctions.dll", "export_d3d_model_primitive_end", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_d3d_model_primitive_end, scr_wrapper_d3d_model_primitive_end);

global.delayCallDLL_export_d3d_model_destroy = external_define("CallDelayedFunctions.dll", "export_d3d_model_destroy", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_d3d_model_destroy, scr_wrapper_d3d_model_destroy);

global.delayCallDLL_export_d3d_start = external_define("CallDelayedFunctions.dll", "export_d3d_start", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_d3d_start, scr_wrapper_d3d_start);

global.delayCallDLL_export_d3d_set_fog = external_define("CallDelayedFunctions.dll", "export_d3d_set_fog", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_d3d_set_fog, scr_wrapper_d3d_set_fog);

global.delayCallDLL_export_d3d_set_lighting = external_define("CallDelayedFunctions.dll", "export_d3d_set_lighting", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_d3d_set_lighting, scr_wrapper_d3d_set_lighting);

global.delayCallDLL_export_draw_text = external_define("CallDelayedFunctions.dll", "export_draw_text", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_draw_text, scr_wrapper_draw_text);

global.delayCallDLL_export_game_end = external_define("CallDelayedFunctions.dll", "export_game_end", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_game_end, scr_wrapper_game_end);

global.delayCallDLL_export_keyboard_check = external_define("CallDelayedFunctions.dll", "export_keyboard_check", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_keyboard_check, scr_wrapper_keyboard_check);

global.delayCallDLL_export_set_keyboard_lastkey = external_define("CallDelayedFunctions.dll", "export_set_keyboard_lastkey", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_set_keyboard_lastkey, scr_wrapper_set_keyboard_lastkey);

global.delayCallDLL_export_get_keyboard_lastkey = external_define("CallDelayedFunctions.dll", "export_get_keyboard_lastkey", dll_cdecl, ty_real, 1, ty_real);
external_call(global.delayCallDLL_export_get_keyboard_lastkey, scr_wrapper_get_keyboard_lastkey);

global.init_dll_function_call_loop = external_define("CallDelayedFunctions.dll", "init_dll_function_call_loop", dll_cdecl, ty_real, 0);
global.call_dll_function = external_define("CallDelayedFunctions.dll", "call_dll_function", dll_cdecl, ty_real, 1, ty_real);
global.is_dll_function_call_complete = external_define("CallDelayedFunctions.dll", "is_dll_function_call_complete", dll_cdecl, ty_real, 0);
global.prime_argument_real = external_define("CallDelayedFunctions.dll", "prime_argument_real", dll_cdecl, ty_real, 2, ty_real, ty_real);
global.prime_argument_string = external_define("CallDelayedFunctions.dll", "prime_argument_string", dll_cdecl, ty_real, 2, ty_real, ty_string);

global.gameLoopInit = scr_get_DLL_function("CallDelayedFunctions.dll", "gameLoopInit");
global.gameLoopBeginStep = scr_get_DLL_function("CallDelayedFunctions.dll", "gameLoopBeginStep");
global.gameLoopStep = scr_get_DLL_function("CallDelayedFunctions.dll", "gameLoopStep");
global.gameLoopDraw = scr_get_DLL_function("CallDelayedFunctions.dll", "gameLoopDraw");

