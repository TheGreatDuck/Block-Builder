argument[1] = d3d_model_create();
d3d_model_primitive_begin(argument[1],pr_trianglelist);

var x1;
x1 = -10;

while (x1 < 10)
{
    var r1;
    r1 = fun_eval(argument[0],x1,0,0);
    var r2;
    r2 = fun_eval(argument[0],x1+1,0,0);
    var angle;
    angle = 0;
    while (angle < 2*pi)
    {
        d3d_model_vertex_texture(argument[1],x1,cos(angle)*r1,sin(angle)*r1,0,0);
        d3d_model_vertex_texture(argument[1],x1,cos(angle + pi/10)*r1,sin(angle + pi/10)*r1,0,1);
        d3d_model_vertex_texture(argument[1],x1+1,cos(angle + pi/10)*r2,sin(angle + pi/10)*r2,1,1);
        
        d3d_model_vertex_texture(argument[1],x1+1,cos(angle + pi/10)*r2,sin(angle + pi/10)*r2,1,1);
        d3d_model_vertex_texture(argument[1],x1,cos(angle + pi/10)*r1,sin(angle + pi/10)*r1,0,1);
        d3d_model_vertex_texture(argument[1],x1,cos(angle)*r1,sin(angle)*r1,0,0);
        
        d3d_model_vertex_texture(argument[1],x1,cos(angle)*r1,sin(angle)*r1,0,0);
        d3d_model_vertex_texture(argument[1],x1+1,cos(angle + pi/10)*r2,sin(angle + pi/10)*r2,1,1);
        d3d_model_vertex_texture(argument[1],x1+1,cos(angle)*r2,sin(angle)*r2,1,0);
        
        d3d_model_vertex_texture(argument[1],x1+1,cos(angle)*r2,sin(angle)*r2,1,0);
        d3d_model_vertex_texture(argument[1],x1+1,cos(angle + pi/10)*r2,sin(angle + pi/10)*r2,1,1);
        d3d_model_vertex_texture(argument[1],x1,cos(angle)*r1,sin(angle)*r1,0,0);
        angle += pi/10;
    }
    x1 += 1;
}
   
d3d_model_primitive_end(argument[1]);
return argument[1];
