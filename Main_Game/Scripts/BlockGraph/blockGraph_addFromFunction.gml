//blockGraph_addFromFunction(f, x1, x2, y1, y2, width, height)

var f;
f = argument[0];

var x1;
var x2;
x1 = argument[1];
x2 = argument[2];

var y1;
var y2;
y1 = argument[3];
y2 = argument[4];

var width;
var height;
width = argument[5];
height = argument[6];

var model;

var i;

for (i = 0; i < width; i+=1)
{
    var j;
    for (j = 0; j < height; j+=1)
    {
        var a1;
        var a2;
        var b1;
        var b2;
        var z11;
        var z12;
        var z21;
        var z22;
        var t;
        
        a1 = i*(x2-x1)/width + x1;
        a2 = (i+1)*(x2-x1)/width + x1;
        b1 = j*(y2-y1)/height + y1;
        b2 = (j+1)*(y2-y1)/height + y1;
        z11 = fun_eval(f,a1,b1,0);
        z12 = fun_eval(f,a2,b1,0);
        z21 = fun_eval(f,a1,b2,0);
        z22 = fun_eval(f,a2,b2,0);
        t = 1 + 1*(i == 0)*(j==0) + 5*(i==width-1)*(j==height-1);
        
        blockGraph[numberOfBlockModels,Block3D_v1x] = a1;
        blockGraph[numberOfBlockModels,Block3D_v1y] = b1;
        blockGraph[numberOfBlockModels,Block3D_v1z] = z11;
        blockGraph[numberOfBlockModels,Block3D_v2x] = a2;
        blockGraph[numberOfBlockModels,Block3D_v2y] = b1;
        blockGraph[numberOfBlockModels,Block3D_v2z] = z12;
        blockGraph[numberOfBlockModels,Block3D_v3x] = a1;
        blockGraph[numberOfBlockModels,Block3D_v3y] = b2;
        blockGraph[numberOfBlockModels,Block3D_v3z] = z21;
        blockGraph[numberOfBlockModels,Block3D_v4x] = a2;
        blockGraph[numberOfBlockModels,Block3D_v4y] = b2;
        blockGraph[numberOfBlockModels,Block3D_v4z] = z22;
        blockGraph[numberOfBlockModels,Block3D_adj1] = -1;
        blockGraph[numberOfBlockModels,Block3D_adj2] = -1;
        blockGraph[numberOfBlockModels,Block3D_adj3] = -1;
        blockGraph[numberOfBlockModels,Block3D_adj4] = -1;
        blockGraph[numberOfBlockModels,Block3D_type] = t;
        blockGraph[numberOfBlockModels,Block3D_removable] = true;
        numberOfBlockModels += 1;
    }
}

//show_message("the blocks have been created. Beginning the linking.");

//Link all of the blocks together
var j;

blockGraph[0,Block3D_adj3] = height;
blockGraph[0,Block3D_adj4] = 1;

for (j = 1; j < height-1; j+=1)
{
    blockGraph[j,Block3D_adj1] = j-1;
    blockGraph[j,Block3D_adj3] = j+height;
    blockGraph[j,Block3D_adj4] = j+1;
}

blockGraph[j,Block3D_adj1] = j-1;
blockGraph[j,Block3D_adj3] = j+height;

for (i = 1; i < width-1; i+=1)
{
    blockGraph[i*height,Block3D_adj2] = i*height - height;
    blockGraph[i*height,Block3D_adj3] = i*height + height;
    blockGraph[i*height,Block3D_adj4] = i*height + 1;
    var j;
    for (j = 1; j < height-1; j+=1)
    {
        blockGraph[i*height + j,Block3D_adj1] = i*height + j-1;
        blockGraph[i*height + j,Block3D_adj2] = i*height + j - height;
        blockGraph[i*height + j,Block3D_adj3] = i*height + j + height;
        blockGraph[i*height + j,Block3D_adj4] = i*height + j+1;
    }
    blockGraph[(i+1)*height - 1,Block3D_adj1] = (i+1)*height - 2;
    blockGraph[(i+1)*height - 1,Block3D_adj2] = i*height - 1;
    blockGraph[(i+1)*height - 1,Block3D_adj3] = (i+2)*height - 1;
}

blockGraph[i*height,Block3D_adj2] = i*height - height;
blockGraph[i*height,Block3D_adj4] = i*height + 1;
var j;
for (j = 1; j < height-1; j+=1)
{
    blockGraph[i*height + j,Block3D_adj1] = i*height + j-1;
    blockGraph[i*height + j,Block3D_adj2] = i*height + j - height;
    blockGraph[i*height + j,Block3D_adj4] = i*height + j+1;
}
blockGraph[i*height + j,Block3D_adj1] = i*height + j-1;
blockGraph[i*height + j,Block3D_adj2] = i*height + j - height;
