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
    d3d_model_create(&blkGph->surfaceModel[modelID]);
    d3d_model_primitive_begin(&blkGph->surfaceModel[modelID],pr_trianglelist);

    for (unsigned int i = modelID*blockModelCapacity; i < blkGph->numberOfBlockModels && i < (modelID+1)*blockModelCapacity; i += 1)
    {
        vector p1 = blkGph->blockGraph[i].v[0];
        vector p2 = blkGph->blockGraph[i].v[1];
        vector p3 = blkGph->blockGraph[i].v[2];
        vector p4 = blkGph->blockGraph[i].v[3];

        vector pn1 = -blkGph->blockGraph[i].n[0];
        vector pn2 = -blkGph->blockGraph[i].n[1];
        vector pn3 = -blkGph->blockGraph[i].n[2];
        vector pn4 = -blkGph->blockGraph[i].n[3];

        double bt = blkGph->blockGraph[i].type;

        /*d3d_model_vertex_normal_texture(&blkGph->surfaceModel[modelID],p1x,p1y,p1z,pn1x,pn1y,pn1z,bt/numberOfBlocks_3D,0+0.5*blkGph->blockGraph[i].removable);
        d3d_model_vertex_normal_texture(&blkGph->surfaceModelmodelID],p3x,p3y,p3z,pn3x,pn3y,pn3z,bt/numberOfBlocks_3D,0.5+0.5*blkGph->blockGraph[i].removable);
        d3d_model_vertex_normal_texture(&blkGph->surfaceModel[modelID],p4x,p4y,p4z,pn4x,pn4y,pn4z,(bt+1)/numberOfBlocks_3D,0.5+0.5*blkGph->blockGraph[i].removable);

        d3d_model_vertex_normal_texture(&blkGph->surfaceModel[modelID],p1x,p1y,p1z,pn1x,pn1y,pn1z,bt/numberOfBlocks_3D,0+0.5*blkGph->blockGraph[i].removable);
        d3d_model_vertex_normal_texture(&blkGph->surfaceModel[modelID],p4x,p4y,p4z,pn4x,pn4y,pn4z,(bt+1)/numberOfBlocks_3D,0.5+0.5*blkGph->blockGraph[i].removable);
        d3d_model_vertex_normal_texture(&blkGph->surfaceModel[modelID],p2x,p2y,p2z,pn2x,pn2y,pn2z,(bt+1)/numberOfBlocks_3D,0+0.5*blkGph->blockGraph[i].removable);*/


        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p1.x,p1.y,p1.z,bt/numberOfBlocks_3D,0);
        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p3.x,p3.y,p3.z,bt/numberOfBlocks_3D,1);
        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p4.x,p4.y,p4.z,(bt+1)/numberOfBlocks_3D,1);

        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p1.x,p1.y,p1.z,bt/numberOfBlocks_3D,0);
        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p4.x,p4.y,p4.z,(bt+1)/numberOfBlocks_3D,1);
        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p2.x,p2.y,p2.z,(bt+1)/numberOfBlocks_3D,0);

        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p1.x,p1.y,p1.z,bt/numberOfBlocks_3D,0);
        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p4.x,p4.y,p4.z,(bt+1)/numberOfBlocks_3D,1);
        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p3.x,p3.y,p3.z,bt/numberOfBlocks_3D,1);

        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p1.x,p1.y,p1.z,bt/numberOfBlocks_3D,0);
        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p2.x,p2.y,p2.z,(bt+1)/numberOfBlocks_3D,0);
        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p4.x,p4.y,p4.z,(bt+1)/numberOfBlocks_3D,1);



        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p1.x+pn1.x,p1.y+pn1.y,p1.z+pn1.z,0/numberOfBlocks_3D,0);
        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p1.x,p1.y,p1.z,0/numberOfBlocks_3D,1);
        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p2.x,p2.y,p2.z,(0+1)/numberOfBlocks_3D,1);

        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p1.x+pn1.x,p1.y+pn1.y,p1.z+pn1.z,0/numberOfBlocks_3D,0);
        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p2.x,p2.y,p2.z,(0+1)/numberOfBlocks_3D,1);
        d3d_model_vertex_texture(&blkGph->surfaceModel[modelID],p2.x+pn2.x,p2.y+pn2.y,p2.z+pn2.z,(0+1)/numberOfBlocks_3D,0);
    }

    d3d_model_primitive_end(&blkGph->surfaceModel[modelID]);
}

