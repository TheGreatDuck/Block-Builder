#ifdef DEFINE_WRAPPERS
ADD_FUNCTION(d3d_model_create)
ADD_FUNCTION(d3d_model_destroy)
ADD_FUNCTION(d3d_model_clear)
ADD_FUNCTION(d3d_model_save)
ADD_FUNCTION(d3d_model_load)
ADD_FUNCTION(d3d_model_draw)
ADD_FUNCTION(d3d_model_primitive_begin)
ADD_FUNCTION(d3d_model_vertex)
ADD_FUNCTION(d3d_model_vertex_color)
ADD_FUNCTION(d3d_model_vertex_texture)
ADD_FUNCTION(d3d_model_vertex_texture_color)
ADD_FUNCTION(d3d_model_vertex_normal)
ADD_FUNCTION(d3d_model_vertex_normal_color)
ADD_FUNCTION(d3d_model_vertex_normal_texture)
ADD_FUNCTION(d3d_model_vertex_normal_texture_color)
ADD_FUNCTION(d3d_model_primitive_end)
#endif

void d3d_model_create(int* ind);
#ifdef DEFINE_WRAPPERS
void d3d_model_create(int* ind)
{
    addDelayedFunctionCall(FP_d3d_model_create, ind, 1);
}
#endif
void d3d_model_destroy(double ind);
#ifdef DEFINE_WRAPPERS
void d3d_model_destroy(double ind)
{
    addDelayedFunctionCall(FP_d3d_model_destroy, NULL, 0, ind);
}
#endif
void d3d_model_load(int* ind, const char* fname);
#ifdef DEFINE_WRAPPERS
void d3d_model_load(int* ind, const char* fname)
{
    addDelayedFunctionCall(FP_d3d_model_load, NULL, 0, ind, fname);
}
#endif
void d3d_model_draw(int* ind, double x, double y, double z, int* texid);
#ifdef DEFINE_WRAPPERS
void d3d_model_draw(int* ind, double x, double y, double z, int* texid)
{
    addDelayedFunctionCall(FP_d3d_model_draw, NULL, 0, ind, x, y, z, texid);
}
#endif
void d3d_model_primitive_begin(int* ind, double kind);
#ifdef DEFINE_WRAPPERS
void d3d_model_primitive_begin(int* ind, double kind)
{
    addDelayedFunctionCall(FP_d3d_model_primitive_begin, NULL, 0, ind, kind);
}
#endif
void d3d_model_vertex_texture(int* ind, double x, double y, double z, double xtex, double ytex);
#ifdef DEFINE_WRAPPERS
void d3d_model_vertex_texture(int* ind, double x, double y, double z, double xtex, double ytex)
{
    addDelayedFunctionCall(FP_d3d_model_vertex_texture, NULL, 0, ind, x, y, z, xtex, ytex);
}
#endif
void d3d_model_primitive_end(int* ind);
#ifdef DEFINE_WRAPPERS
void d3d_model_primitive_end(int* ind)
{
    addDelayedFunctionCall(FP_d3d_model_primitive_end, NULL, 0, ind);
}
#endif
