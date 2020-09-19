ADD_FUNCTION(d3d_transform_set_identity)
ADD_FUNCTION(d3d_transform_set_translation)
ADD_FUNCTION(d3d_transform_set_scaling)
ADD_FUNCTION(d3d_transform_set_rotation_x)
ADD_FUNCTION(d3d_transform_set_rotation_y)
ADD_FUNCTION(d3d_transform_set_rotation_z)
ADD_FUNCTION(d3d_transform_set_rotation_axis)
ADD_FUNCTION(d3d_transform_add_translation)
ADD_FUNCTION(d3d_transform_add_scaling)
ADD_FUNCTION(d3d_transform_add_rotation_x)
ADD_FUNCTION(d3d_transform_add_rotation_y)
ADD_FUNCTION(d3d_transform_add_rotation_z)
ADD_FUNCTION(d3d_transform_add_rotation_axis)

void d3d_transform_set_identity()
{
    addDelayedFunctionCall(FP_d3d_transform_set_identity, NULL, 0);
}

void d3d_transform_set_translation(double x, double y, double z)
{
    addDelayedFunctionCall(FP_d3d_transform_set_translation, NULL, 0, x, y, z);
}

void d3d_transform_set_scaling(double xs, double ys, double zs)
{
    addDelayedFunctionCall(FP_d3d_transform_set_scaling, 0, 0, xs, ys, zs);
}

void d3d_transform_set_rotation_x(double direction)
{
    addDelayedFunctionCall(FP_d3d_transform_set_rotation_x, NULL, 0, direction);
}

void d3d_transform_set_rotation_y(double direction)
{
    addDelayedFunctionCall(FP_d3d_transform_set_rotation_y, NULL, 0, direction);
}

void d3d_transform_set_rotation_z(double direction)
{
    addDelayedFunctionCall(FP_d3d_transform_set_rotation_z, NULL, 0, direction);
}

void d3d_transform_set_rotation_axis(double xa, double ya, double za, double angle)
{
    addDelayedFunctionCall(FP_d3d_transform_set_rotation_axis, NULL, 0, xa, ya, za, angle);
}

void d3d_transform_add_translation(double x, double y, double z)
{
    addDelayedFunctionCall(FP_d3d_transform_add_translation, NULL, 0, x, y, z);
}

void d3d_transform_add_scaling(double xs, double ys, double zs)
{
    addDelayedFunctionCall(FP_d3d_transform_add_scaling, 0, 0, xs, ys, zs);
}

void d3d_transform_add_rotation_x(double direction)
{
    addDelayedFunctionCall(FP_d3d_transform_add_rotation_x, NULL, 0, direction);
}

void d3d_transform_add_rotation_y(double direction)
{
    addDelayedFunctionCall(FP_d3d_transform_add_rotation_y, NULL, 0, direction);
}

void d3d_transform_add_rotation_z(double direction)
{
    addDelayedFunctionCall(FP_d3d_transform_add_rotation_z, NULL, 0, direction);
}

void d3d_transform_add_rotation_axis(double xa, double ya, double za, double angle)
{
    addDelayedFunctionCall(FP_d3d_transform_add_rotation_axis, NULL, 0, xa, ya, za, angle);
}