void blockGraph_create3DModel()
{
    d3d_model_create(&blkGph->fillerModel);
    blkGph->numberOfModels = ceil(blkGph->numberOfBlockModels/blockModelCapacity);
    for (unsigned int i = 0; i < blkGph->numberOfModels; i+=1)
    {
        blockGraph_createSubmodel(i);
    }
}

static int blockGraph_blockArithmetic(int blockID)
{
    int s1 = blkGph->blockGraph[blockID].adj[0];
    int s2 = blkGph->blockGraph[blockID].adj[1];
    int s3 = blkGph->blockGraph[blockID].adj[2];
    int s4 = blkGph->blockGraph[blockID].adj[3];

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
            blockGraph_addToBlockUpdateList(blkGph->blockGraph[i].adj[0]);
            blockGraph_addToBlockUpdateList(blkGph->blockGraph[i].adj[1]);
            blockGraph_addToBlockUpdateList(blkGph->blockGraph[i].adj[2]);
            blockGraph_addToBlockUpdateList(blkGph->blockGraph[i].adj[3]);
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

static void blockGraph_addToTempBlockUpdateList(int blockID)
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

void blockGraph_updateBlockGraphWithList()
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
            blockGraph_addToTempBlockUpdateList(blkGph->blockGraph[i].adj[0]);
            blockGraph_addToTempBlockUpdateList(blkGph->blockGraph[i].adj[1]);
            blockGraph_addToTempBlockUpdateList(blkGph->blockGraph[i].adj[2]);
            blockGraph_addToTempBlockUpdateList(blkGph->blockGraph[i].adj[3]);
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
            d3d_model_destroy(blkGph->surfaceModel[i]);
            blockGraph_createSubmodel(i);
        }
    }
}

static int blockGraph_getSideWithPoint(int blockID, vector v)
{
    double x = v.x;
    double y = v.y;
    double z = v.z;

    if (blockID == -1)
        return -1;

    vector s0 = blkGph->blockGraph[blockID].side[0];
    vector s1 = blkGph->blockGraph[blockID].side[1];
    vector s2 = blkGph->blockGraph[blockID].side[2];
    vector s3 = blkGph->blockGraph[blockID].side[3];

    if (s0.x == x && s0.y == y && s0.z == z)
    {
        return 0;
    }

    if (s1.x == x && s1.y == y && s1.z == z)
    {
        return 1;
    }

    if (s2.x == x && s2.y == y && s2.z == z)
    {
        return 2;
    }

    if (s3.x == x && s3.y == y && s3.z == z)
    {
        return 3;
    }

    return -1;
}

