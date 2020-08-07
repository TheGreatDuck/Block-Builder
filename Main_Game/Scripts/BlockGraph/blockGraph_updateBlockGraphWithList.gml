with (obj_blockGraph)
{
    var changed;
    for (i = 0; i  < ceil(numberOfBlockModels/blockModelCapacity); i+=1)
    {
        changed[i] = 0;
    }
    
    var k
    for (k = 0; k < blockUpdateListLength; k += 1)
    {
        var i;
        i = blockUpdateList[k];
        
        if (tempBlocks[i] != blockGraph_blockArithmetic(i))
        {
            blockGraph_addToTempBlockUpdateList(i);
            blockGraph_addToTempBlockUpdateList(blockGraph[i,Block3D_adj1]);
            blockGraph_addToTempBlockUpdateList(blockGraph[i,Block3D_adj2]);
            blockGraph_addToTempBlockUpdateList(blockGraph[i,Block3D_adj3]);
            blockGraph_addToTempBlockUpdateList(blockGraph[i,Block3D_adj4]);
            changed[floor(i/blockModelCapacity)] = 1;
        }
        
        tempBlocks[i] = blockGraph_blockArithmetic(i);
    }
    
    for (k = 0; k < blockUpdateListLength; k += 1)
    {
        var i;
        i = blockUpdateList[k];
        blockGraph[i,Block3D_type] = tempBlocks[i];
    }
    
    blockUpdateListLength = 0;
    
    for (k = 0; k < blockUpdateListTempLength; k += 1)
    {
        blockUpdateList[k] = blockUpdateListTemp[k];
        
    }
    
    blockUpdateListLength = blockUpdateListTempLength;
    blockUpdateListTempLength = 0;
    for (i = 0; i  < ceil(numberOfBlockModels/blockModelCapacity); i+=1)
    {
        if (changed[i] == 1)
        {
            d3d_model_destroy(surfaceModel[i]);
            surfaceModel[i] = blockGraph_createSubmodel(i);
        }
    }
}
