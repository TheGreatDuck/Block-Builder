#include "vector.hpp"

#ifndef BLOCKGRAPH_H
#define BLOCKGRAPH_H
typedef struct block3D
{
    int type;
    int entityID;

    vector v[4];
    vector n[4];
    vector position;
    vector side[4];
    vector motionPoints[4][5];
    vector axisX[4];
    vector dir[4];
    vector normal;

    int removable;
    int adj[4];
    int adjSide[4];
} block3D;

typedef struct blockGraph
{
    unsigned int numberOfBlockModels;
    block3D* blockGraph;
    int surfaceModel;
    int  fillerModel;
    int* blockGraphDirtyBit;
    unsigned int blockUpdateListLength;
    unsigned int* blockUpdateList;
    unsigned int blockUpdateListTempLength;
    unsigned int* blockUpdateListTemp;
    int spr_blockTexture;
    int tex_blockTexture;
} blockGraph;

#ifndef ENTITY_DLL
void blockGraph_initBlockModelAssets(const char* worldName);
void blockGraph_create3DModel();
void blockGraph_setUpBlockGraphList();
void blockGraph_addToBlockUpdateList(int blockID);
void blockGraph_updateBlockGraphWithList();
void blockGraph_loadFromFile(const char* fileName);
void blockGraph_drawEvent();
void d3d_transform_add_block_matrix(int blockID, int sideFacing, int motion, int movingSide);
int blockGraph_addBlock(vector v0, vector v1, vector v2, vector v3);
int blockGraph_getAdjacentID(int blockID, int side);

extern blockGraph* blkGph;
#endif
#endif
