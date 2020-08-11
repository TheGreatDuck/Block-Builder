#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <math.h>
#include "delayed_function_calls.h"
#include "blockGraph.h"
#include "blockAlchemy.h"

#define blockModelCapacity 5000
#define numberOfBlocks_3D  5000

blockGraph* blkGph;

static double blockGraph_createSubmodel(double modelID)
{
    int model;
    d3d_model_create(&model);
    //d3d_model_primitive_begin(model,pr_trianglelist);

    for (unsigned int i = modelID*blockModelCapacity; i < blkGph->numberOfBlockModels && i < (modelID+1)*blockModelCapacity; i += 1)
    {
        double p1x = blkGph->blockGraph[i].v1x;
        double p1y = blkGph->blockGraph[i].v1y;
        double p1z = blkGph->blockGraph[i].v1z;
        double p2x = blkGph->blockGraph[i].v2x;
        double p2y = blkGph->blockGraph[i].v2y;
        double p2z = blkGph->blockGraph[i].v2z;
        double p3x = blkGph->blockGraph[i].v3x;
        double p3y = blkGph->blockGraph[i].v3y;
        double p3z = blkGph->blockGraph[i].v3z;
        double p4x = blkGph->blockGraph[i].v4x;
        double p4y = blkGph->blockGraph[i].v4y;
        double p4z = blkGph->blockGraph[i].v4z;

        double pn1x = -4*blkGph->blockGraph[i].n1x;
        double pn1y = -4*blkGph->blockGraph[i].n1y;
        double pn1z = -4*blkGph->blockGraph[i].n1z;
        double pn2x = -4*blkGph->blockGraph[i].n2x;
        double pn2y = -4*blkGph->blockGraph[i].n2y;
        double pn2z = -4*blkGph->blockGraph[i].n2z;
        double pn3x = -4*blkGph->blockGraph[i].n3x;
        double pn3y = -4*blkGph->blockGraph[i].n3y;
        double pn3z = -4*blkGph->blockGraph[i].n3z;
        double pn4x = -4*blkGph->blockGraph[i].n4x;
        double pn4y = -4*blkGph->blockGraph[i].n4y;
        double pn4z = -4*blkGph->blockGraph[i].n4z;

        double bt = blkGph->blockGraph[i].type;

        /*d3d_model_vertex_normal_texture(model,p1x,p1y,p1z,pn1x,pn1y,pn1z,bt/numberOfBlocks_3D,0+0.5*blkGph->blockGraph[i].removable);
        d3d_model_vertex_normal_texture(model,p3x,p3y,p3z,pn3x,pn3y,pn3z,bt/numberOfBlocks_3D,0.5+0.5*blkGph->blockGraph[i].removable);
        d3d_model_vertex_normal_texture(model,p4x,p4y,p4z,pn4x,pn4y,pn4z,(bt+1)/numberOfBlocks_3D,0.5+0.5*blkGph->blockGraph[i].removable);

        d3d_model_vertex_normal_texture(model,p1x,p1y,p1z,pn1x,pn1y,pn1z,bt/numberOfBlocks_3D,0+0.5*blkGph->blockGraph[i].removable);
        d3d_model_vertex_normal_texture(model,p4x,p4y,p4z,pn4x,pn4y,pn4z,(bt+1)/numberOfBlocks_3D,0.5+0.5*blkGph->blockGraph[i].removable);
        d3d_model_vertex_normal_texture(model,p2x,p2y,p2z,pn2x,pn2y,pn2z,(bt+1)/numberOfBlocks_3D,0+0.5*blkGph->blockGraph[i].removable);*/


        /*d3d_model_vertex_texture(model,p4x,p4y,p4z,(bt+1)/8,1);
        d3d_model_vertex_texture(model,p3x,p3y,p3z,bt/8,1);
        d3d_model_vertex_texture(model,p1x,p1y,p1z,bt/8,0);

        d3d_model_vertex_texture(model,p2x,p2y,p2z,(bt+1)/8,0);
        d3d_model_vertex_texture(model,p4x,p4y,p4z,(bt+1)/8,1);
        d3d_model_vertex_texture(model,p1x,p1y,p1z,bt/8,0);*/
    }

    //d3d_model_primitive_end(model);
    return model;
}

