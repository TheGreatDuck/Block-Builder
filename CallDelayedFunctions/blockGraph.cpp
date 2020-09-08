#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <math.h>
#include "delayed_function_calls.h"
#include "blockGraph.h"
#include "blockAlchemy.h"

#define blockModelCapacity 2.0

blockGraph* blkGph;

static void blockGraph_createSubmodel(int modelID)
{
    /*d3d_model_create(&blkGph->surfaceModel[modelID]);
    d3d_model_primitive_begin(&blkGph->surfaceModel[modelID],pr_trianglelist);

    for (unsigned int i = modelID*blockModelCapacity; i < blkGph->numberOfBlockModels && i < (modelID+1)*blockModelCapacity; i += 1)
    {
        vector p1 = blkGph->blockGraph[i].v[1];
        double p2x = blkGph->blockGraph[i].v[2].x;
        double p2y = blkGph->blockGraph[i].v[2].y;
        double p2z = blkGph->blockGraph[i].v[2].z;
        double p3x = blkGph->blockGraph[i].v[3].x;
        double p3y = blkGph->blockGraph[i].v[3].y;
        double p3z = blkGph->blockGraph[i].v[3].z;
        double p4x = blkGph->blockGraph[i].v[4].x;
        double p4y = blkGph->blockGraph[i].v[4].y;
        double p4z = blkGph->blockGraph[i].v[4].z;

        double pn1x = -blkGph->blockGraph[i].n[1].x;
        double pn1y = -blkGph->blockGraph[i].n[1].y;
        double pn1z = -blkGph->blockGraph[i].n[1].z;
        double pn2x = -blkGph->blockGraph[i].n[2].x;
        double pn2y = -blkGph->blockGraph[i].n[2].y;
        double pn2z = -blkGph->blockGraph[i].n[2].z;
        double pn3x = -blkGph->blockGraph[i].n[3].x;
        double pn3y = -blkGph->blockGraph[i].n[3].y;
        double pn3z = -blkGph->blockGraph[i].n[3].z;
        double pn4x = -blkGph->blockGraph[i].n[4].x;
        double pn4y = -blkGph->blockGraph[i].n[4].y;
        double pn4z = -blkGph->blockGraph[i].n[4].z;

        double bt = blkGph->blockGraph[i].type;

        d3d_model_vertex_normal_texture(&blkGph->surfaceModel[modelID],p1x,p1y,p1z,pn1x,pn1y,pn1z,bt/numberOfBlocks_3D,0+0.5*blkGph->blockGraph[i].removable);
        d3d_model_vertex_normal_texture(&blkGph->surfaceModelmodelID],p3x,p3y,p3z,pn3x,pn3y,pn3z,bt/numberOfBlocks_3D,0.5+0.5*blkGph->blockGraph[i].removable);
        d3d_model_vertex_normal_texture(&blkGph->surfaceModel[modelID],p4x,p4y,p4z,pn4x,pn4y,pn4z,(bt+1)/numberOfBlocks_3D,0.5+0.5*blkGph->blockGraph[i].removable);

        d3d_model_vertex_normal_texture(&blkGph->surfaceModel[modelID],p1x,p1y,p1z,pn1x,pn1y,pn1z,bt/numberOfBlocks_3D,0+0.5*blkGph->blockGraph[i].removable);
        d3d_model_vertex_normal_texture(&blkGph->surfaceModel[modelID],p4x,p4y,p4z,pn4x,pn4y,pn4z,(bt+1)/numberOfBlocks_3D,0.5+0.5*blkGph->blockGraph[i].removable);
        d3d_model_vertex_normal_texture(&blkGph->surfaceModel[modelID],p2x,p2y,p2z,pn2x,pn2y,pn2z,(bt+1)/numberOfBlocks_3D,0+0.5*blkGph->blockGraph[i].removable);


        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p1.x,p1.y,p1.z,bt/numberOfBlocks_3D,0);
        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p3x,p3y,p3z,bt/numberOfBlocks_3D,1);
        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p4x,p4y,p4z,(bt+1)/numberOfBlocks_3D,1);

        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p1.x,p1.y,p1.z,bt/numberOfBlocks_3D,0);
        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p4x,p4y,p4z,(bt+1)/numberOfBlocks_3D,1);
        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p2x,p2y,p2z,(bt+1)/numberOfBlocks_3D,0);

        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p1.x,p1.y,p1.z,bt/numberOfBlocks_3D,0);
        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p4x,p4y,p4z,(bt+1)/numberOfBlocks_3D,1);
        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p3x,p3y,p3z,bt/numberOfBlocks_3D,1);

        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p1.x,p1.y,p1.z,bt/numberOfBlocks_3D,0);
        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p2x,p2y,p2z,(bt+1)/numberOfBlocks_3D,0);
        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p4x,p4y,p4z,(bt+1)/numberOfBlocks_3D,1);



        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p1.x+pn1x,p1.y+pn1y,p1.z+pn1z,0/numberOfBlocks_3D,0);
        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p1.x,p1.y,p1.z,0/numberOfBlocks_3D,1);
        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p2x,p2y,p2z,(0+1)/numberOfBlocks_3D,1);

        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p1.x+pn1x,p1.y+pn1y,p1.z+pn1z,0/numberOfBlocks_3D,0);
        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p2x,p2y,p2z,(0+1)/numberOfBlocks_3D,1);
        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p2x+pn2x,p2y+pn2y,p2z+pn2z,(0+1)/numberOfBlocks_3D,0);
    }

    d3d_model_primitive_end(&blkGph->surfaceModel[modelID]);*/
}

