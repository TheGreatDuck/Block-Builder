#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <math.h>
#include "delayed_function_calls.h"

GMEXPORT double blockGraph_update()
{
    with (obj_blockGraph)
{
    var i;
    for (i = 0; i < numberOfBlockModels; i += 1)
    {
        tempBlocks[i] = blockGraph_blockArithmetic(i);
    }

    var changed;
    changed = 0;
    for (i = 0; i < numberOfBlockModels; i += 1)
    {
        if (blockGraph[i,Block3D_type] != tempBlocks[i])
        {

            blockGraph[i,Block3D_type] = tempBlocks[i];
            changed = 1;
            /*show_message("it executed");
            d3d_set_projection_ortho(0,0, power(2,ceil(log2(numberOfBlockModels)))*64, 64, 0);
            surface_set_target(blockGraphSurface);
            draw_sprite(spr_tileSet,square_getBlockType(blockGraph[i]),64*i,0);
            surface_reset_target();*/
        }
    }

    if (changed == 1)
    {
        d3d_model_destroy(surfaceModel);
        surfaceModel = blockGraph_create3DModel();
    }
}
}

GMEXPORT double blockGraph_create3DModel()
{
    fillerModel = d3d_model_create();
numberOfModels = ceil(numberOfBlockModels/blockModelCapacity);
for (i = 0; i < numberOfModels; i+=1)
{
    surfaceModel[i] = blockGraph_createSubmodel(i);
}
}

GMEXPORT double blockGraph_createSubmodel()
{
    var model;
model = d3d_model_create();
d3d_model_primitive_begin(model,pr_trianglelist);

var i;
for (i = argument[0]*blockModelCapacity; i < numberOfBlockModels && i < (argument[0]+1)*blockModelCapacity; i += 1)
{
    var p1x;
    var p1y;
    var p1z;
    var p2x;
    var p2y;
    var p2z;
    var p3x;
    var p3y;
    var p3z;
    var p4x;
    var p4y;
    var p4z;

    var n1x;
    var n1y;
    var n1z;
    var n2x;
    var n2y;
    var n2z;
    var n3x;
    var n3y;
    var n3z;
    var n4x;
    var n4y;
    var n4z;

    p1x = blockGraph[i,Block3D_v1x];
    p1y = blockGraph[i,Block3D_v1y];
    p1z = blockGraph[i,Block3D_v1z];
    p2x = blockGraph[i,Block3D_v2x];
    p2y = blockGraph[i,Block3D_v2y];
    p2z = blockGraph[i,Block3D_v2z];
    p3x = blockGraph[i,Block3D_v3x];
    p3y = blockGraph[i,Block3D_v3y];
    p3z = blockGraph[i,Block3D_v3z];
    p4x = blockGraph[i,Block3D_v4x];
    p4y = blockGraph[i,Block3D_v4y];
    p4z = blockGraph[i,Block3D_v4z];

    pn1x = -4*blockGraph[i,Block3D_n1x];
    pn1y = -4*blockGraph[i,Block3D_n1y];
    pn1z = -4*blockGraph[i,Block3D_n1z];
    pn2x = -4*blockGraph[i,Block3D_n2x];
    pn2y = -4*blockGraph[i,Block3D_n2y];
    pn2z = -4*blockGraph[i,Block3D_n2z];
    pn3x = -4*blockGraph[i,Block3D_n3x];
    pn3y = -4*blockGraph[i,Block3D_n3y];
    pn3z = -4*blockGraph[i,Block3D_n3z];
    pn4x = -4*blockGraph[i,Block3D_n4x];
    pn4y = -4*blockGraph[i,Block3D_n4y];
    pn4z = -4*blockGraph[i,Block3D_n4z];

    dir1x = p3x-p1x;
    dir1y = p3y-p1y;
    dir1z = p3z-p1z;

    dir2x = p4x-p1x;
    dir2y = p4y-p1y;
    dir2z = p4z-p1z;

    n1x = dir1y*dir2z - dir1z*dir2y;
    n1y = dir1z*dir2x - dir1x*dir2z;
    n1z = dir1x*dir2y - dir1y*dir2x;

    norm = sqrt(n1x*n1x + n1y*n1y + n1z*n1z);
    n1x /= norm;
    n1y /= norm;
    n1z /= norm;

    dir1x = p4x-p1x;
    dir1y = p4y-p1y;
    dir1z = p4z-p1z;

    dir2x = p2x-p1x;
    dir2y = p2y-p1y;
    dir2z = p2z-p1z;

    n2x = dir1y*dir2z - dir1z*dir2y;
    n2y = dir1z*dir2x - dir1x*dir2z;
    n2z = dir1x*dir2y - dir1y*dir2x;

    norm = sqrt(n2x*n2x + n2y*n2y + n2z*n2z);
    n2x /= norm;
    n2y /= norm;
    n2z /= norm;

    var bt;
    bt = blockGraph[i,Block3D_type];

    d3d_model_vertex_normal_texture(model,p1x,p1y,p1z,pn1x,pn1y,pn1z,bt/numberOfBlocks_3D,0+0.5*blockGraph[i,Block3D_removable]);
    d3d_model_vertex_normal_texture(model,p3x,p3y,p3z,pn3x,pn3y,pn3z,bt/numberOfBlocks_3D,0.5+0.5*blockGraph[i,Block3D_removable]);
    d3d_model_vertex_normal_texture(model,p4x,p4y,p4z,pn4x,pn4y,pn4z,(bt+1)/numberOfBlocks_3D,0.5+0.5*blockGraph[i,Block3D_removable]);

    d3d_model_vertex_normal_texture(model,p1x,p1y,p1z,pn1x,pn1y,pn1z,bt/numberOfBlocks_3D,0+0.5*blockGraph[i,Block3D_removable]);
    d3d_model_vertex_normal_texture(model,p4x,p4y,p4z,pn4x,pn4y,pn4z,(bt+1)/numberOfBlocks_3D,0.5+0.5*blockGraph[i,Block3D_removable]);
    d3d_model_vertex_normal_texture(model,p2x,p2y,p2z,pn2x,pn2y,pn2z,(bt+1)/numberOfBlocks_3D,0+0.5*blockGraph[i,Block3D_removable]);


    /*d3d_model_vertex_texture(model,p4x,p4y,p4z,(bt+1)/8,1);
    d3d_model_vertex_texture(model,p3x,p3y,p3z,bt/8,1);
    d3d_model_vertex_texture(model,p1x,p1y,p1z,bt/8,0);

    d3d_model_vertex_texture(model,p2x,p2y,p2z,(bt+1)/8,0);
    d3d_model_vertex_texture(model,p4x,p4y,p4z,(bt+1)/8,1);
    d3d_model_vertex_texture(model,p1x,p1y,p1z,bt/8,0);*/
}

d3d_model_primitive_end(model);
return model;
}

