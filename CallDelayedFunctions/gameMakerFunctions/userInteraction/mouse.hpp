#ifdef DEFINE_WRAPPERS
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(get_mouse_x)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(get_mouse_y)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(get_mouse_button)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(get_mouse_lastbutton)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(mouse_check_button)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(mouse_check_button_pressed)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(mouse_check_button_released)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(mouse_wheel_up)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(mouse_wheel_down)
#endif

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
double get_mouse_x();
#ifdef DEFINE_WRAPPERS
double get_mouse_x()
{
    return addDelayedFunctionCall(FP_get_mouse_x, 1);
}
#endif

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
double get_mouse_y();
#ifdef DEFINE_WRAPPERS
double get_mouse_y()
{
    return addDelayedFunctionCall(FP_get_mouse_y, 1);
}
#endif

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
double get_mouse_button();
#ifdef DEFINE_WRAPPERS
double get_mouse_button()
{
    return addDelayedFunctionCall(FP_get_mouse_button, 1);
}
#endif

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
double get_mouse_lastbutton();
#ifdef DEFINE_WRAPPERS
double get_mouse_lastbutton()
{
    return addDelayedFunctionCall(FP_get_mouse_lastbutton, 1);
}
#endif

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
double mouse_check_button(double numb);
#ifdef DEFINE_WRAPPERS
double mouse_check_button(double numb)
{
    return addDelayedFunctionCall(FP_mouse_check_button, 1, numb);
}
#endif

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
double mouse_check_button_pressed(double numb);
#ifdef DEFINE_WRAPPERS
double mouse_check_button_pressed(double numb)
{
    return addDelayedFunctionCall(FP_mouse_check_button_pressed, 1, numb);
}
#endif

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
double mouse_check_button_released(double numb);
#ifdef DEFINE_WRAPPERS
double mouse_check_button_released(double numb)
{
    addDelayedFunctionCall(FP_mouse_check_button_released, 1, numb);
}
#endif

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
double mouse_wheel_up();
#ifdef DEFINE_WRAPPERS
double mouse_wheel_up()
{
    return addDelayedFunctionCall(FP_mouse_wheel_up, 1);
}
#endif

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
double mouse_wheel_down();
#ifdef DEFINE_WRAPPERS
double mouse_wheel_down()
{
    return addDelayedFunctionCall(FP_mouse_wheel_down, 1);
}
#endif
