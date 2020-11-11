#ifndef CONTROLS_H
#define CONTROLS_H
typedef struct control
{
    /** \brief
     *
     */
    unsigned int gameControl;

    /** \brief
     *
     */
    unsigned int gameControlType;

    /** \brief
     *
     */
    unsigned int gameControlControllerID;

    /** \brief
     *
     */
    unsigned int gameControlPress;

    /** \brief
     *
     */
    unsigned int gameControlPressed;

    /** \brief
     *
     */
    int keyboardCheck;
} control;

typedef struct controlSet
{
    /** \brief
     *
     */
    control control_cancel;

    /** \brief
     *
     */
    control control_confirm;

    /** \brief
     *
     */
    control control_itemTwo;

    /** \brief
     *
     */
    control control_itemOne;

    /** \brief
     *
     */
    control control_pause;

    /** \brief
     *
     */
    control control_blockRight;

    /** \brief
     *
     */
    control control_blockLeft;

    /** \brief
     *
     */
    control control_moveLeft;

    /** \brief
     *
     */
    control control_moveDown;

    /** \brief
     *
     */
    control control_moveRight;

    /** \brief
     *
     */
    control control_moveUp;
} controlSet;

#define controlType_keyboard 0
#define controlType_controller 1
#define controlType_dPadUp 2
#define controlType_dPadRight 3
#define controlType_dPadDown 4
#define controlType_dPadLeft 5
#define controlType_xUp 6
#define controlType_xDown 7
#define controlType_yUp 8
#define controlType_yDown 9
#define controlType_zUp 10
#define controlType_zDown 11
#define controlType_rUp 12
#define controlType_rDown 13
#define controlType_uUp 14
#define controlType_uDown 15
#define controlType_vUp 16
#define controlType_vDown 17

extern controlSet gameControl;

void initGameControl();
void updateGameControlBeginStep();
void updateGameControlStep();

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
double setGameControl_cancel(double pressed);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
double setGameControl_confirm(double pressed);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
double setGameControl_itemTwo(double pressed);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
double setGameControl_itemOne(double pressed);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
double setGameControl_pause(double pressed);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
double setGameControl_blockRight(double pressed);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
double setGameControl_blockLeft(double pressed);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
double setGameControl_moveLeft(double pressed);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
double setGameControl_moveDown(double pressed);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
double setGameControl_moveRight(double pressed);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
double setGameControl_moveUp(double pressed);
#endif
