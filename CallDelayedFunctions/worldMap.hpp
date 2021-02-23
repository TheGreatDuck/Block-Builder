extern unsigned int map_width;
extern unsigned int map_height;
extern unsigned int map_player_x;
extern unsigned int map_player_y;
extern unsigned int* map_icons;
extern unsigned int* map_collision;
extern unsigned int* map_path;

typedef struct
{
    unsigned int xPos;
    unsigned int yPos;
    unsigned int level;
    unsigned int side;
} map_lock;

extern unsigned int numberOfLocks;
extern map_lock* map_locks;

typedef struct
{
    unsigned int xPos;
    unsigned int yPos;
    unsigned int level;
    unsigned int north;
    unsigned int west;
    unsigned int east;
    unsigned int south;
} map_level;

extern unsigned int numberOfLevels;
extern map_level* map_levels;
extern int* map_levelCompletion;

void load_world(const char* worldName);
void save_world(const char* worldName);
