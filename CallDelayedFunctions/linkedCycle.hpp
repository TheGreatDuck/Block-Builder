typedef struct linkedNode
{
    /** \brief
     *
     */
    void*  data;

    /** \brief
     *
     */
    struct linkedNode* next;

    /** \brief
     *
     */
    struct linkedNode* previous;
} linkedNode;

typedef struct linkedCycle
{
    /** \brief
     *
     */
    linkedNode* current;

    /** \brief
     *
     */
    int         length;
} linkedCycle;

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
linkedCycle* createCycle();

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void insertAfterCurrent(linkedCycle* cycle, double data);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void removeAfterCurrent(linkedCycle* cycle);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int getLength(linkedCycle* cycle);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void* getCurrentData(linkedCycle* cycle);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void next(linkedCycle* cycle);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void previous(linkedCycle* cycle);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
linkedNode* getCurrentNode(linkedCycle* cycle);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void setCurrentNode(linkedCycle* cycle, linkedNode* node);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void setLength(linkedCycle* cycle, int length);
