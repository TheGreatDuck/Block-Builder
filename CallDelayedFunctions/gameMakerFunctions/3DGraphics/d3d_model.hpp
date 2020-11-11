#ifdef DEFINE_WRAPPERS
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_model_create)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_model_destroy)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_model_clear)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_model_save)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_model_load)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_model_draw)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_model_primitive_begin)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_model_vertex)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_model_vertex_color)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_model_vertex_texture)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_model_vertex_texture_color)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_model_vertex_normal)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_model_vertex_normal_color)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_model_vertex_normal_texture)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_model_vertex_normal_texture_color)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_model_primitive_end)
#endif

/** \brief
 *
 * \param ind
 *
 * \return
 *
 */
double d3d_model_create();
#ifdef DEFINE_WRAPPERS
double d3d_model_create()
{
    return addDelayedFunctionCall(FP_d3d_model_create, 1);
}
#endif

/** \brief
 *
 * \param ind
 *
 * \return
 *
 */
void d3d_model_destroy(double ind);
#ifdef DEFINE_WRAPPERS
void d3d_model_destroy(double ind)
{
    addDelayedFunctionCall(FP_d3d_model_destroy, 0, ind);
}
#endif

/** \brief
 *
 * \param ind
 *
 * \param fname
 *
 * \return
 *
 */
void d3d_model_load(double ind, const char* fname);
#ifdef DEFINE_WRAPPERS
void d3d_model_load(double ind, const char* fname)
{
    addDelayedFunctionCall(FP_d3d_model_load, 0, ind, fname);
}
#endif

/** \brief
 *
 * \param ind
 *
 * \param x
 *
 * \param y
 *
 * \param z
 *
 * \param texid
 *
 * \return
 *
 */
void d3d_model_draw(double ind, double x, double y, double z, double texid);
#ifdef DEFINE_WRAPPERS
void d3d_model_draw(double ind, double x, double y, double z, double texid)
{
    addDelayedFunctionCall(FP_d3d_model_draw, 0, ind, x, y, z, texid);
}
#endif

/** \brief
 *
 * \param ind
 *
 * \param kind
 *
 * \return
 *
 */
void d3d_model_primitive_begin(double ind, double kind);
#ifdef DEFINE_WRAPPERS
void d3d_model_primitive_begin(double ind, double kind)
{
    addDelayedFunctionCall(FP_d3d_model_primitive_begin, 0, ind, kind);
}
#endif

/** \brief
 *
 * \param ind
 *
 * \param x
 *
 * \param y
 *
 * \param z
 *
 * \param xtex
 *
 * \param ytex
 *
 * \return
 *
 */
void d3d_model_vertex_texture(double ind, double x, double y, double z, double xtex, double ytex);
#ifdef DEFINE_WRAPPERS
void d3d_model_vertex_texture(double ind, double x, double y, double z, double xtex, double ytex)
{
    addDelayedFunctionCall(FP_d3d_model_vertex_texture, 0, ind, x, y, z, xtex, ytex);
}
#endif

/** \brief
 *
 * \param ind
 *
 * \return
 *
 */
void d3d_model_primitive_end(double ind);
#ifdef DEFINE_WRAPPERS
void d3d_model_primitive_end(double ind)
{
    addDelayedFunctionCall(FP_d3d_model_primitive_end, 0, ind);
}
#endif
