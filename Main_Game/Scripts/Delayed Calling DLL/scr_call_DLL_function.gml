var function_to_call;
function_to_call = argument[0];

var number_of_arguments;
number_of_arguments = argument[1];

var i;
for (i = 0; i < number_of_arguments; i+= 1)
{
    if (is_real(argument[i+2]))
        external_call(global.prime_argument_real, i, argument[i+2]);
    if (is_string(argument[i+2]))
        external_call(global.prime_argument_string, i, argument[i+2]);
}

external_call(global.call_dll_function, function_to_call);
while (external_call(global.is_dll_function_call_complete) == 0)
{
    scr_delayCallDLL_callQueuedFunctions();
}
scr_delayCallDLL_callQueuedFunctions();