double blockGraph_create3DModel()
{
    //d3d_model_create(&blkGph->fillerModel);
    blkGph->numberOfModels = ceil(blkGph->numberOfBlockModels/blockModelCapacity);
    for (unsigned int i = 0; i < blkGph->numberOfModels; i+=1)
    {
        blockGraph_createSubmodel(i);
    }

    return 1.0;
}

static int blockGraph_blockArithmetic(int blockID)
{
    int s1 = blkGph->blockGraph[blockID].adj[1];
    int s2 = blkGph->blockGraph[blockID].adj[2];
    int s3 = blkGph->blockGraph[blockID].adj[3];
    int s4 = blkGph->blockGraph[blockID].adj[4];

    int b1;
    int b2;
    int b3;
    int b4;

    if (s1 != -1)
    {
        b1 = blkGph->blockGraph[s1].type;
    } else
    {
        b1 = -1;
    }

    if (s2 != -1)
    {
        b2 = blkGph->blockGraph[s2].type;
    } else
    {
        b2 = -1;
    }

    if (s3 != -1)
    {
        b3 = blkGph->blockGraph[s3].type;
    } else
    {
        b3 = -1;
    }

    if (s4 != -1)
    {
        b4 = blkGph->blockGraph[s4].type;
    } else
    {
        b4 = -1;
    }

    return scr_changeBlock(blkGph->blockGraph[blockID].type,b1,b2,b3,b4);
}

void blockGraph_setUpBlockGraphList()
{
    blkGph->blockUpdateListLength = 0;

    double tempBlocks[blkGph->numberOfBlockModels];

    for (unsigned int i = 0; i < blkGph->numberOfBlockModels; i+=1)
    {
        int newType = blockGraph_blockArithmetic(i);

        if (blkGph->blockGraph[i].type != newType)
        {
            blockGraph_addToBlockUpdateList(i);
            blockGraph_addToBlockUpdateList(blkGph->blockGraph[i].adj[1]);
            blockGraph_addToBlockUpdateList(blkGph->blockGraph[i].adj[2]);
            blockGraph_addToBlockUpdateList(blkGph->blockGraph[i].adj[3]);
            blockGraph_addToBlockUpdateList(blkGph->blockGraph[i].adj[4]);
        }

        tempBlocks[i] = newType;
    }

    for (unsigned int i = 0; i < blkGph->numberOfBlockModels; i += 1)
    {
        blkGph->blockGraph[i].type = tempBlocks[i];
        blkGph->blockGraphDirtyBit[i] = 0;
    }
}

