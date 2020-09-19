ADD_FUNCTION(d3d_draw_block)
ADD_FUNCTION(d3d_draw_cylinder)
ADD_FUNCTION(d3d_draw_cone)
ADD_FUNCTION(d3d_draw_ellipsoid)
ADD_FUNCTION(d3d_draw_wall)
ADD_FUNCTION(d3d_draw_floor)

ADD_FUNCTION(d3d_set_projection_ortho)
ADD_FUNCTION(d3d_set_projection_perspective)
ADD_FUNCTION(d3d_set_projection)
ADD_FUNCTION(d3d_start)
ADD_FUNCTION(d3d_set_fog)
ADD_FUNCTION(d3d_set_lighting)
ADD_FUNCTION(d3d_set_culling)

void d3d_draw_block(double x1, double y1, double z1, double x2, double y2, double z2, int* texid, int hrepeat, int vrepeat)
{
    addDelayedFunctionCall(FP_d3d_draw_block, NULL, 0, x1, y1, z1, x2, y2, z2, texid, hrepeat, vrepeat);
}

void d3d_draw_cylinder(double x1, double y1, double z1, double x2, double y2, double z2, int* texid, int hrepeat, int vrepeat, int closed, int steps)
{
    addDelayedFunctionCall(FP_d3d_draw_cylinder, NULL, 0, x1, y1, z1, x2, y2, z2, texid, hrepeat, vrepeat, closed, steps);
}

void d3d_draw_cone(double x1, double y1, double z1, double x2, double y2, double z2, int* texid, int hrepeat, int vrepeat, int closed, int steps)
{
    addDelayedFunctionCall(FP_d3d_draw_cone, NULL, 0, x1, y1, z1, x2, y2, z2, texid, hrepeat, vrepeat, closed, steps);
}

void d3d_draw_ellipsoid(double x1, double y1, double z1, double x2, double y2, double z2, int* texid, int hrepeat, int vrepeat, int steps)
{
    addDelayedFunctionCall(FP_d3d_draw_ellipsoid, NULL, 0, x1, y1, z1, x2, y2, z2, texid, hrepeat, vrepeat, steps);
}

void d3d_draw_wall(double x1, double y1, double z1, double x2, double y2, double z2, int* texid, int hrepeat, int vrepeat)
{
    addDelayedFunctionCall(FP_d3d_draw_wall, NULL, 0, x1, y1, z1, x2, y2, z2, texid, hrepeat, vrepeat);
}

void d3d_draw_floor(double x1, double y1, double z1, double x2, double y2, double z2, int* texid, int hrepeat, int vrepeat)
{
    addDelayedFunctionCall(FP_d3d_draw_floor, NULL, 0, x1, y1, z1, x2, y2, z2, texid, hrepeat, vrepeat);
}

void d3d_set_projection_ortho(double x, double y, double w, double h, double angle)
{
    addDelayedFunctionCall(FP_d3d_set_projection_ortho, 0, 0, x, y, w, h, angle);
}

void d3d_set_projection_perspective(double x, double y, double w, double h, double angle)
{
    addDelayedFunctionCall(FP_d3d_set_projection_perspective, 0, 0, x, y, w, h, angle);
}

void d3d_set_projection(double xfrom, double yfrom, double zfrom, double xto, double yto, double zto, double xup, double yup, double zup)
{
    addDelayedFunctionCall(FP_d3d_set_projection, 0, 0, xfrom, yfrom, zfrom, xto, yto, zto, xup, yup, zup);
}

void d3d_start()
{
    addDelayedFunctionCall(FP_d3d_start, 0, 0);
}

void d3d_set_fog(double enable, double color, double start, double end)
{
    addDelayedFunctionCall(FP_d3d_set_fog, 0, 0, enable, color, start, end);
}

void d3d_set_lighting(double enable)
{
    addDelayedFunctionCall(FP_d3d_set_lighting, 0, 0, enable);
}
