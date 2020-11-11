#ifdef DEFINE_WRAPPERS
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_transform_set_identity)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_transform_set_translation)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_transform_set_scaling)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_transform_set_rotation_x)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_transform_set_rotation_y)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_transform_set_rotation_z)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_transform_set_rotation_axis)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_transform_add_translation)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_transform_add_scaling)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_transform_add_rotation_x)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_transform_add_rotation_y)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_transform_add_rotation_z)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_transform_add_rotation_axis)
#endif

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void d3d_transform_set_identity();
#ifdef DEFINE_WRAPPERS
void d3d_transform_set_identity()
{
    addDelayedFunctionCall(FP_d3d_transform_set_identity, 0);
}
#endif

/** \brief
 *
 * \param x
 *
 * \param y
 *
 * \param z
 *
 * \return
 *
 */
void d3d_transform_set_translation(double x, double y, double z);
#ifdef DEFINE_WRAPPERS
void d3d_transform_set_translation(double x, double y, double z)
{
    addDelayedFunctionCall(FP_d3d_transform_set_translation, 0, x, y, z);
}
#endif

/** \brief
 *
 * \param xs
 *
 * \param ys
 *
 * \param zs
 *
 * \return
 *
 */
void d3d_transform_set_scaling(double xs, double ys, double zs);
#ifdef DEFINE_WRAPPERS
void d3d_transform_set_scaling(double xs, double ys, double zs)
{
    addDelayedFunctionCall(FP_d3d_transform_set_scaling, 0, xs, ys, zs);
}
#endif

/** \brief
 *
 * \param direction
 *
 * \return
 *
 */
void d3d_transform_set_rotation_x(double direction);
#ifdef DEFINE_WRAPPERS
void d3d_transform_set_rotation_x(double direction)
{
    addDelayedFunctionCall(FP_d3d_transform_set_rotation_x, 0, direction);
}
#endif

/** \brief
 *
 * \param direction
 *
 * \return
 *
 */
void d3d_transform_set_rotation_y(double direction);
#ifdef DEFINE_WRAPPERS
void d3d_transform_set_rotation_y(double direction)
{
    addDelayedFunctionCall(FP_d3d_transform_set_rotation_y, 0, direction);
}
#endif

/** \brief
 *
 * \param direction
 *
 * \return
 *
 */
void d3d_transform_set_rotation_z(double direction);
#ifdef DEFINE_WRAPPERS
void d3d_transform_set_rotation_z(double direction)
{
    addDelayedFunctionCall(FP_d3d_transform_set_rotation_z, 0, direction);
}
#endif

/** \brief
 *
 * \param xa
 *
 * \param ya
 *
 * \param za
 *
 * \param angle
 *
 * \return
 *
 */
void d3d_transform_set_rotation_axis(double xa, double ya, double za, double angle);
#ifdef DEFINE_WRAPPERS
void d3d_transform_set_rotation_axis(double xa, double ya, double za, double angle)
{
    addDelayedFunctionCall(FP_d3d_transform_set_rotation_axis, 0, xa, ya, za, angle);
}
#endif

/** \brief
 *
 * \param x
 *
 * \param y
 *
 * \param z
 *
 * \return
 *
 */
void d3d_transform_add_translation(double x, double y, double z);
#ifdef DEFINE_WRAPPERS
void d3d_transform_add_translation(double x, double y, double z)
{
    addDelayedFunctionCall(FP_d3d_transform_add_translation, 0, x, y, z);
}
#endif

/** \brief
 *
 * \param xs
 *
 * \param ys
 *
 * \param zs
 *
 * \return
 *
 */
void d3d_transform_add_scaling(double xs, double ys, double zs);
#ifdef DEFINE_WRAPPERS
void d3d_transform_add_scaling(double xs, double ys, double zs)
{
    addDelayedFunctionCall(FP_d3d_transform_add_scaling, 0, xs, ys, zs);
}
#endif

/** \brief
 *
 * \param direction
 *
 * \return
 *
 */
void d3d_transform_add_rotation_x(double direction);
#ifdef DEFINE_WRAPPERS
void d3d_transform_add_rotation_x(double direction)
{
    addDelayedFunctionCall(FP_d3d_transform_add_rotation_x, 0, direction);
}
#endif

/** \brief
 *
 * \param direction
 *
 * \return
 *
 */
void d3d_transform_add_rotation_y(double direction);
#ifdef DEFINE_WRAPPERS
void d3d_transform_add_rotation_y(double direction)
{
    addDelayedFunctionCall(FP_d3d_transform_add_rotation_y, 0, direction);
}
#endif

/** \brief
 *
 * \param direction
 *
 * \return
 *
 */
void d3d_transform_add_rotation_z(double direction);
#ifdef DEFINE_WRAPPERS
void d3d_transform_add_rotation_z(double direction)
{
    addDelayedFunctionCall(FP_d3d_transform_add_rotation_z, 0, direction);
}
#endif

/** \brief
 *
 * \param xa
 *
 * \param ya
 *
 * \param za
 *
 * \param angle
 *
 * \return
 *
 */
void d3d_transform_add_rotation_axis(double xa, double ya, double za, double angle);
#ifdef DEFINE_WRAPPERS
void d3d_transform_add_rotation_axis(double xa, double ya, double za, double angle)
{
    addDelayedFunctionCall(FP_d3d_transform_add_rotation_axis, 0, xa, ya, za, angle);
}
#endif
