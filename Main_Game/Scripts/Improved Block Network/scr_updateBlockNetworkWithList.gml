with (obj_blockNetwork)
{
    //var tempBlocks;
    for (k = 0; k < blockUpdateListLength; k += 1)
    {
        i = blockUpdateList[0,k];
        j = blockUpdateList[1,k];
        
        if (i == 0 && j == 0)
        {
            if (tempBlocks[0,0] != scr_changeBlock(blocks[0,0],blocks[1,0],blocks[0,1]))
            {
                tempBlocks[0,0] = scr_changeBlock(blocks[0,0],blocks[1,0],blocks[0,1]);
                scr_addToTempBlockUpdateList(0,0);
                scr_addToTempBlockUpdateList(1,0);
                scr_addToTempBlockUpdateList(0,1);
            } else
            {
                tempBlocks[0,0] = scr_changeBlock(blocks[0,0],blocks[1,0],blocks[0,1]);
            }
        }
        
        if (i == 0 && j > 0)
        {
            if (tempBlocks[0,j] != scr_changeBlock(blocks[0,j],blocks[0,j-1],blocks[1,j],blocks[0,j+1]))
            {
                tempBlocks[0,j] = scr_changeBlock(blocks[0,j],blocks[0,j-1],blocks[1,j],blocks[0,j+1]);
                scr_addToTempBlockUpdateList(0,j);
                scr_addToTempBlockUpdateList(0,j-1);
                scr_addToTempBlockUpdateList(1,j);
                scr_addToTempBlockUpdateList(0,j+1);
            } else
            {
                tempBlocks[0,j] = scr_changeBlock(blocks[0,j],blocks[0,j-1],blocks[1,j],blocks[0,j+1]);
            }
        }
        
        if (i > 0 && j == 0)
        {
            if (tempBlocks[i,0] != scr_changeBlock(blocks[i,0],blocks[i-1,0],blocks[i+1,0],blocks[i,1]))
            {
                tempBlocks[i,0] = scr_changeBlock(blocks[i,0],blocks[i-1,0],blocks[i+1,0],blocks[i,1]);
                scr_addToTempBlockUpdateList(i,0);
                scr_addToTempBlockUpdateList(i-1,0);
                scr_addToTempBlockUpdateList(i+1,0);
                scr_addToTempBlockUpdateList(i,1);
            } else
            {
                tempBlocks[i,0] = scr_changeBlock(blocks[i,0],blocks[i-1,0],blocks[i+1,0],blocks[i,1]);
            }
        }
        
        if (i > 0 && j > 0)
        {
            if (tempBlocks[i,j] != scr_changeBlock(blocks[i,j],blocks[i,j-1],blocks[i-1,j],blocks[i+1,j],blocks[i,j+1]))
            {
                tempBlocks[i,j] = scr_changeBlock(blocks[i,j],blocks[i,j-1],blocks[i-1,j],blocks[i+1,j],blocks[i,j+1]);
                scr_addToTempBlockUpdateList(i,j);
                scr_addToTempBlockUpdateList(i,j-1);
                scr_addToTempBlockUpdateList(i-1,j);
                scr_addToTempBlockUpdateList(i+1,j);
                scr_addToTempBlockUpdateList(i,j+1);
            } else
            {
                tempBlocks[i,j] = scr_changeBlock(blocks[i,j],blocks[i,j-1],blocks[i-1,j],blocks[i+1,j],blocks[i,j+1]);
            }
        }
    }
    
    for (k = 0; k < blockUpdateListLength; k += 1)
    {
        blocks[blockUpdateList[0,k],blockUpdateList[1,k]] = tempBlocks[blockUpdateList[0,k],blockUpdateList[1,k]];
    }
    
    //for (i = 0; i < hblocks; i += 1)
    //{
    //    for (j = 0; j < vblocks; j += 1)
    //    {
    //        blocks[i,j] = tempBlocks[i,j];
    //    }
    //}
    
    blockUpdateListLength = 0;
    
    for (k = 0; k < blockUpdateListTempLength; k += 1)
    {
        blockUpdateList[0,k] = blockUpdateListTemp[0,k];
        blockUpdateList[1,k] = blockUpdateListTemp[1,k];
        
    }
    
    blockUpdateListLength = blockUpdateListTempLength;
    blockUpdateListTempLength = 0;
}