void blockGraph_loadFromFile(const char* fileName)
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
                     &blkGph->blockGraph[i].v[0].x, &blkGph->blockGraph[i].v[0].y, &blkGph->blockGraph[i].v[0].z,
                     &blkGph->blockGraph[i].v[1].x, &blkGph->blockGraph[i].v[1].y, &blkGph->blockGraph[i].v[1].z,
                     &blkGph->blockGraph[i].v[2].x, &blkGph->blockGraph[i].v[2].y, &blkGph->blockGraph[i].v[2].z,
                     &blkGph->blockGraph[i].v[3].x, &blkGph->blockGraph[i].v[3].y, &blkGph->blockGraph[i].v[3].z,
                     &blkGph->blockGraph[i].adj[0], &blkGph->blockGraph[i].adj[1], &blkGph->blockGraph[i].adj[2], &blkGph->blockGraph[i].adj[3],
                     &blkGph->blockGraph[i].type,
                     &blkGph->blockGraph[i].removable,
                     &blkGph->blockGraph[i].n[0].x, &blkGph->blockGraph[i].n[0].y, &blkGph->blockGraph[i].n[0].z,
                     &blkGph->blockGraph[i].n[1].x, &blkGph->blockGraph[i].n[1].y, &blkGph->blockGraph[i].n[1].z,
                     &blkGph->blockGraph[i].n[2].x, &blkGph->blockGraph[i].n[2].y, &blkGph->blockGraph[i].n[2].z,
                     &blkGph->blockGraph[i].n[3].x, &blkGph->blockGraph[i].n[3].y, &blkGph->blockGraph[i].n[3].z);

        blkGph->blockGraph[i].position = (blkGph->blockGraph[i].v[0] +
                                          blkGph->blockGraph[i].v[1] +
                                          blkGph->blockGraph[i].v[2] +
                                          blkGph->blockGraph[i].v[3])/4;



        vector dir1 = blkGph->blockGraph[i].v[2] - blkGph->blockGraph[i].v[0];
        vector dir2 = blkGph->blockGraph[i].v[3] - blkGph->blockGraph[i].v[0];

        blkGph->blockGraph[i].normal.x = dir1.y*dir2.z - dir1.z*dir2.y;
        blkGph->blockGraph[i].normal.y = dir1.z*dir2.x - dir1.x*dir2.z;
        blkGph->blockGraph[i].normal.z = dir1.x*dir2.y - dir1.y*dir2.x;

        blkGph->blockGraph[i].normal = (1/sqrt(blkGph->blockGraph[i].normal*blkGph->blockGraph[i].normal))*blkGph->blockGraph[i].normal;

        blkGph->blockGraph[i].side[0] = (blkGph->blockGraph[i].v[0] + blkGph->blockGraph[i].v[2])/2;
        blkGph->blockGraph[i].side[1] = (blkGph->blockGraph[i].v[2] + blkGph->blockGraph[i].v[3])/2;
        blkGph->blockGraph[i].side[2] = (blkGph->blockGraph[i].v[3] + blkGph->blockGraph[i].v[1])/2;
        blkGph->blockGraph[i].side[3] = (blkGph->blockGraph[i].v[1] + blkGph->blockGraph[i].v[0])/2;

        blkGph->blockGraph[i].dir[0] = blkGph->blockGraph[i].side[0] - blkGph->blockGraph[i].position;
        blkGph->blockGraph[i].dir[1] = blkGph->blockGraph[i].side[1] - blkGph->blockGraph[i].position;
        blkGph->blockGraph[i].dir[2] = blkGph->blockGraph[i].side[2] - blkGph->blockGraph[i].position;
        blkGph->blockGraph[i].dir[3] = blkGph->blockGraph[i].side[3] - blkGph->blockGraph[i].position;

        blkGph->blockGraph[i].dir[0] = (1/sqrt(blkGph->blockGraph[i].dir[0]*blkGph->blockGraph[i].dir[0]))*blkGph->blockGraph[i].dir[0];
        blkGph->blockGraph[i].dir[1] = (1/sqrt(blkGph->blockGraph[i].dir[1]*blkGph->blockGraph[i].dir[1]))*blkGph->blockGraph[i].dir[1];
        blkGph->blockGraph[i].dir[2] = (1/sqrt(blkGph->blockGraph[i].dir[2]*blkGph->blockGraph[i].dir[2]))*blkGph->blockGraph[i].dir[2];
        blkGph->blockGraph[i].dir[3] = (1/sqrt(blkGph->blockGraph[i].dir[3]*blkGph->blockGraph[i].dir[3]))*blkGph->blockGraph[i].dir[3];

        blkGph->blockGraph[i].axisX[0] = crossProduct(blkGph->blockGraph[i].dir[0], blkGph->blockGraph[i].normal);
        blkGph->blockGraph[i].axisX[1] = crossProduct(blkGph->blockGraph[i].dir[1], blkGph->blockGraph[i].normal);
        blkGph->blockGraph[i].axisX[2] = crossProduct(blkGph->blockGraph[i].dir[2], blkGph->blockGraph[i].normal);
        blkGph->blockGraph[i].axisX[3] = crossProduct(blkGph->blockGraph[i].dir[3], blkGph->blockGraph[i].normal);

        blkGph->blockGraph[i].entityID = -1;
    }

    for (unsigned int i = 0; i < blkGph->numberOfBlockModels; i += 1)
    {
        for (unsigned int m = 0; m < 4; m += 1)
        {
            blkGph->blockGraph[i].adj[m] = -1;
        }
    }

    for (unsigned int i = 0; i < blkGph->numberOfBlockModels; i += 1)
    {
        for (unsigned int j = 0; j < blkGph->numberOfBlockModels; j += 1)
        {
            for (unsigned int k = 0; k < 4; k += 1)
            {
                for (unsigned int m = 0; m < 4; m += 1)
                {
                    if (blkGph->blockGraph[i].side[m] == blkGph->blockGraph[j].side[k] && i != j)
                    {
                        blkGph->blockGraph[i].adj[m] = j;
                    }
                }
            }
        }
    }

    for (unsigned int i = 0; i < blkGph->numberOfBlockModels; i += 1)
    {
        blkGph->blockGraph[i].adjSide[0] = blockGraph_getSideWithPoint(blkGph->blockGraph[i].adj[0], blkGph->blockGraph[i].side[0]);
        blkGph->blockGraph[i].adjSide[1] = blockGraph_getSideWithPoint(blkGph->blockGraph[i].adj[1], blkGph->blockGraph[i].side[1]);
        blkGph->blockGraph[i].adjSide[2] = blockGraph_getSideWithPoint(blkGph->blockGraph[i].adj[2], blkGph->blockGraph[i].side[2]);
        blkGph->blockGraph[i].adjSide[3] = blockGraph_getSideWithPoint(blkGph->blockGraph[i].adj[3], blkGph->blockGraph[i].side[3]);
    }

    fclose(file);
}