GMEXPORT double blockGraph_create3DModel()
{
    //fillerModel = d3d_model_create();
    blkGph->numberOfModels = ceil(blkGph->numberOfBlockModels/blockModelCapacity);
    for (unsigned int i = 0; i < blkGph->numberOfModels; i+=1)
    {
        blkGph->surfaceModel[i] = blockGraph_createSubmodel(i);
    }

    return 1.0;
}

static int blockGraph_blockArithmetic(int blockID)
{
    int s1 = blkGph->blockGraph[blockID].adj1;
    int s2 = blkGph->blockGraph[blockID].adj2;
    int s3 = blkGph->blockGraph[blockID].adj3;
    int s4 = blkGph->blockGraph[blockID].adj4;

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

GMEXPORT double blockGraph_setUpBlockGraphList()
{
    blkGph->blockUpdateListLength = 0;

    double tempBlocks[blkGph->numberOfBlockModels];

    for (unsigned int i = 0; i < blkGph->numberOfBlockModels; i+=1)
    {
        if (blkGph->blockGraph[i].type != blockGraph_blockArithmetic(i))
        {
            blockGraph_addToBlockUpdateList(i);
            blockGraph_addToBlockUpdateList(blkGph->blockGraph[i].adj1);
            blockGraph_addToBlockUpdateList(blkGph->blockGraph[i].adj2);
            blockGraph_addToBlockUpdateList(blkGph->blockGraph[i].adj3);
            blockGraph_addToBlockUpdateList(blkGph->blockGraph[i].adj4);
        }

        tempBlocks[i] = blockGraph_blockArithmetic(i);
    }

    for (unsigned int i = 0; i < blkGph->numberOfBlockModels; i += 1)
    {
        blkGph->blockGraph[i].type = tempBlocks[i];
    }

    return 1.0;
}

GMEXPORT double blockGraph_addToBlockUpdateList(double blockID)
{
    if (blockID >= 0)
    {
        blkGph->blockUpdateList[blkGph->blockUpdateListLength] = blockID;
        blkGph->blockUpdateListLength += 1;
    }

    return 1.0;
}

GMEXPORT double blockGraph_updateBlockGraphWithList()
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

        if (tempBlocks[i] != blockGraph_blockArithmetic(i))
        {
            blockGraph_addToTempBlockUpdateList(i);
            blockGraph_addToTempBlockUpdateList(blkGph->blockGraph[i].adj1);
            blockGraph_addToTempBlockUpdateList(blkGph->blockGraph[i].adj2);
            blockGraph_addToTempBlockUpdateList(blkGph->blockGraph[i].adj3);
            blockGraph_addToTempBlockUpdateList(blkGph->blockGraph[i].adj4);
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
    }

    blkGph->blockUpdateListLength = blkGph->blockUpdateListTempLength;
    blkGph->blockUpdateListTempLength = 0;
    for (unsigned int i = 0; i < ceil(blkGph->numberOfBlockModels/blockModelCapacity); i+=1)
    {
        if (changed[i] == 1)
        {
            //d3d_model_destroy(blkGph->surfaceModel[i]);
            blkGph->surfaceModel[i] = blockGraph_createSubmodel(i);
        }
    }

    return 1.0;
}

GMEXPORT double blockGraph_addToTempBlockUpdateList(double blockID)
{
    if (blockID >= 0)
    {
        blkGph->blockUpdateListTemp[blkGph->blockUpdateListTempLength] = blockID;
        blkGph->blockUpdateListTempLength += 1;
    }

    return 1.0;
}