void blockGraph_addToBlockUpdateList(int blockID)
{
    if (blockID >= 0)
    {
        if (blkGph->blockGraphDirtyBit[blockID] == 0)
        {
            blkGph->blockUpdateList[blkGph->blockUpdateListLength] = blockID;
            blkGph->blockUpdateListLength += 1;
            blkGph->blockGraphDirtyBit[blockID] = 1;
        }
    }
}

double blockGraph_updateBlockGraphWithList()
{
    unsigned int changed[(int)ceil(blkGph->numberOfBlockModels/blockModelCapacity)];
    for (unsigned int i = 0; i  < ceil(blkGph->numberOfBlockModels/blockModelCapacity); i+=1)
    {
        changed[i] = 0;
    }

    int tempBlocks[blkGph->numberOfBlockModels];

    for (unsigned int k = 0; k < blkGph->blockUpdateListLength; k += 1)
    {
        unsigned int i = blkGph->blockUpdateList[k];

        if (blkGph->blockGraph[i].type != blockGraph_blockArithmetic(i))
        {
            blockGraph_addToTempBlockUpdateList(i);
            blockGraph_addToTempBlockUpdateList(blkGph->blockGraph[i].adj[1]);
            blockGraph_addToTempBlockUpdateList(blkGph->blockGraph[i].adj[2]);
            blockGraph_addToTempBlockUpdateList(blkGph->blockGraph[i].adj[3]);
            blockGraph_addToTempBlockUpdateList(blkGph->blockGraph[i].adj[4]);
            changed[(int)floor(i/blockModelCapacity)] = 1;
        }

        tempBlocks[i] = blockGraph_blockArithmetic(i);
    }

    for (unsigned int k = 0; k < blkGph->blockUpdateListLength; k += 1)
    {
        unsigned int i = blkGph->blockUpdateList[k];
        blkGph->blockGraph[i].type = tempBlocks[i];
    }

    blkGph->blockUpdateListLength = 0;

    for (unsigned int k = 0; k < blkGph->blockUpdateListTempLength; k += 1)
    {
        blkGph->blockUpdateList[k] = blkGph->blockUpdateListTemp[k];
        unsigned int i = blkGph->blockUpdateListTemp[k];
        blkGph->blockGraphDirtyBit[i] = 0;
    }

    blkGph->blockUpdateListLength = blkGph->blockUpdateListTempLength;
    blkGph->blockUpdateListTempLength = 0;
    for (unsigned int i = 0; i < ceil(blkGph->numberOfBlockModels/blockModelCapacity); i+=1)
    {
        if (changed[i] == 1)
        {
            //d3d_model_destroy(blkGph->surfaceModel[i]);
            blockGraph_createSubmodel(i);
        }
    }

    return 1.0;
}

void blockGraph_addToTempBlockUpdateList(int blockID)
{
    if (blockID >= 0)
    {
        if (blkGph->blockGraphDirtyBit[(int)blockID] == 0)
        {
            blkGph->blockUpdateListTemp[blkGph->blockUpdateListTempLength] = blockID;
            blkGph->blockUpdateListTempLength += 1;
            blkGph->blockGraphDirtyBit[(int)blockID] = 1;
        }
    }
}

int blockGraph_getSideWithPoint(int blockID, double x, double y, double z)
{
    double p1x = blkGph->blockGraph[(int)blockID].v[1].x;
    double p1y = blkGph->blockGraph[(int)blockID].v[1].y;
    double p1z = blkGph->blockGraph[(int)blockID].v[1].z;

    double p2x = blkGph->blockGraph[(int)blockID].v[2].x;
    double p2y = blkGph->blockGraph[(int)blockID].v[2].y;
    double p2z = blkGph->blockGraph[(int)blockID].v[2].z;

    double p3x = blkGph->blockGraph[(int)blockID].v[3].x;
    double p3y = blkGph->blockGraph[(int)blockID].v[3].y;
    double p3z = blkGph->blockGraph[(int)blockID].v[3].z;

    double p4x = blkGph->blockGraph[(int)blockID].v[4].x;
    double p4y = blkGph->blockGraph[(int)blockID].v[4].y;
    double p4z = blkGph->blockGraph[(int)blockID].v[4].z;

    double vx = x;
    double vy = y;
    double vz = z;

    if ((p1x + p3x)/2 == vx && (p1y + p3y)/2 == vy && (p1z + p3z)/2 == vz)
    {
        return 0;
    }

    if ((p4x + p3x)/2 == vx && (p4y + p3y)/2 == vy && (p4z + p3z)/2 == vz)
    {
        return 1;
    }

    if ((p2x + p4x)/2 == vx && (p2y + p4y)/2 == vy && (p2z + p4z)/2 == vz)
    {
        return 2;
    }

    if ((p1x + p2x)/2 == vx && (p1y + p2y)/2 == vy && (p1z + p2z)/2 == vz)
    {
        return 3;
    }

    return -1;
}

