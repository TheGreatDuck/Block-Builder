typedef struct block3D
{
    int type;

    double v1x;
    double v1y;
    double v1z;
    double v2x;
    double v2y;
    double v2z;
    double v3x;
    double v3y;
    double v3z;
    double v4x;
    double v4y;
    double v4z;

    double n1x;
    double n1y;
    double n1z;
    double n2x;
    double n2y;
    double n2z;
    double n3x;
    double n3y;
    double n3z;
    double n4x;
    double n4y;
    double n4z;

    int removable;

    int adj1;
    int adj2;
    int adj3;
    int adj4;
} block3D;

typedef struct blockGraph
{
    unsigned int numberOfBlockModels;
    block3D* blockGraph;
    unsigned int numberOfModels;
    int* surfaceModel;
    int  fillerModel;
    int* blockGraphDirtyBit;
    unsigned int blockUpdateListLength;
    unsigned int* blockUpdateList;
    unsigned int blockUpdateListTempLength;
    unsigned int* blockUpdateListTemp;
    int spr_blockTexture;
    int tex_blockTexture;
} blockGraph;

double blockGraph_create3DModel();
void blockGraph_setUpBlockGraphList();
void blockGraph_addToBlockUpdateList(int blockID);
double blockGraph_updateBlockGraphWithList();
void blockGraph_addToTempBlockUpdateList(int blockID);
int blockGraph_getSideWithPoint(int blockID, double x, double y, double z);
void blockGraph_loadFromFile(char* fileName);
void blockGraph_drawEvent();

extern blockGraph* blkGph;
