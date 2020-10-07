#ifdef DEFINE_WRAPPERS
ADD_FUNCTION(game_end)
#endif

void game_end();
#ifdef DEFINE_WRAPPERS
void game_end()
{
    addDelayedFunctionCall(FP_game_end, NULL, 0);
}
#endif
