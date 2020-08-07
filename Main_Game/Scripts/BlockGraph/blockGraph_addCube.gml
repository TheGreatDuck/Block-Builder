//blockGraph_addCube(width, numberOfBlocks)

var width;
var numberOfBlocks;

width = argument[0];
numberOfBlocks = argument[1];

var face1;
var face2;
var face3;

for (i = 0; i < numberOfBlocks; i+=1)
{
    var j;
    for (j = 0; j < numberOfBlocks; j+=1)
    {
        var a1;
        var a2;
        var b1;
        var b2;
        
        a1 = i*(width)/numberOfBlocks;
        a2 = (i+1)*(width)/numberOfBlocks;
        b1 = j*(width)/numberOfBlocks;
        b2 = (j+1)*(width)/numberOfBlocks;
        
        blockGraph_addSquare(a1,b1,0,a2,b1,0,a1,b2,0,a2,b2,0,3,true);
        blockGraph_addSquare(a2,0,b1,a1,0,b1,a2,0,b2,a1,0,b2,3,true);
        blockGraph_addSquare(0,a1,b1,0,a2,b1,0,a1,b2,0,a2,b2,3,true);
        blockGraph_addSquare(a2,b1,width,a1,b1,width,a2,b2,width,a1,b2,width,3,true);
        blockGraph_addSquare(a1,width,b1,a2,width,b1,a1,width,b2,a2,width,b2,3,true);
        blockGraph_addSquare(width,a2,b1,width,a1,b1,width,a2,b2,width,a1,b2,3,true);
    }
}
