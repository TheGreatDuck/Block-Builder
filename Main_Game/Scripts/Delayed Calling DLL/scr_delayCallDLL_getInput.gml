inputType = scr_delayCallDLL_getInputType(argument[0]);

if (inputType == 0)
{
    return scr_delayCallDLL_getInputNumber(argument[0]);
} else if (inputType == 1)
{
    return scr_delayCallDLL_getInputText(argument[0]);
} else if (inputType == 2)
{
    return scr_delayCallDLL_getInputDelayedVariable(argument[0]);
}
