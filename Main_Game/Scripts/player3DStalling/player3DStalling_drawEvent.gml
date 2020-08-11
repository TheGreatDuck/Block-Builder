d3d_transform_set_identity();
//d3d_transform_add_rotation_axis(rx,ry,rz,angle);
d3d_transform_add_rotation_matrix(axisX_x,dirX,nx,
                                  axisX_y,dirY,ny,
                                  axisX_z,dirZ,nz);
d3d_transform_add_rotation_z(spin);
d3d_transform_add_translation(x,y,z);
d3d_draw_ellipsoid(-1,-1,2,1,1,5,sprite_get_texture(spr_tileGrey,0),2,1,60);

d3d_transform_set_identity();
d3d_transform_add_translation(-1,0,4);
//d3d_transform_add_rotation_axis(rx,ry,rz,angle);
d3d_transform_add_rotation_matrix(axisX_x,dirX,nx,
                                  axisX_y,dirY,ny,
                                  axisX_z,dirZ,nz);
d3d_transform_add_rotation_z(spin);
d3d_transform_add_translation(x,y,z);
d3d_draw_ellipsoid(-0.5,-0.5,-0.5,0.5,0.5,0.5,sprite_get_texture(spr_tileGrey,0),2,1,60);

d3d_transform_set_identity();
d3d_transform_add_translation(-1,0,4);
//d3d_transform_add_rotation_axis(rx,ry,rz,angle);
d3d_transform_add_rotation_matrix(axisX_x,dirX,nx,
                                  axisX_y,dirY,ny,
                                  axisX_z,dirZ,nz);
d3d_transform_add_rotation_z(spin);
d3d_transform_add_translation(x,y,z);
d3d_draw_cylinder(-0.5,-0.5,0,0.5,0.5,2,sprite_get_texture(spr_tileGrey,0),2,1,true,60);

d3d_transform_set_identity()
d3d_transform_add_translation(1,0,4);
//d3d_transform_add_rotation_axis(rx,ry,rz,angle);
d3d_transform_add_rotation_matrix(axisX_x,dirX,nx,
                                  axisX_y,dirY,ny,
                                  axisX_z,dirZ,nz);
d3d_transform_add_rotation_z(spin);
d3d_transform_add_translation(x,y,z);
d3d_draw_ellipsoid(-0.5,-0.5,-0.5,0.5,0.5,0.5,sprite_get_texture(spr_tileGrey,0),2,1,60);

d3d_transform_set_identity();
d3d_transform_add_translation(1,0,4);
//d3d_transform_add_rotation_axis(rx,ry,rz,angle);
d3d_transform_add_rotation_matrix(axisX_x,dirX,nx,
                                  axisX_y,dirY,ny,
                                  axisX_z,dirZ,nz);
d3d_transform_add_rotation_z(spin);
d3d_transform_add_translation(x,y,z);
d3d_draw_cylinder(-0.5,-0.5,0,0.5,0.5,2,sprite_get_texture(spr_tileGrey,0),2,1,true,60);

d3d_transform_set_identity();
d3d_transform_add_translation(-1,0,2.5);
//d3d_transform_add_rotation_axis(rx,ry,rz,angle);
d3d_transform_add_rotation_matrix(axisX_x,dirX,nx,
                                  axisX_y,dirY,ny,
                                  axisX_z,dirZ,nz);
d3d_transform_add_rotation_z(spin);
d3d_transform_add_translation(x,y,z);
d3d_draw_ellipsoid(-0.5,-0.5,-0.5,0.5,0.5,0.5,sprite_get_texture(spr_tileGrey,0),2,1,60);

d3d_transform_set_identity();
d3d_transform_add_translation(-1,0,2.5);
//d3d_transform_add_rotation_axis(rx,ry,rz,angle);
d3d_transform_add_rotation_matrix(axisX_x,dirX,nx,
                                  axisX_y,dirY,ny,
                                  axisX_z,dirZ,nz);
d3d_transform_add_rotation_z(spin);
d3d_transform_add_translation(x,y,z);
d3d_draw_cylinder(-0.5,-0.5,-2,0.5,0.5,0,sprite_get_texture(spr_tileGrey,0),2,1,true,60);

d3d_transform_set_identity()
d3d_transform_add_translation(1,0,2.5);
//d3d_transform_add_rotation_axis(rx,ry,rz,angle);
d3d_transform_add_rotation_matrix(axisX_x,dirX,nx,
                                  axisX_y,dirY,ny,
                                  axisX_z,dirZ,nz);
d3d_transform_add_rotation_z(spin);
d3d_transform_add_translation(x,y,z);
d3d_draw_ellipsoid(-0.5,-0.5,-0.5,0.5,0.5,0.5,sprite_get_texture(spr_tileGrey,0),2,1,60);

d3d_transform_set_identity();
d3d_transform_add_translation(1,0,2.5);
//d3d_transform_add_rotation_axis(rx,ry,rz,angle);
d3d_transform_add_rotation_matrix(axisX_x,dirX,nx,
                                  axisX_y,dirY,ny,
                                  axisX_z,dirZ,nz);
d3d_transform_add_rotation_z(spin);
d3d_transform_add_translation(x,y,z);
d3d_draw_cylinder(-0.5,-0.5,-2,0.5,0.5,0,sprite_get_texture(spr_tileGrey,0),2,1,true,60);

d3d_transform_set_identity();
d3d_transform_add_translation(0,0,6);
//d3d_transform_add_rotation_axis(rx,ry,rz,angle);
d3d_transform_add_rotation_matrix(axisX_x,dirX,nx,
                                  axisX_y,dirY,ny,
                                  axisX_z,dirZ,nz);
d3d_transform_add_rotation_z(spin);
d3d_transform_add_translation(x,y,z);
d3d_draw_ellipsoid(-1,-1,-1,1,1,1,sprite_get_texture(spr_tileGrey,0),2,1,60);

d3d_transform_set_identity();
d3d_transform_add_translation(0,0,6);
d3d_transform_add_translation(-0.25,1,0.25);
//d3d_transform_add_rotation_axis(rx,ry,rz,angle);
d3d_transform_add_rotation_matrix(axisX_x,dirX,nx,
                                  axisX_y,dirY,ny,
                                  axisX_z,dirZ,nz);
d3d_transform_add_rotation_z(spin);
d3d_transform_add_translation(x,y,z);
d3d_draw_ellipsoid(-0.125,-0.125,-0.125,0.125,0.125,0.125,sprite_get_texture(spr_tileGreen,0),2,1,60);

d3d_transform_set_identity();
d3d_transform_add_translation(0,0,6);
d3d_transform_add_translation(0.25,1,0.25);
//d3d_transform_add_rotation_axis(rx,ry,rz,angle);
d3d_transform_add_rotation_matrix(axisX_x,dirX,nx,
                                  axisX_y,dirY,ny,
                                  axisX_z,dirZ,nz);
d3d_transform_add_rotation_z(spin);
d3d_transform_add_translation(x,y,z);
d3d_draw_ellipsoid(-0.125,-0.125,-0.125,0.125,0.125,0.125,sprite_get_texture(spr_tileGreen,0),2,1,60);

d3d_transform_set_identity();