GMEXPORT double blockGraph_blockArithmetic()
{
    var s1;
var s2;
var s3;
var s4;

s1 = blockGraph[argument[0],Block3D_adj1];
s2 = blockGraph[argument[0],Block3D_adj2];
s3 = blockGraph[argument[0],Block3D_adj3];
s4 = blockGraph[argument[0],Block3D_adj4];

var b1;
var b2;
var b3;
var b4;

if (s1 != -1)
{
    b1 = blockGraph[s1,Block3D_type];
} else
{
    b1 = -1;
}

if (s2 != -1)
{
    b2 = blockGraph[s2,Block3D_type];
} else
{
    b2 = -1;
}

if (s3 != -1)
{
    b3 = blockGraph[s3,Block3D_type];
} else
{
    b3 = -1;
}

if (s4 != -1)
{
    b4 = blockGraph[s4,Block3D_type];
} else
{
    b4 = -1;
}

return scr_changeBlock(blockGraph[argument[0],Block3D_type],b1,b2,b3,b4);
}

GMEXPORT double blockGraph_setUpBlockGraphList()
{
    with (obj_blockGraph)
{
    blockUpdateListLength = 0;
    var i;

    for (i = 0; i < numberOfBlockModels; i+=1)
    {
        if (blockGraph[i,Block3D_type] != blockGraph_blockArithmetic(i))
        {
            blockGraph_addToBlockUpdateList(i);
            blockGraph_addToBlockUpdateList(blockGraph[i,Block3D_adj1]);
            blockGraph_addToBlockUpdateList(blockGraph[i,Block3D_adj2]);
            blockGraph_addToBlockUpdateList(blockGraph[i,Block3D_adj3]);
            blockGraph_addToBlockUpdateList(blockGraph[i,Block3D_adj4]);
        }

        tempBlocks[i] = blockGraph_blockArithmetic(i);
    }

    for (i = 0; i < numberOfBlockModels; i += 1)
    {
        blockGraph[i,Block3D_type] = tempBlocks[i];
    }
}
}