void blockGraph_drawEvent()
{
    for (int i = 0; i  < ceil(blkGph->numberOfBlockModels/blockModelCapacity); i+=1)
    {
        d3d_model_draw(&blkGph->surfaceModel[i],0,0,0, &blkGph->tex_blockTexture);
    }
}

void d3d_transform_add_block_matrix(int blockID, int sideFacing)
{
    double a11 = blkGph->blockGraph[blockID].axisX[sideFacing].x;
    double a12 = blkGph->blockGraph[blockID].dir[sideFacing].x;
    double a13 = blkGph->blockGraph[blockID].normal.x;

    double a21 = blkGph->blockGraph[blockID].axisX[sideFacing].y;
    double a22 = blkGph->blockGraph[blockID].dir[sideFacing].y;
    double a23 = blkGph->blockGraph[blockID].normal.y;

    double a31 = blkGph->blockGraph[blockID].axisX[sideFacing].z;
    double a32 = blkGph->blockGraph[blockID].dir[sideFacing].z;
    double a33 = blkGph->blockGraph[blockID].normal.z;

    double rot_x;
    double rot_y;
    double rot_z;
    double rot_angle;

    if ((a11 + a22 + a33 - 1)/2 > 1)
    {
        rot_angle = 0;
    } else if ((a11 + a22 + a33 - 1)/2 < -1)
    {
        rot_angle = acos(-1.0);
    } else
    {
        rot_angle = acos((a11 + a22 + a33 - 1)/2);
    }

    if (sin(rot_angle) != 0)
    {
        rot_x = (a32 - a23)/(2*sin(rot_angle));
        rot_y = (a13 - a31)/(2*sin(rot_angle));
        rot_z = (a21 - a12)/(2*sin(rot_angle));
    } else if (cos(rot_angle) == 1)
    {
        rot_x = 0;
        rot_y = 0;
        rot_z = 1;
    } else
    {
        double rot_norm;
        rot_x = 2*a11 + 2;
        rot_y = a12 + a21;
        rot_z = a13 + a31;
        rot_norm = sqrt(rot_x*rot_x + rot_y*rot_y + rot_z*rot_z);
        if (rot_norm == 0)
        {
            rot_x = a21 + a12;
            rot_y = 2*a22 + 2;
            rot_z = a32 + a23;
            rot_norm = sqrt(rot_x*rot_x + rot_y*rot_y + rot_z*rot_z);
        }

        if (rot_norm == 0)
        {
            rot_x = a31 + a13;
            rot_y = a32 + a23;
            rot_z = 2*a33 + 2;
            rot_norm = sqrt(rot_x*rot_x + rot_y*rot_y + rot_z*rot_z);
        }
        rot_x /= rot_norm;
        rot_y /= rot_norm;
        rot_z /= rot_norm;
    }

    rot_angle = (2*(rot_angle == acos(-1.0)) - 1)*rot_angle*(180/acos(-1.0));
    d3d_transform_add_rotation_axis(rot_x,rot_y,rot_z,rot_angle);
}
