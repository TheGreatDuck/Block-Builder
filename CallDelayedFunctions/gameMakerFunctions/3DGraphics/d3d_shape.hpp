#ifdef DEFINE_WRAPPERS
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_draw_block)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_draw_cylinder)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_draw_cone)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_draw_ellipsoid)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_draw_wall)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_draw_floor)


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_set_projection_ortho)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_set_projection_perspective)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_set_projection)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_start)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_set_fog)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_set_lighting)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_set_culling)
#endif

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void d3d_draw_block(double x1, double y1, double z1, double x2, double y2, double z2, double texid, int hrepeat, int vrepeat);
#ifdef DEFINE_WRAPPERS
void d3d_draw_block(double x1, double y1, double z1, double x2, double y2, double z2, double texid, int hrepeat, int vrepeat)
{
    addDelayedFunctionCall(FP_d3d_draw_block, 0, x1, y1, z1, x2, y2, z2, texid, hrepeat, vrepeat);
}
#endif

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void d3d_draw_cylinder(double x1, double y1, double z1, double x2, double y2, double z2, double texid, int hrepeat, int vrepeat, int closed, int steps);
#ifdef DEFINE_WRAPPERS
void d3d_draw_cylinder(double x1, double y1, double z1, double x2, double y2, double z2, double texid, int hrepeat, int vrepeat, int closed, int steps)
{
    addDelayedFunctionCall(FP_d3d_draw_cylinder, 0, x1, y1, z1, x2, y2, z2, texid, hrepeat, vrepeat, closed, steps);
}
#endif

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void d3d_draw_cone(double x1, double y1, double z1, double x2, double y2, double z2, double texid, int hrepeat, int vrepeat, int closed, int steps);
#ifdef DEFINE_WRAPPERS
void d3d_draw_cone(double x1, double y1, double z1, double x2, double y2, double z2, double texid, int hrepeat, int vrepeat, int closed, int steps)
{
    addDelayedFunctionCall(FP_d3d_draw_cone, 0, x1, y1, z1, x2, y2, z2, texid, hrepeat, vrepeat, closed, steps);
}
#endif

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void d3d_draw_ellipsoid(double x1, double y1, double z1, double x2, double y2, double z2, double texid, int hrepeat, int vrepeat, int steps);
#ifdef DEFINE_WRAPPERS
void d3d_draw_ellipsoid(double x1, double y1, double z1, double x2, double y2, double z2, double texid, int hrepeat, int vrepeat, int steps)
{
    addDelayedFunctionCall(FP_d3d_draw_ellipsoid, 0, x1, y1, z1, x2, y2, z2, texid, hrepeat, vrepeat, steps);
}
#endif

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void d3d_draw_wall(double x1, double y1, double z1, double x2, double y2, double z2, double texid, int hrepeat, int vrepeat);
#ifdef DEFINE_WRAPPERS
void d3d_draw_wall(double x1, double y1, double z1, double x2, double y2, double z2, double texid, int hrepeat, int vrepeat)
{
    addDelayedFunctionCall(FP_d3d_draw_wall, 0, x1, y1, z1, x2, y2, z2, texid, hrepeat, vrepeat);
}
#endif

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void d3d_draw_floor(double x1, double y1, double z1, double x2, double y2, double z2, double texid, int hrepeat, int vrepeat);
#ifdef DEFINE_WRAPPERS
void d3d_draw_floor(double x1, double y1, double z1, double x2, double y2, double z2, double texid, int hrepeat, int vrepeat)
{
    addDelayedFunctionCall(FP_d3d_draw_floor, 0, x1, y1, z1, x2, y2, z2, texid, hrepeat, vrepeat);
}
#endif

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void d3d_set_projection_ortho(double x, double y, double w, double h, double angle);
#ifdef DEFINE_WRAPPERS
void d3d_set_projection_ortho(double x, double y, double w, double h, double angle)
{
    addDelayedFunctionCall(FP_d3d_set_projection_ortho, 0, x, y, w, h, angle);
}
#endif

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void d3d_set_projection_perspective(double x, double y, double w, double h, double angle);
#ifdef DEFINE_WRAPPERS
void d3d_set_projection_perspective(double x, double y, double w, double h, double angle)
{
    addDelayedFunctionCall(FP_d3d_set_projection_perspective, 0, x, y, w, h, angle);
}
#endif

/** \brief
 *
 * \param
 *
 * \param
 *
 * \param
 *
 * \param
 *
 * \param
 *
 * \param
 *
 * \param
 *
 * \param
 *
 * \param
 *
 * \return
 *
 */
void d3d_set_projection(double xfrom, double yfrom, double zfrom, double xto, double yto, double zto, double xup, double yup, double zup);
#ifdef DEFINE_WRAPPERS
void d3d_set_projection(double xfrom, double yfrom, double zfrom, double xto, double yto, double zto, double xup, double yup, double zup)
{
    addDelayedFunctionCall(FP_d3d_set_projection, 0, xfrom, yfrom, zfrom, xto, yto, zto, xup, yup, zup);
}
#endif

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void d3d_start();
#ifdef DEFINE_WRAPPERS
void d3d_start()
{
    addDelayedFunctionCall(FP_d3d_start, 0);
}
#endif

/** \brief
 *
 * \param enable
 *
 * \param color
 *
 * \param start
 *
 * \param end
 *
 * \return
 *
 */
void d3d_set_fog(double enable, double color, double start, double end);
#ifdef DEFINE_WRAPPERS
void d3d_set_fog(double enable, double color, double start, double end)
{
    addDelayedFunctionCall(FP_d3d_set_fog, 0, enable, color, start, end);
}
#endif

/** \brief
 *
 * \param enable
 *
 * \return
 *
 */
void d3d_set_lighting(double enable);
#ifdef DEFINE_WRAPPERS
void d3d_set_lighting(double enable)
{
    addDelayedFunctionCall(FP_d3d_set_lighting, 0, enable);
}
#endif
