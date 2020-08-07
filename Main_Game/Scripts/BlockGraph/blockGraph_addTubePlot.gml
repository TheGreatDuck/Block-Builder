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

// Create and add all the neccessary faces to the scene
for (i = 0; i < numberOfSegments; i+=1)
{
    var j;
    for (j = 0; j < numberOfRotations; j+=1)
    {
        var p1x;
        var p1y;
        var p1z;
        var p2x;
        var p2y;
        var p2z;
        var p3x;
        var p3y;
        var p3z;
        var p4x;
        var p4y;
        var p4z;
        
        p2x = vx[i*numberOfRotations + j];
        p2y = vy[i*numberOfRotations + j];
        p2z = vz[i*numberOfRotations + j];
        p1x = vx[i*numberOfRotations + j + numberOfRotations]
        p1y = vy[i*numberOfRotations + j + numberOfRotations]
        p1z = vz[i*numberOfRotations + j + numberOfRotations];
        p4x = vx[i*numberOfRotations + ((j + 1) mod numberOfRotations)]
        p4y = vy[i*numberOfRotations + ((j + 1) mod numberOfRotations)]
        p4z = vz[i*numberOfRotations + ((j + 1) mod numberOfRotations)];
        p3x = vx[i*numberOfRotations + ((j + 1) mod numberOfRotations) + numberOfRotations]
        p3y = vy[i*numberOfRotations + ((j + 1) mod numberOfRotations) + numberOfRotations]
        p3z = vz[i*numberOfRotations + ((j + 1) mod numberOfRotations) + numberOfRotations];
        
        blockGraph_addSquare(p1x,p1y,p1z,p2x,p2y,p2z,p3x,p3y,p3z,p4x,p4y,p4z,(i >= 0) + (i==0) + 2*(i == numberOfSegments-1),true);
    }
}


//Link all of the blocks together
/*var j;

square_setAdjacentOne(model[0],model[numberOfRotations - 1]);
square_setAdjacentThree(model[0],model[numberOfRotations]);
square_setAdjacentFour(model[0],model[1 mod numberOfRotations]);

for (j = 1; j < numberOfRotations; j+=1)
{
    square_setAdjacentOne(model[j],model[j-1]);
    square_setAdjacentThree(model[j],model[j+ numberOfRotations]);
    square_setAdjacentFour(model[j],model[(j+1) mod numberOfRotations]);
}

for (i = 1; i < numberOfSegments; i+=1)
{
    square_setAdjacentOne(model[i*numberOfRotations],model[i*numberOfRotations + numberOfRotations - 1]);
    square_setAdjacentTwo(model[i*numberOfRotations],model[i*numberOfRotations - numberOfRotations]);
    square_setAdjacentThree(model[i*numberOfRotations],model[i*numberOfRotations + numberOfRotations]);
    square_setAdjacentFour(model[i*numberOfRotations],model[i*numberOfRotations + (1 mod numberOfRotations)]);
    var j;
    for (j = 1; j < numberOfRotations; j+=1)
    {
        square_setAdjacentOne(model[i*numberOfRotations + j],model[i*numberOfRotations + j-1]);
        square_setAdjacentTwo(model[i*numberOfRotations + j],model[i*numberOfRotations - numberOfRotations]);
        square_setAdjacentThree(model[i*numberOfRotations + j],model[i*numberOfRotations + j + numberOfRotations]);
        square_setAdjacentFour(model[i*numberOfRotations + j],model[i*numberOfRotations + ((j+1) mod numberOfRotations)]);
    }
}

square_setAdjacentOne(model[numberOfSegments*numberOfRotations],model[numberOfSegments*numberOfRotations + numberOfRotations - 1]);
square_setAdjacentTwo(model[numberOfSegments*numberOfRotations],model[numberOfSegments*numberOfRotations - numberOfRotations]);
square_setAdjacentFour(model[numberOfSegments*numberOfRotations],model[numberOfSegments*numberOfRotations + (1 mod numberOfRotations)]);
var j;
for (j = 1; j < numberOfRotations; j+=1)
{
    square_setAdjacentOne(model[numberOfSegments*numberOfRotations + j],model[numberOfSegments*numberOfRotations + j-1]);
    square_setAdjacentTwo(model[numberOfSegments*numberOfRotations + j],model[numberOfSegments*numberOfRotations - numberOfRotations]);
    square_setAdjacentFour(model[numberOfSegments*numberOfRotations + j],model[numberOfSegments*numberOfRotations + ((j+1) mod numberOfRotations)]);
}*/
