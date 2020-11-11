#ifdef DEFINE_WRAPPERS
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_primitive_begin)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_vertex)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_vertex_color)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_primitive_end)


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_primitive_begin_texture)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_vertex_texture)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_vertex_texture_color)


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_vertex_normal)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_vertex_normal_color)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_vertex_normal_texture)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
ADD_FUNCTION(d3d_vertex_normal_texture_color)
#endif

/** \brief
 *
 * \param kind
 *
 * \return
 *
 */
void d3d_primitive_begin(double kind);
#ifdef DEFINE_WRAPPERS
void d3d_primitive_begin(double kind)
{
    addDelayedFunctionCall(FP_d3d_primitive_begin, 0, kind);
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
void d3d_vertex(double x, double y, double z);
#ifdef DEFINE_WRAPPERS
void d3d_vertex(double x, double y, double z)
{
    addDelayedFunctionCall(FP_d3d_vertex, 0, x, y, z);
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
 * \param col
 *
 * \param alpha
 *
 * \return
 *
 */
void d3d_vertex_color(double x, double y, double z, double col, double alpha);
#ifdef DEFINE_WRAPPERS
void d3d_vertex_color(double x, double y, double z, double col, double alpha)
{
    addDelayedFunctionCall(FP_d3d_vertex_color, 0, x, y, z, col, alpha);
}
#endif

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void d3d_primitive_end();
#ifdef DEFINE_WRAPPERS
void d3d_primitive_end()
{
    addDelayedFunctionCall(FP_d3d_primitive_end, 0);
}
#endif

/** \brief
 *
 * \param kind
 *
 * \param texid
 *
 * \return
 *
 */
void d3d_primitive_begin_texture(double kind, double texid);
#ifdef DEFINE_WRAPPERS
void d3d_primitive_begin_texture(double kind, double texid)
{
    addDelayedFunctionCall(FP_d3d_primitive_begin_texture, 0, kind, texid);
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
 * \param xtex
 *
 * \param ytex
 *
 * \return
 *
 */
void d3d_vertex_texture(double x, double y, double z, double xtex, double ytex);
#ifdef DEFINE_WRAPPERS
void d3d_vertex_texture(double x, double y, double z, double xtex, double ytex)
{
    addDelayedFunctionCall(FP_d3d_vertex_texture, 0, x, y, z, xtex, ytex);
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
 * \param xtex
 *
 * \param ytex
 *
 * \param col
 *
 * \param alpha
 *
 * \return
 *
 */
void d3d_vertex_texture_color(double x,double y,double z,double xtex,double ytex,double col,double alpha);
#ifdef DEFINE_WRAPPERS
void d3d_vertex_texture_color(double x,double y,double z,double xtex,double ytex,double col,double alpha)
{
    addDelayedFunctionCall(FP_d3d_vertex_texture_color, 0,x,y,z,xtex,ytex,col,alpha);
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
 * \param nx
 *
 * \param ny
 *
 * \param nz
 *
 * \return
 *
 */
void d3d_vertex_normal(double x,double y,double z,double nx,double ny,double nz);
#ifdef DEFINE_WRAPPERS
void d3d_vertex_normal(double x,double y,double z,double nx,double ny,double nz)
{
    addDelayedFunctionCall(FP_d3d_vertex_normal, 0,x,y,z,nx,ny,nz);
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
 * \param nx
 *
 * \param ny
 *
 * \param nz
 *
 * \param col
 *
 * \param alpha
 *
 * \return
 *
 */
void d3d_vertex_normal_color(double x,double y,double z,double nx,double ny,double nz,double col,double alpha);
#ifdef DEFINE_WRAPPERS
void d3d_vertex_normal_color(double x,double y,double z,double nx,double ny,double nz,double col,double alpha)
{
    addDelayedFunctionCall(FP_d3d_vertex_normal_color, 0,x,y,z,nx,ny,nz,col,alpha);
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
 * \param nx
 *
 * \param ny
 *
 * \param xtex
 *
 * \param ytex
 *
 * \return
 *
 */
void d3d_vertex_normal_texture(double x,double y,double z,double nx,double ny,double nz,double xtex,double ytex);
#ifdef DEFINE_WRAPPERS
void d3d_vertex_normal_texture(double x,double y,double z,double nx,double ny,double nz,double xtex,double ytex)
{
    addDelayedFunctionCall(FP_d3d_vertex_normal_texture, 0,x,y,z,nx,ny,nz,xtex,ytex);
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
 * \param nx
 *
 * \param ny
 *
 * \param nz
 *
 * \param xtex
 *
 * \param ytex
 *
 * \param col
 *
 * \param alpha
 *
 * \return
 *
 */
void d3d_vertex_normal_texture_color(double x,double y,double z,double nx,double ny,double nz,double xtex,double ytex,double col,double alpha);
#ifdef DEFINE_WRAPPERS
void d3d_vertex_normal_texture_color(double x,double y,double z,double nx,double ny,double nz,double xtex,double ytex,double col,double alpha)
{
    addDelayedFunctionCall(FP_d3d_vertex_normal_texture_color, 0,x,y,z,nx,ny,nz,xtex,ytex,col,alpha);
}
#endif
