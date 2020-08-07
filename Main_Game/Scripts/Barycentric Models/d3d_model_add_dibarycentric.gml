//d3d_model_add_dibarycentric(model,blockID)

var model;
var blockID;
var blockModelID;

model = argument[0];
blockID = argument[1];

var vx1;
var vx2;
var vx3;
var vx4;
var vy1;
var vy2;
var vy3;
var vy4;
var vz1;
var vz2;
var vz3;
var vz4;

var nx1;
var nx2;
var nx3;
var nx4;
var ny1;
var ny2;
var ny3;
var ny4;
var nz1;
var nz2;
var nz3;
var nz4;

vx1 = blockGraph[blockID,Block3D_v1x];
vx2 = blockGraph[blockID,Block3D_v2x];
vx3 = blockGraph[blockID,Block3D_v3x];
vx4 = blockGraph[blockID,Block3D_v4x];
vy1 = blockGraph[blockID,Block3D_v1y];
vy2 = blockGraph[blockID,Block3D_v2y];
vy3 = blockGraph[blockID,Block3D_v3y];
vy4 = blockGraph[blockID,Block3D_v4y];
vz1 = blockGraph[blockID,Block3D_v1z];
vz2 = blockGraph[blockID,Block3D_v2z];
vz3 = blockGraph[blockID,Block3D_v3z];
vz4 = blockGraph[blockID,Block3D_v4z];

nx1 = blockGraph[blockID,Block3D_n1x];
nx2 = blockGraph[blockID,Block3D_n2x];
nx3 = blockGraph[blockID,Block3D_n3x];
nx4 = blockGraph[blockID,Block3D_n4x];
ny1 = blockGraph[blockID,Block3D_n1y];
ny2 = blockGraph[blockID,Block3D_n2y];
ny3 = blockGraph[blockID,Block3D_n3y];
ny4 = blockGraph[blockID,Block3D_n4y];
nz1 = blockGraph[blockID,Block3D_n1z];
nz2 = blockGraph[blockID,Block3D_n2z];
nz3 = blockGraph[blockID,Block3D_n3z];
nz4 = blockGraph[blockID,Block3D_n4z];

blockModelID = blockGraph[blockID,Block3D_type];

var blockModelSize;
var blockModelNormalStart;
var blockModelNormalEnd;

blockModelSize = global.barycentricModelSize[blockModelID];

var i;

for (i = 0; i < blockModelSize; i+=1)
{
    var px;
    var py;
    var pz;
    
    px = global.barycentricModelVertices[i,3*blockModelID];
    py = global.barycentricModelVertices[i,3*blockModelID+1];
    pz = global.barycentricModelVertices[i,3*blockModelID+2];
    
    if (px + py <= 1)
    {
        localBarycentricModelVertices[i,0] = vx1*px + vx4*py + vx3*(1 - px - py) + pz*(nx1*px + nx4*py + nx3*(1 - px - py));
        localBarycentricModelVertices[i,1] = vy1*px + vy4*py + vy3*(1 - px - py) + pz*(ny1*px + ny4*py + ny3*(1 - px - py));
        localBarycentricModelVertices[i,2] = vz1*px + vz4*py + vz3*(1 - px - py) + pz*(nz1*px + nz4*py + nz3*(1 - px - py));
    } else
    {
        localBarycentricModelVertices[i,0] = vx1*(1 - px) + vx4*(1 - py) + vx2*(-1 + px + py) + pz*(nx1*(1 - px) + nx4*(1 - py) + nx2*(-1 + px + py));
        localBarycentricModelVertices[i,1] = vy1*(1 - px) + vy4*(1 - py) + vy2*(-1 + px + py) + pz*(ny1*(1 - px) + ny4*(1 - py) + ny2*(-1 + px + py));
        localBarycentricModelVertices[i,2] = vz1*(1 - px) + vz4*(1 - py) + vz2*(-1 + px + py) + pz*(nz1*(1 - px) + nz4*(1 - py) + nz2*(-1 + px + py));
    }
}

d3d_model_primitive_begin(model,pr_trianglelist);

for (i = 0; i < 3*blockModelSize; i+=1)
{
    var nx;
    var ny;
    var nz;
    
    var px1;
    var py1;
    var pz1;
    
    var px2;
    var py2;
    var pz2;
    
    var px3;
    var py3;
    var pz3;
    
    var dir1x;
    var dir1y;
    var dir1z;
    
    var dir2x;
    var dir2y;
    var dir2z;
    
    px1 = localBarycentricModelVertices[3*i,0];
    py1 = localBarycentricModelVertices[3*i,1];
    pz1 = localBarycentricModelVertices[3*i,2];
    
    px2 = localBarycentricModelVertices[3*i+1,0];
    py2 = localBarycentricModelVertices[3*i+1,1];
    pz2 = localBarycentricModelVertices[3*i+1,2];
    
    px3 = localBarycentricModelVertices[3*i+2,0];
    py3 = localBarycentricModelVertices[3*i+2,1];
    pz3 = localBarycentricModelVertices[3*i+2,2];
    
    dir1x = p2x-p1x;
    dir1y = p2y-p1y;
    dir1z = p2z-p1z;
    
    dir2x = p3x-p1x;
    dir2y = p3y-p1y;
    dir2z = p3z-p1z;
    
    nx = dir1y*dir2z - dir1z*dir2y;
    ny = dir1z*dir2x - dir1x*dir2z;
    nz = dir1x*dir2y - dir1y*dir2x;

    norm = sqrt(nx*nx + ny*ny + nz*nz);
    nx /= norm;
    ny /= norm;
    nz /= norm;
    
    d3d_model_vertex_normal_texture(model,p1x,p1y,p1z,nx,ny,nz,global.barycentricModelTexture[3*i,2*blockModelID],global.barycentricModelTexture[3*i,2*blockModelID+1]);
    d3d_model_vertex_normal_texture(model,p2x,p2y,p2z,nx,ny,nz,global.barycentricModelTexture[3*i+1,2*blockModelID],global.barycentricModelTexture[3*i+1,2*blockModelID+1]);
    d3d_model_vertex_normal_texture(model,p3x,p3y,p3z,nx,ny,nz,global.barycentricModelTexture[3*i+2,2*blockModelID],global.barycentricModelTexture[3*i+2,2*blockModelID+1]);
}

d3d_model_primitive_end(model);
