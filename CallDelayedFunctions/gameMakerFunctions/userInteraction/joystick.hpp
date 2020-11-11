#ifdef DEFINE_WRAPPERS
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(joystick_exists)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(joystick_name)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(joystick_axes)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(joystick_buttons)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(joystick_has_pov)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(joystick_direction)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(joystick_check_button)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(joystick_xpos)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(joystick_ypos)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(joystick_zpos)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(joystick_rpos)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(joystick_upos)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(joystick_vpos)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(joystick_pov)
#endif

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
double joystick_exists(int id);
#ifdef DEFINE_WRAPPERS
double joystick_exists(int id)
{
    return addDelayedFunctionCall(FP_joystick_exists, 1, id);
}
#endif

#if 0
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void joystick_name(int id, int* result);
#ifdef DEFINE_WRAPPERS
void joystick_name(int id, int* result)
{
    addDelayedFunctionCall(FP_joystick_name, result, 1, id);
}
#endif
#endif

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void joystick_axes(int id);
#ifdef DEFINE_WRAPPERS
void joystick_axes(int id)
{
    addDelayedFunctionCall(FP_joystick_axes, 1, id);
}
#endif

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
double joystick_buttons(int id);
#ifdef DEFINE_WRAPPERS
double joystick_buttons(int id)
{
    return addDelayedFunctionCall(FP_joystick_buttons, 1, id);
}
#endif

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
double joystick_has_pov(int id);
#ifdef DEFINE_WRAPPERS
double joystick_has_pov(int id)
{
    return addDelayedFunctionCall(FP_joystick_has_pov, 1, id);
}
#endif

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
double joystick_direction(int id);
#ifdef DEFINE_WRAPPERS
double joystick_direction(int id)
{
    return addDelayedFunctionCall(FP_joystick_direction, 1, id);
}
#endif

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
double joystick_check_button(int id, int numb);
#ifdef DEFINE_WRAPPERS
double joystick_check_button(int id, int numb)
{
    return addDelayedFunctionCall(FP_joystick_check_button, 1, id, numb);
}
#endif

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
/*joystick_xpos(int id, int* result);
void joystick_xpos(int id, int* result)
{
    addDelayedFunctionCall(FP_joystick_xpos, result, 1, id);
}*/

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
//joystick_ypos(int id, int* result);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
//joystick_zpos(int id, int* result);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
//joystick_rpos(int id, int* result);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
//joystick_upos(int id, int* result);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
//joystick_vpos(int id, int* result);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
//joystick_pov(int id, int* result);
