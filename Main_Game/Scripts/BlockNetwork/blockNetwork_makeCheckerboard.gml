//blockNetwork_makeCheckerboard(array,value1,value2,scale,x,y)

argument[3] = round(argument[3]);

for (i=y; i<y+(8*argument[3]); i+=argument[3])
{
    for (j=argument[5]; j<argument[5]+(8*argument[3]); j+=argument[3])
    {
        blockNetwork_makeSquare(argument[0],argument[1],j,i,j+argument[3]-1,i+argument[3]-1);
        j+=argument[3];
        blockNetwork_makeSquare(argument[0],argument[2],j,i,j+argument[3]-1,i+argument[3]-1);
    }
    i+=argument[3];
    for (j=argument[5]; j<argument[5]+(8*argument[3]); j+=argument[3])
    {
        blockNetwork_makeSquare(argument[0],argument[2],j,i,j+argument[3]-1,i+argument[3]-1);
        j+=argument[3];
        blockNetwork_makeSquare(argument[0],argument[1],j,i,j+argument[3]-1,i+argument[3]-1);
    }
}