GMEXPORT double blockGraph_getSideWithPoint(double blockID, double x, double y, double z)
{
    double p1x = blkGph->blockGraph[(int)blockID].v1x;
    double p1y = blkGph->blockGraph[(int)blockID].v1y;
    double p1z = blkGph->blockGraph[(int)blockID].v1z;

    double p2x = blkGph->blockGraph[(int)blockID].v2x;
    double p2y = blkGph->blockGraph[(int)blockID].v2y;
    double p2z = blkGph->blockGraph[(int)blockID].v2z;

    double p3x = blkGph->blockGraph[(int)blockID].v3x;
    double p3y = blkGph->blockGraph[(int)blockID].v3y;
    double p3z = blkGph->blockGraph[(int)blockID].v3z;

    double p4x = blkGph->blockGraph[(int)blockID].v4x;
    double p4y = blkGph->blockGraph[(int)blockID].v4y;
    double p4z = blkGph->blockGraph[(int)blockID].v4z;

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

GMEXPORT double blockGraph_loadFromFile(char* fileName)
{
    FILE* file = fopen(fileName, "r");

    if (blkGph)
    {
        free(blkGph->blockGraph);
        free(blkGph->surfaceModel);
        free(blkGph->blockUpdateList);
        free(blkGph->blockUpdateListTemp);
        free(blkGph);
    }

    blkGph = (blockGraph*)malloc(sizeof(blockGraph));

    fscanf(file, "%u\n", &blkGph->numberOfBlockModels);

    blkGph->blockGraph = (block3D*)malloc(blkGph->numberOfBlockModels*sizeof(blockGraph));

    blkGph->numberOfModels = ceil(blkGph->numberOfBlockModels/blockModelCapacity);
    blkGph->surfaceModel = (double*)malloc(blkGph->numberOfModels*sizeof(double));

    blkGph->blockUpdateListLength = 0;
    blkGph->blockUpdateList = (unsigned int*)malloc(blkGph->numberOfBlockModels*sizeof(unsigned int));

    blkGph->blockUpdateListTempLength = 0;
    blkGph->blockUpdateListTemp = (unsigned int*)malloc(blkGph->numberOfBlockModels*sizeof(unsigned int));

    for (unsigned int i = 0; i < blkGph->numberOfBlockModels; i += 1)
    {
        fscanf(file, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %u %u %u %u %u %u %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf \n",
                     &blkGph->blockGraph[i].v1x, &blkGph->blockGraph[i].v1y, &blkGph->blockGraph[i].v1z,
                     &blkGph->blockGraph[i].v2x, &blkGph->blockGraph[i].v2y, &blkGph->blockGraph[i].v2z,
                     &blkGph->blockGraph[i].v3x, &blkGph->blockGraph[i].v3y, &blkGph->blockGraph[i].v3z,
                     &blkGph->blockGraph[i].v4x, &blkGph->blockGraph[i].v4y, &blkGph->blockGraph[i].v4z,
                     &blkGph->blockGraph[i].adj1, &blkGph->blockGraph[i].adj2, &blkGph->blockGraph[i].adj3, &blkGph->blockGraph[i].adj4,
                     &blkGph->blockGraph[i].type,
                     &blkGph->blockGraph[i].removable,
                     &blkGph->blockGraph[i].n1x, &blkGph->blockGraph[i].n1y, &blkGph->blockGraph[i].n1z,
                     &blkGph->blockGraph[i].n2x, &blkGph->blockGraph[i].n2y, &blkGph->blockGraph[i].n2z,
                     &blkGph->blockGraph[i].n3x, &blkGph->blockGraph[i].n3y, &blkGph->blockGraph[i].n3z,
                     &blkGph->blockGraph[i].n4x, &blkGph->blockGraph[i].n4y, &blkGph->blockGraph[i].n4z);
    }

    fclose(file);

    return (double)(int)blkGph;
}
