#define GMEXPORT extern "C"

#define pr_pointlist 1
#define pr_linelist 2
#define pr_linestrip 3
#define pr_trianglelist 4
#define pr_trianglestrip 5
#define pr_trianglefan 6

GMEXPORT double removeDelayedFunctionCall();
GMEXPORT double getInputDelayedVariable(double input);
GMEXPORT char* getInputText(double input);
GMEXPORT double getInputNumber(double input);
GMEXPORT double getInputType(double input);
GMEXPORT double getFunction();
GMEXPORT double setDelayedOutput(double value);
GMEXPORT double getHasOutput();
GMEXPORT double isThereDelayedFunctionCall();

GMEXPORT double export_d3d_draw_block(double functionPointer);
GMEXPORT double export_d3d_draw_cylinder(double functionPointer);
GMEXPORT double export_d3d_draw_cone(double functionPointer);
GMEXPORT double export_d3d_draw_ellipsoid(double functionPointer);
GMEXPORT double export_d3d_draw_wall(double functionPointer);
GMEXPORT double export_d3d_draw_floor(double functionPointer);
GMEXPORT double export_d3d_transform_set_identity(double functionPointer);
GMEXPORT double export_d3d_transform_add_rotation_x(double functionPointer);
GMEXPORT double export_d3d_transform_add_rotation_y(double functionPointer);
GMEXPORT double export_d3d_transform_add_rotation_z(double functionPointer);
GMEXPORT double export_d3d_transform_add_translation(double functionPointer);
GMEXPORT double export_d3d_transform_add_rotation_axis(double functionPointer);
GMEXPORT double export_sprite_get_texture(double functionPointer);
GMEXPORT double export_d3d_primitive_begin(double functionPointer);
GMEXPORT double export_d3d_vertex(double functionPointer);
GMEXPORT double export_d3d_vertex_color(double functionPointer);
GMEXPORT double export_d3d_primitive_end(double functionPointer);
GMEXPORT double export_d3d_model_draw(double functionPointer);
GMEXPORT double export_d3d_model_create(double functionPointer);
GMEXPORT double export_d3d_model_load(double functionPointer);
GMEXPORT double export_sprite_add(double functionPointer);
GMEXPORT double export_d3d_transform_add_scaling(double functionPointer);

void d3d_draw_block(double x1, double y1, double z1, double x2, double y2, double z2, int* texid, int hrepeat, int vrepeat);
void d3d_draw_cylinder(double x1, double y1, double z1, double x2, double y2, double z2, int* texid, int hrepeat, int vrepeat, int closed, int steps);
void d3d_draw_cone(double x1, double y1, double z1, double x2, double y2, double z2, int* texid, int hrepeat, int vrepeat, int closed, int steps);
void d3d_draw_ellipsoid(double x1, double y1, double z1, double x2, double y2, double z2, int* texid, int hrepeat, int vrepeat, int steps);
void d3d_draw_wall(double x1, double y1, double z1, double x2, double y2, double z2, int* texid, int hrepeat, int vrepeat);
void d3d_draw_floor(double x1, double y1, double z1, double x2, double y2, double z2, int* texid, int hrepeat, int vrepeat);
void d3d_transform_set_identity();
void d3d_transform_add_rotation_x(double direction);
void d3d_transform_add_rotation_y(double direction);
void d3d_transform_add_rotation_z(double direction);
void d3d_transform_add_translation(double x, double y, double z);
void d3d_transform_add_rotation_axis(double xa, double ya, double za,double angle);
void sprite_get_texture(int* spr, double subimg, int* returnValue);
void d3d_primitive_begin(double kind);
void d3d_vertex(double x, double y, double z);
void d3d_vertex_color(double x, double y, double z, double col, double alpha);
void d3d_primitive_end();
void d3d_model_draw(int* ind, double x, double y, double z, int* texid);
void d3d_model_create(int* ind);
void d3d_model_load(int* ind, const char* fname);
void sprite_add(const char* fname, int imgnumb, int removeback, int smooth, int xorig, int yorig, int* ind);
void d3d_transform_add_scaling(double xs, double ys, double zs);
void d3d_set_projection_ortho(double x, double y, double w, double h, double angle);
void d3d_set_projection_perspective( double x, double y, double w, double h, double angle);
void d3d_set_projection(double xfrom, double yfrom, double zfrom, double xto, double yto, double zto, double xup, double yup, double zup);
void d3d_model_primitive_begin(int* ind, double kind);
void d3d_model_vertex_texture(int* ind, double x, double y, double z, double xtex, double ytex);
void d3d_model_primitive_end(int* ind);
void d3d_model_destroy(double ind);
void d3d_start();
void d3d_set_fog(double enable, double color, double start, double end);
void d3d_set_lighting(double enable);
