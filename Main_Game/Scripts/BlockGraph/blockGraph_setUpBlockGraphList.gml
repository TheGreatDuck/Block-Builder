with (obj_blockGraph)
{
    blockUpdateListLength = 0;
    var i;
    
    for (i = 0; i < numberOfBlockModels; i+=1)
    {
        if (blockGraph[i,Block3D_type] != blockGraph_blockArithmetic(i))
        {
            blockGraph_addToBlockUpdateList(i);
            blockGraph_addToBlockUpdateList(blockGraph[i,Block3D_adj1]);
            blockGraph_addToBlockUpdateList(blockGraph[i,Block3D_adj2]);
            blockGraph_addToBlockUpdateList(blockGraph[i,Block3D_adj3]);
            blockGraph_addToBlockUpdateList(blockGraph[i,Block3D_adj4]);
        }
        
        tempBlocks[i] = blockGraph_blockArithmetic(i);
    }
    
    for (i = 0; i < numberOfBlockModels; i += 1)
    {
        blockGraph[i,Block3D_type] = tempBlocks[i];
    }
}
