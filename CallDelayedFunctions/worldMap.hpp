extern unsigned int map_width;
extern unsigned int map_height;
extern unsigned int map_player_x;
extern unsigned int map_player_y;
extern unsigned int* map_icons;
extern unsigned int* map_collision;
extern unsigned int* map_path;

typedef struct
{
    /** \brief
     *
     */
    unsigned int xPos;

    /** \brief
     *
     */
    unsigned int yPos;

    /** \brief
     *
     */
    unsigned int level;

    /** \brief
     *
     */
    unsigned int side;
} map_lock;

extern unsigned int numberOfLocks;
extern map_lock* map_locks;

typedef struct
{
    /** \brief
     *
     */
    unsigned int xPos;

    /** \brief
     *
     */
    unsigned int yPos;

    /** \brief
     *
     */
    unsigned int level;

    /** \brief
     *
     */
    unsigned int north;

    /** \brief
     *
     */
    unsigned int west;

    /** \brief
     *
     */
    unsigned int east;

    /** \brief
     *
     */
    unsigned int south;
} map_level;

extern unsigned int numberOfLevels;
extern map_level* map_levels;
extern int* map_levelCompletion;

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void load_world(const char* program_directory, const char* worldName);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void save_world(const char* program_directory, const char* worldName);
