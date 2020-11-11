var getter;
var dll_file_name
var function_name;

dll_file_name = argument[0];
function_name = argument[1];

getter = external_define(dll_file_name, "get_" + function_name, dll_cdecl, ty_real, 0);
return external_call(getter);