void blockGraph_loadFromFile(char* fileName)
{
    FILE* file = fopen(fileName, "r");

    if (blkGph)
    {
        free(blkGph->blockGraph);
        free(blkGph->surfaceModel);
        free(blkGph->blockGraphDirtyBit);
        free(blkGph->blockUpdateList);
        free(blkGph->blockUpdateListTemp);
        free(blkGph);
    }

    blkGph = (blockGraph*)malloc(sizeof(blockGraph));

    fscanf(file, "%u\n", &blkGph->numberOfBlockModels);

    blkGph->blockGraph = (block3D*)malloc(blkGph->numberOfBlockModels*sizeof(block3D));

    blkGph->blockGraphDirtyBit = (int*)malloc(blkGph->numberOfBlockModels*sizeof(int));
    memset(blkGph->blockGraphDirtyBit, 0, blkGph->numberOfBlockModels*sizeof(int));

    blkGph->numberOfModels = ceil(blkGph->numberOfBlockModels/blockModelCapacity);
    blkGph->surfaceModel = (int*)malloc(blkGph->numberOfModels*sizeof(int));

    blkGph->blockUpdateListLength = 0;
    blkGph->blockUpdateList = (unsigned int*)malloc(blkGph->numberOfBlockModels*sizeof(unsigned int));

    blkGph->blockUpdateListTempLength = 0;
    blkGph->blockUpdateListTemp = (unsigned int*)malloc(blkGph->numberOfBlockModels*sizeof(unsigned int));

    for (unsigned int i = 0; i < blkGph->numberOfBlockModels; i += 1)
    {
        fscanf(file, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %d %d %d %d %d %d %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf \n",
                     &blkGph->blockGraph[i].v[1].x, &blkGph->blockGraph[i].v[1].y, &blkGph->blockGraph[i].v[1].z,
                     &blkGph->blockGraph[i].v[2].x, &blkGph->blockGraph[i].v[2].y, &blkGph->blockGraph[i].v[2].z,
                     &blkGph->blockGraph[i].v[3].x, &blkGph->blockGraph[i].v[3].y, &blkGph->blockGraph[i].v[3].z,
                     &blkGph->blockGraph[i].v[4].x, &blkGph->blockGraph[i].v[4].y, &blkGph->blockGraph[i].v[4].z,
                     &blkGph->blockGraph[i].adj[1], &blkGph->blockGraph[i].adj[2], &blkGph->blockGraph[i].adj[3], &blkGph->blockGraph[i].adj[4],
                     &blkGph->blockGraph[i].type,
                     &blkGph->blockGraph[i].removable,
                     &blkGph->blockGraph[i].n[1].x, &blkGph->blockGraph[i].n[1].y, &blkGph->blockGraph[i].n[1].z,
                     &blkGph->blockGraph[i].n[2].x, &blkGph->blockGraph[i].n[2].y, &blkGph->blockGraph[i].n[2].z,
                     &blkGph->blockGraph[i].n[3].x, &blkGph->blockGraph[i].n[3].y, &blkGph->blockGraph[i].n[3].z,
                     &blkGph->blockGraph[i].n[4].x, &blkGph->blockGraph[i].n[4].y, &blkGph->blockGraph[i].n[4].z);
    }

    fclose(file);
}

void blockGraph_drawEvent()
{
    for (int i = 0; i  < ceil(blkGph->numberOfBlockModels/blockModelCapacity); i+=1)
    {
        //d3d_model_draw(&blkGph->surfaceModel[i],0,0,0, &blkGph->tex_blockTexture);
    }
}
