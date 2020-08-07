//blockNetwork_makeSquare(array,value,x1,y1,x2,y2);

for (i=argument[3]; i<=argument[5]; i+=1)
{
    for (j=argument[2]; j<=argument[4]; j+=1)
    {
        argument[0].blocks[j,i] = argument[1];
    }
}
