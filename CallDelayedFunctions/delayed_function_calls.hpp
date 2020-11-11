#define GMEXPORT extern "C" __declspec(dllexport)
//define GMEXPORT extern "C"

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
GMEXPORT double removeDelayedFunctionCall();

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
GMEXPORT double getInputDelayedVariable(double input);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
GMEXPORT char* getInputText(double input);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
GMEXPORT double getInputNumber(double input);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
GMEXPORT double getInputType(double input);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
GMEXPORT double getFunction();

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
GMEXPORT double setDelayedOutput(double value);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
GMEXPORT double getHasOutput();

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
GMEXPORT double isThereDelayedFunctionCall();

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
GMEXPORT double is_dll_function_call_complete();
