//fun_tubePlot(f1, f2, f3, t1, t2, numberOfSegments, numberOfRotations, radius, angle)
var f1;
var f2;
var f3;
var t1;
var t2;
var numberOfSegments;
var numberOfRotations;
var radius;
var angle;

f1 = argument[0];
f2 = argument[1];
f3 = argument[2];
t1 = argument[3];
t2 = argument[4];
numberOfSegments = argument[5];
numberOfRotations = argument[6];
radius = argument[7];
angle = argument[8];

var i;
var vx;
var vy;
var vz;

var df1;
var df2;
var df3;

df1 = fun_xImpliedDerivative(f1);
df2 = fun_xImpliedDerivative(f2);
df3 = fun_xImpliedDerivative(f3);

var ddf1;
var ddf2;
var ddf3;

ddf1 = fun_xImpliedDerivative(df1);
ddf2 = fun_xImpliedDerivative(df2);
ddf3 = fun_xImpliedDerivative(df3);

for (i = 0; i <= numberOfSegments; i+=1)
{
    var currentPoint_x;
    var currentPoint_y;
    var currentPoint_z;
    
    currentPoint_x = fun_eval(f1,(i) * (t2-t1)/numberOfSegments + t1,0,0);
    currentPoint_y = fun_eval(f2,(i) * (t2-t1)/numberOfSegments + t1,0,0);
    currentPoint_z = fun_eval(f3,(i) * (t2-t1)/numberOfSegments + t1,0,0);
    
    var directionZ_x;
    var directionZ_y;
    var directionZ_z;
    
    directionZ_x = fun_eval(df1,(i) * (t2-t1)/numberOfSegments + t1,0,0);
    directionZ_y = fun_eval(df2,(i) * (t2-t1)/numberOfSegments + t1,0,0);
    directionZ_z = fun_eval(df3,(i) * (t2-t1)/numberOfSegments + t1,0,0);
    
    
    var lengthOfZ;
    lengthOfZ = sqrt((directionZ_x*directionZ_x) + (directionZ_y*directionZ_y) + (directionZ_z*directionZ_z));
    
    var unitZ_x;
    var unitZ_y;
    var unitZ_z;
    unitZ_x = directionZ_x/lengthOfZ;
    unitZ_y = directionZ_y/lengthOfZ;
    unitZ_z = directionZ_z/lengthOfZ;
    
    var directionY_x;
    var directionY_y;
    var directionY_z;
    directionY_x = fun_eval(ddf1,(i) * (t2-t1)/numberOfSegments + t1,0,0);
    directionY_y = fun_eval(ddf2,(i) * (t2-t1)/numberOfSegments + t1,0,0);
    directionY_z = fun_eval(ddf3,(i) * (t2-t1)/numberOfSegments + t1,0,0);
    
    var lengthOfY;
    lengthOfY = sqrt((directionY_x*directionY_x) + (directionY_y*directionY_y) + (directionY_z*directionY_z));
    
    var unitY_x;
    var unitY_y;
    var unitY_z;
    unitY_x = directionY_x/lengthOfY;
    unitY_y = directionY_y/lengthOfY;
    unitY_z = directionY_z/lengthOfY;
    
    var unitX_x;
    var unitX_y;
    var unitX_z;
    unitX_x = unitZ_y*unitY_z-unitZ_z*unitY_y;
    unitX_y = unitZ_z*unitY_x-unitZ_x*unitY_z;
    unitX_z = unitZ_x*unitY_y-unitZ_y*unitY_x;
    
    /*apply the scaling transformation to the coordinate system*/
    var r;
    r = fun_eval(radius,(i+1) * (t2 - t1)/numberOfSegments + t1,0,0);
    unitX_x *= r;
    unitX_y *= r;
    unitX_z *= r;
    unitY_x *= r;
    unitY_y *= r;
    unitY_z *= r;
    /*add this disk to the list of vertices*/
    var j;
    for (j = 0; j < numberOfRotations; j+=1)
    {
        var theta;
        theta = j*2*pi/numberOfRotations + fun_eval(angle,(i+1) * (t2 - t1)/numberOfSegments + t1,0,0);
        vx[i*numberOfRotations + j] = unitX_y*cos(theta)+unitY_y*sin(theta)+currentPoint_y;
        vy[i*numberOfRotations + j] = unitX_z*cos(theta)+unitY_z*sin(theta)+currentPoint_z;
        vz[i*numberOfRotations + j] = unitX_x*cos(theta)+unitY_x*sin(theta)+currentPoint_x;
    }
}

