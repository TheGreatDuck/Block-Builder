while (scr_delayCallDLL_isThereDelayedFunctionCall())
{
    if (scr_delayCallDLL_getHasOutput())
    {
        delayedOutput = script_execute(scr_delayCallDLL_getFunction(), scr_delayCallDLL_getInput(0),
                                                                       scr_delayCallDLL_getInput(1),
                                                                       scr_delayCallDLL_getInput(2),
                                                                       scr_delayCallDLL_getInput(3),
                                                                       scr_delayCallDLL_getInput(4),
                                                                       scr_delayCallDLL_getInput(5),
                                                                       scr_delayCallDLL_getInput(6),
                                                                       scr_delayCallDLL_getInput(7),
                                                                       scr_delayCallDLL_getInput(8),
                                                                       scr_delayCallDLL_getInput(9),
                                                                       scr_delayCallDLL_getInput(10),
                                                                       scr_delayCallDLL_getInput(11),
                                                                       scr_delayCallDLL_getInput(12),
                                                                       scr_delayCallDLL_getInput(13));
        scr_delayCallDLL_setDelayedOutput(delayedOutput);
    } else
    {
        script_execute(scr_delayCallDLL_getFunction(), scr_delayCallDLL_getInput(0),
                                                       scr_delayCallDLL_getInput(1),
                                                       scr_delayCallDLL_getInput(2),
                                                       scr_delayCallDLL_getInput(3),
                                                       scr_delayCallDLL_getInput(4),
                                                       scr_delayCallDLL_getInput(5),
                                                       scr_delayCallDLL_getInput(6),
                                                       scr_delayCallDLL_getInput(7),
                                                       scr_delayCallDLL_getInput(8),
                                                       scr_delayCallDLL_getInput(9),
                                                       scr_delayCallDLL_getInput(10),
                                                       scr_delayCallDLL_getInput(11),
                                                       scr_delayCallDLL_getInput(12),
                                                       scr_delayCallDLL_getInput(13));
    }
    
    scr_delayCallDLL_removeDelayedFunctionCall();
}
