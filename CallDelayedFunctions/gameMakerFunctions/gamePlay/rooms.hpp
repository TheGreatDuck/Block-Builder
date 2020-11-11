#ifdef DEFINE_WRAPPERS
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(game_end)
#endif

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void game_end();
#ifdef DEFINE_WRAPPERS
void game_end()
{
    addDelayedFunctionCall(FP_game_end, 0);
}
#endif
