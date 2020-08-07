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
