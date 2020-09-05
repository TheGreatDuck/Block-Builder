#include "vector.h"

typedef struct block3D
{
    int type;

    vector v1;
    vector v2;
    vector v3;
    vector v4;

    vector n1;
    vector n2;
    vector n3;
    vector n4;

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