GMEXPORT double blockGraph_addToBlockUpdateList()
{
    if (argument[0] >= 0)
{
    blockUpdateList[blockUpdateListLength] = argument[0];
    blockUpdateListLength += 1;
}
}

GMEXPORT double blockGraph_updateBlockGraphWithList()
{
    with (obj_blockGraph)
{
    var changed;
    for (i = 0; i  < ceil(numberOfBlockModels/blockModelCapacity); i+=1)
    {
        changed[i] = 0;
    }

    var k
    for (k = 0; k < blockUpdateListLength; k += 1)
    {
        var i;
        i = blockUpdateList[k];

        if (tempBlocks[i] != blockGraph_blockArithmetic(i))
        {
            blockGraph_addToTempBlockUpdateList(i);
            blockGraph_addToTempBlockUpdateList(blockGraph[i,Block3D_adj1]);
            blockGraph_addToTempBlockUpdateList(blockGraph[i,Block3D_adj2]);
            blockGraph_addToTempBlockUpdateList(blockGraph[i,Block3D_adj3]);
            blockGraph_addToTempBlockUpdateList(blockGraph[i,Block3D_adj4]);
            changed[floor(i/blockModelCapacity)] = 1;
        }

        tempBlocks[i] = blockGraph_blockArithmetic(i);
    }

    for (k = 0; k < blockUpdateListLength; k += 1)
    {
        var i;
        i = blockUpdateList[k];
        blockGraph[i,Block3D_type] = tempBlocks[i];
    }

    blockUpdateListLength = 0;

    for (k = 0; k < blockUpdateListTempLength; k += 1)
    {
        blockUpdateList[k] = blockUpdateListTemp[k];

    }

    blockUpdateListLength = blockUpdateListTempLength;
    blockUpdateListTempLength = 0;
    for (i = 0; i  < ceil(numberOfBlockModels/blockModelCapacity); i+=1)
    {
        if (changed[i] == 1)
        {
            d3d_model_destroy(surfaceModel[i]);
            surfaceModel[i] = blockGraph_createSubmodel(i);
        }
    }
}
}

GMEXPORT double blockGraph_addToTempBlockUpdateList()
{
    if (argument[0] >= 0)
{
    blockUpdateListTemp[blockUpdateListTempLength] = argument[0];
    blockUpdateListTempLength += 1;
}
}

GMEXPORT double blockGraph_addSquare()
{
    blockGraph[numberOfBlockModels,Block3D_v1x] = argument[0];
blockGraph[numberOfBlockModels,Block3D_v1y] = argument[1];
blockGraph[numberOfBlockModels,Block3D_v1z] = argument[2];
blockGraph[numberOfBlockModels,Block3D_v2x] = argument[3];
blockGraph[numberOfBlockModels,Block3D_v2y] = argument[4];
blockGraph[numberOfBlockModels,Block3D_v2z] = argument[5];
blockGraph[numberOfBlockModels,Block3D_v3x] = argument[6];
blockGraph[numberOfBlockModels,Block3D_v3y] = argument[7];
blockGraph[numberOfBlockModels,Block3D_v3z] = argument[8];
blockGraph[numberOfBlockModels,Block3D_v4x] = argument[9];
blockGraph[numberOfBlockModels,Block3D_v4y] = argument[10];
blockGraph[numberOfBlockModels,Block3D_v4z] = argument[11];
blockGraph[numberOfBlockModels,Block3D_adj1] = -1;
blockGraph[numberOfBlockModels,Block3D_adj2] = -1;
blockGraph[numberOfBlockModels,Block3D_adj3] = -1;
blockGraph[numberOfBlockModels,Block3D_adj4] = -1;
blockGraph[numberOfBlockModels,Block3D_type] = argument[12];
blockGraph[numberOfBlockModels,Block3D_removable] = argument[13];
numberOfBlockModels+=1;
}

