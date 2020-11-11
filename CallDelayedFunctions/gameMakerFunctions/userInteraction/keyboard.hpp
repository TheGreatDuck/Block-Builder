#ifdef DEFINE_WRAPPERS
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(set_keyboard_lastkey)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(get_keyboard_lastkey)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(keyboard_check)
#endif

//vk_nokey
//vk_anykey
#define vk_left 37
#define vk_right 39
#define vk_up 38
#define vk_down 40
#define vk_enter 13
#define vk_escape 27
#define vk_space 32
#define vk_shift 16
#define vk_control 17
//#define vk_alt
//#define vk_backspace
//#define vk_tab
//#define vk_home
//#define vk_end
//#define vk_delete
//#define vk_insert
//#define vk_pageup
//#define vk_pagedown
//#define vk_pause
//#define vk_printscreen
//#define vk_f1
//#define vk_f2
//#define vk_f3
//#define vk_f4
//#define vk_f5
//#define vk_f6
//#define vk_f7
//#define vk_f8
//#define vk_f9
//#define vk_f10
//#define vk_f11
//#define vk_f12
//#define vk_numpad0
//#define vk_numpad1
//#define vk_numpad2
//#define vk_numpad3
//#define vk_numpad4
//#define vk_numpad5
//#define vk_numpad6
//#define vk_numpad7
//#define vk_numpad8
//#define vk_numpad9
//#define vk_multiply
//#define vk_divide
//#define vk_add
//#define vk_subtract
//#define vk_decimal

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void set_keyboard_lastkey(int value);
#ifdef DEFINE_WRAPPERS
void set_keyboard_lastkey(int value)
{
    addDelayedFunctionCall(FP_set_keyboard_lastkey, 0, value);
}
#endif

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
double get_keyboard_lastkey();
#ifdef DEFINE_WRAPPERS
double get_keyboard_lastkey()
{
    return addDelayedFunctionCall(FP_get_keyboard_lastkey, 1);
}
#endif

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
double keyboard_check(int key);
#ifdef DEFINE_WRAPPERS
double keyboard_check(int key)
{
    return addDelayedFunctionCall(FP_keyboard_check, 1, key);
}
#endif