var model;
model = d3d_model_create();
d3d_model_primitive_begin(model,pr_trianglelist);

// Create and add all the neccessary faces to the scene
for (i = 0; i < numberOfSegments - 1; i+=1)
{
    var j;
    for (j = 0; j < numberOfRotations; j+=1)
    {
        d3d_model_vertex_texture(model,vx[i*numberOfRotations + ((j + 1) mod numberOfRotations) + numberOfRotations],vy[i*numberOfRotations + ((j + 1) mod numberOfRotations) + numberOfRotations],vz[i*numberOfRotations + ((j + 1) mod numberOfRotations) + numberOfRotations],1,1);
        d3d_model_vertex_texture(model,vx[i*numberOfRotations + ((j + 1) mod numberOfRotations)],vy[i*numberOfRotations + ((j + 1) mod numberOfRotations)],vz[i*numberOfRotations + ((j + 1) mod numberOfRotations)],0,1);
        d3d_model_vertex_texture(model,vx[i*numberOfRotations + j],vy[i*numberOfRotations + j],vz[i*numberOfRotations + j],0,0);
        
        d3d_model_vertex_texture(model,vx[i*numberOfRotations + j + numberOfRotations],vy[i*numberOfRotations + j + numberOfRotations],vz[i*numberOfRotations + j + numberOfRotations],1,0);
        d3d_model_vertex_texture(model,vx[i*numberOfRotations + ((j + 1) mod numberOfRotations) + numberOfRotations],vy[i*numberOfRotations + ((j + 1) mod numberOfRotations) + numberOfRotations],vz[i*numberOfRotations + ((j + 1) mod numberOfRotations) + numberOfRotations],1,1);
        d3d_model_vertex_texture(model,vx[i*numberOfRotations + j],vy[i*numberOfRotations + j],vz[i*numberOfRotations + j],0,0);
    }
}

for (i = 0; i <= numberOfSegments - 1; i+=1)
{
    var j;
    for (j = 0; j < numberOfRotations; j+=1)
    {
        d3d_model_vertex_texture(model,vx[i*numberOfRotations + j],vy[i*numberOfRotations + j],vz[i*numberOfRotations + j],0,0);
        d3d_model_vertex_texture(model,vx[i*numberOfRotations + ((j + 1) mod numberOfRotations)],vy[i*numberOfRotations + ((j + 1) mod numberOfRotations)],vz[i*numberOfRotations + ((j + 1) mod numberOfRotations)],0,1);
        d3d_model_vertex_texture(model,vx[i*numberOfRotations + ((j + 1) mod numberOfRotations) + numberOfRotations],vy[i*numberOfRotations + ((j + 1) mod numberOfRotations) + numberOfRotations],vz[i*numberOfRotations + ((j + 1) mod numberOfRotations) + numberOfRotations],1,1);
        
        d3d_model_vertex_texture(model,vx[i*numberOfRotations + j],vy[i*numberOfRotations + j],vz[i*numberOfRotations + j],0,0);
        d3d_model_vertex_texture(model,vx[i*numberOfRotations + ((j + 1) mod numberOfRotations) + numberOfRotations],vy[i*numberOfRotations + ((j + 1) mod numberOfRotations) + numberOfRotations],vz[i*numberOfRotations + ((j + 1) mod numberOfRotations) + numberOfRotations],1,1);
        d3d_model_vertex_texture(model,vx[i*numberOfRotations + j + numberOfRotations],vy[i*numberOfRotations + j + numberOfRotations],vz[i*numberOfRotations + j + numberOfRotations],1,0);
    }
}

d3d_model_primitive_end(model);
return model;
