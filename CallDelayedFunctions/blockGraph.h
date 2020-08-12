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
    double* surfaceModel;
    unsigned int blockUpdateListLength;
    unsigned int* blockUpdateList;
    unsigned int blockUpdateListTempLength;
    unsigned int* blockUpdateListTemp;
} blockGraph;

double blockGraph_create3DModel();
double blockGraph_setUpBlockGraphList();
double blockGraph_addToBlockUpdateList(double blockID);
double blockGraph_updateBlockGraphWithList();
double blockGraph_addToTempBlockUpdateList(double blockID);
double blockGraph_getSideWithPoint(double blockID, double x, double y, double z);
double blockGraph_loadFromFile(char* fileName);
double blockGraph_drawEvent();

extern blockGraph* blkGph;