GMEXPORT double blockGraph_getSideWithPoint()
{
var p1x;
var p1y;
var p1z;

var p2x;
var p2y;
var p2z;

var p3x;
var p3y;
var p3z;

var p4x;
var p4y;
var p4z;

var vx;
var vy;
var vz;

p1x = obj_blockGraph.blockGraph[argument[0],Block3D_v1x];
p1y = obj_blockGraph.blockGraph[argument[0],Block3D_v1y];
p1z = obj_blockGraph.blockGraph[argument[0],Block3D_v1z];

p2x = obj_blockGraph.blockGraph[argument[0],Block3D_v2x];
p2y = obj_blockGraph.blockGraph[argument[0],Block3D_v2y];
p2z = obj_blockGraph.blockGraph[argument[0],Block3D_v2z];

p3x = obj_blockGraph.blockGraph[argument[0],Block3D_v3x];
p3y = obj_blockGraph.blockGraph[argument[0],Block3D_v3y];
p3z = obj_blockGraph.blockGraph[argument[0],Block3D_v3z];

p4x = obj_blockGraph.blockGraph[argument[0],Block3D_v4x];
p4y = obj_blockGraph.blockGraph[argument[0],Block3D_v4y];
p4z = obj_blockGraph.blockGraph[argument[0],Block3D_v4z];

vx = argument[1];
vy = argument[2];
vz = argument[3];

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

GMEXPORT double blockGraph_loadFromFile()
{
file = file_text_open_read(argument[0]);

numberOfBlockModels = file_text_read_real(file);
//show_message(numberOfBlockModels);
file_text_readln(file);
var i;

for (i = 0; i < numberOfBlockModels; i += 1)
{
    blockGraph[i,Block3D_v1x] = file_text_read_real(file);
    blockGraph[i,Block3D_v1y] = file_text_read_real(file);
    blockGraph[i,Block3D_v1z] = file_text_read_real(file);
    blockGraph[i,Block3D_v2x] = file_text_read_real(file);
    blockGraph[i,Block3D_v2y] = file_text_read_real(file);
    blockGraph[i,Block3D_v2z] = file_text_read_real(file);
    blockGraph[i,Block3D_v3x] = file_text_read_real(file);
    blockGraph[i,Block3D_v3y] = file_text_read_real(file);
    blockGraph[i,Block3D_v3z] = file_text_read_real(file);
    blockGraph[i,Block3D_v4x] = file_text_read_real(file);
    blockGraph[i,Block3D_v4y] = file_text_read_real(file);
    blockGraph[i,Block3D_v4z] = file_text_read_real(file);
    blockGraph[i,Block3D_adj1] = file_text_read_real(file);
    blockGraph[i,Block3D_adj2] = file_text_read_real(file);
    blockGraph[i,Block3D_adj3] = file_text_read_real(file);
    blockGraph[i,Block3D_adj4] = file_text_read_real(file);
    blockGraph[i,Block3D_type] = file_text_read_real(file);
    blockGraph[i,Block3D_removable] = file_text_read_real(file);
    //blockGraph[i,Block3D_n1x] = file_text_read_real(file);
    //blockGraph[i,Block3D_n1y] = file_text_read_real(file);
    //blockGraph[i,Block3D_n1z] = file_text_read_real(file);
    //blockGraph[i,Block3D_n2x] = file_text_read_real(file);
    //blockGraph[i,Block3D_n2y] = file_text_read_real(file);
    //blockGraph[i,Block3D_n2z] = file_text_read_real(file);
    //blockGraph[i,Block3D_n3x] = file_text_read_real(file);
    //blockGraph[i,Block3D_n3y] = file_text_read_real(file);
    //blockGraph[i,Block3D_n3z] = file_text_read_real(file);
    //blockGraph[i,Block3D_n4x] = file_text_read_real(file);
    //blockGraph[i,Block3D_n4y] = file_text_read_real(file);
    //blockGraph[i,Block3D_n4z] = file_text_read_real(file);
    file_text_readln(file);
}
file_text_close(file);
}
