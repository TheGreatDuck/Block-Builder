argument[1] = d3d_model_create();
d3d_model_primitive_begin(argument[1],pr_trianglelist);

argument[2] = -10;

while (argument[2] < 10)
{
    argument[3] = -10;
    while (argument[3] < 10)
    {
        d3d_model_vertex_texture(argument[1],argument[3],argument[2],fun_eval(argument[0],argument[3],argument[2],0),0,0);
        d3d_model_vertex_texture(argument[1],argument[3],argument[2]+1,fun_eval(argument[0],argument[3],argument[2]+1,0),0,1);
        d3d_model_vertex_texture(argument[1],argument[3]+1,argument[2]+1,fun_eval(argument[0],argument[3]+1,argument[2]+1,0),1,1);
        
        
        d3d_model_vertex_texture(argument[1],argument[3]+1,argument[2]+1,fun_eval(argument[0],argument[3]+1,argument[2]+1,0),1,1);
        d3d_model_vertex_texture(argument[1],argument[3],argument[2]+1,fun_eval(argument[0],argument[3],argument[2]+1,0),0,1);
        d3d_model_vertex_texture(argument[1],argument[3],argument[2],fun_eval(argument[0],argument[3],argument[2],0),0,0);
        
        d3d_model_vertex_texture(argument[1],argument[3],argument[2],fun_eval(argument[0],argument[3],argument[2],0),0,0);
        d3d_model_vertex_texture(argument[1],argument[3]+1,argument[2]+1,fun_eval(argument[0],argument[3]+1,argument[2]+1,0),1,1);
        d3d_model_vertex_texture(argument[1],argument[3]+1,argument[2],fun_eval(argument[0],argument[3]+1,argument[2],0),1,0);
        
        d3d_model_vertex_texture(argument[1],argument[3]+1,argument[2],fun_eval(argument[0],argument[3]+1,argument[2],0),1,0);
        d3d_model_vertex_texture(argument[1],argument[3]+1,argument[2]+1,fun_eval(argument[0],argument[3]+1,argument[2]+1,0),1,1);
        d3d_model_vertex_texture(argument[1],argument[3],argument[2],fun_eval(argument[0],argument[3],argument[2],0),0,0);
        argument[3] += 1;
    }
    argument[2] += 1;
}
   
d3d_model_primitive_end(argument[1]);
return argument[1];
