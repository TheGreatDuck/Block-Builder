#ifdef DEFINE_WRAPPERS
ADD_FUNCTION(d3d_primitive_begin)
ADD_FUNCTION(d3d_vertex)
ADD_FUNCTION(d3d_vertex_color)
ADD_FUNCTION(d3d_primitive_end)

ADD_FUNCTION(d3d_primitive_begin_texture)
ADD_FUNCTION(d3d_vertex_texture)
ADD_FUNCTION(d3d_vertex_texture_color)

ADD_FUNCTION(d3d_vertex_normal)
ADD_FUNCTION(d3d_vertex_normal_color)
ADD_FUNCTION(d3d_vertex_normal_texture)
ADD_FUNCTION(d3d_vertex_normal_texture_color)
#endif

void d3d_primitive_begin(double kind);
#ifdef DEFINE_WRAPPERS
void d3d_primitive_begin(double kind)
{
    addDelayedFunctionCall(FP_d3d_primitive_begin, NULL, 0, kind);
}
#endif
void d3d_vertex(double x, double y, double z);
#ifdef DEFINE_WRAPPERS
void d3d_vertex(double x, double y, double z)
{
    addDelayedFunctionCall(FP_d3d_vertex, NULL, 0, x, y, z);
}
#endif
void d3d_vertex_color(double x, double y, double z, double col, double alpha);
#ifdef DEFINE_WRAPPERS
void d3d_vertex_color(double x, double y, double z, double col, double alpha)
{
    addDelayedFunctionCall(FP_d3d_vertex_color, NULL, 0, x, y, z, col, alpha);
}
#endif
void d3d_primitive_end();
#ifdef DEFINE_WRAPPERS
void d3d_primitive_end()
{
    addDelayedFunctionCall(FP_d3d_primitive_end, NULL, 0);
}
#endif
void d3d_primitive_begin_texture(double kind, int* texid);
#ifdef DEFINE_WRAPPERS
void d3d_primitive_begin_texture(double kind, int* texid)
{
    addDelayedFunctionCall(FP_d3d_primitive_begin_texture, NULL, 0, kind, texid);
}
#endif
void d3d_vertex_texture(double x, double y, double z, double xtex, double ytex);
#ifdef DEFINE_WRAPPERS
void d3d_vertex_texture(double x, double y, double z, double xtex, double ytex)
{
    addDelayedFunctionCall(FP_d3d_vertex_texture, NULL, 0, x, y, z, xtex, ytex);
}
#endif
void d3d_vertex_texture_color(double x,double y,double z,double xtex,double ytex,double col,double alpha);
#ifdef DEFINE_WRAPPERS
void d3d_vertex_texture_color(double x,double y,double z,double xtex,double ytex,double col,double alpha)
{
    addDelayedFunctionCall(FP_d3d_vertex_texture_color, NULL, 0,x,y,z,xtex,ytex,col,alpha);
}
#endif
void d3d_vertex_normal(double x,double y,double z,double nx,double ny,double nz);
#ifdef DEFINE_WRAPPERS
void d3d_vertex_normal(double x,double y,double z,double nx,double ny,double nz)
{
    addDelayedFunctionCall(FP_d3d_vertex_normal, NULL, 0,x,y,z,nx,ny,nz);
}
#endif
void d3d_vertex_normal_color(double x,double y,double z,double nx,double ny,double nz,double col,double alpha);
#ifdef DEFINE_WRAPPERS
void d3d_vertex_normal_color(double x,double y,double z,double nx,double ny,double nz,double col,double alpha)
{
    addDelayedFunctionCall(FP_d3d_vertex_normal_color, NULL, 0,x,y,z,nx,ny,nz,col,alpha);
}
#endif
void d3d_vertex_normal_texture(double x,double y,double z,double nx,double ny,double nz,double xtex,double ytex);
#ifdef DEFINE_WRAPPERS
void d3d_vertex_normal_texture(double x,double y,double z,double nx,double ny,double nz,double xtex,double ytex)
{
    addDelayedFunctionCall(FP_d3d_vertex_normal_texture, NULL, 0,x,y,z,nx,ny,nz,xtex,ytex);
}
#endif
void d3d_vertex_normal_texture_color(double x,double y,double z,double nx,double ny,double nz,double xtex,double ytex,double col,double alpha);
#ifdef DEFINE_WRAPPERS
void d3d_vertex_normal_texture_color(double x,double y,double z,double nx,double ny,double nz,double xtex,double ytex,double col,double alpha)
{
    addDelayedFunctionCall(FP_d3d_vertex_normal_texture_color, NULL, 0,x,y,z,nx,ny,nz,xtex,ytex,col,alpha);
}
#endif
