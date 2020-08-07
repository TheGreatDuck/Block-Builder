with (obj_blockNetwork)
{
    blockUpdateListLength = 0;
    if (tempBlocks[0,0] != scr_changeBlock(blocks[0,0],blocks[1,0],blocks[0,1]))
    {
        tempBlocks[0,0] = scr_changeBlock(blocks[0,0],blocks[1,0],blocks[0,1]);
        scr_addToBlockUpdateList(0,0);
        scr_addToBlockUpdateList(1,0);
        scr_addToBlockUpdateList(0,1);
    } else
    {
        tempBlocks[0,0] = scr_changeBlock(blocks[0,0],blocks[1,0],blocks[0,1]);
    }
    for (j = 1; j < vblocks-1; j += 1)
    {
        if (tempBlocks[0,j] != scr_changeBlock(blocks[0,j],blocks[0,j-1],blocks[1,j],blocks[0,j+1]))
        {
            tempBlocks[0,j] = scr_changeBlock(blocks[0,j],blocks[0,j-1],blocks[1,j],blocks[0,j+1]);
            scr_addToBlockUpdateList(0,j);
            scr_addToBlockUpdateList(0,j-1);
            scr_addToBlockUpdateList(1,j);
            scr_addToBlockUpdateList(0,j+1);
        } else
        {
            tempBlocks[0,j] = scr_changeBlock(blocks[0,j],blocks[0,j-1],blocks[1,j],blocks[0,j+1]);
        }
    }
    
    if (tempBlocks[0,vblocks-1] != scr_changeBlock(blocks[0,vblocks-1],blocks[0,vblocks-2],blocks[1,vblocks-1]))
    {
        tempBlocks[0,vblocks-1] = scr_changeBlock(blocks[0,vblocks-1],blocks[0,vblocks-2],blocks[1,vblocks-1]);
        scr_addToBlockUpdateList(0,vblocks-1);
        scr_addToBlockUpdateList(0,vblocks-2);
        scr_addToBlockUpdateList(1,vblocks-1);
    } else
    {
        tempBlocks[0,vblocks-1] = scr_changeBlock(blocks[0,vblocks-1],blocks[0,vblocks-2],blocks[1,vblocks-1]);
    }
    
    for (i = 1; i < hblocks-1; i += 1)
    {
        if (tempBlocks[i,0] != scr_changeBlock(blocks[i,0],blocks[i-1,0],blocks[i+1,0],blocks[i,1]))
        {
            tempBlocks[i,0] = scr_changeBlock(blocks[i,0],blocks[i-1,0],blocks[i+1,0],blocks[i,1]);
            scr_addToBlockUpdateList(i,0);
            scr_addToBlockUpdateList(i-1,0);
            scr_addToBlockUpdateList(i+1,0);
            scr_addToBlockUpdateList(i,1);
        } else
        {
            tempBlocks[i,0] = scr_changeBlock(blocks[i,0],blocks[i-1,0],blocks[i+1,0],blocks[i,1]);
        }
        
        for (j = 1; j < vblocks-1; j += 1)
        {
            if (tempBlocks[i,j] != scr_changeBlock(blocks[i,j],blocks[i,j-1],blocks[i-1,j],blocks[i+1,j],blocks[i,j+1]))
            {
                tempBlocks[i,j] = scr_changeBlock(blocks[i,j],blocks[i,j-1],blocks[i-1,j],blocks[i+1,j],blocks[i,j+1]);
                scr_addToBlockUpdateList(i,j);
                scr_addToBlockUpdateList(i,j-1);
                scr_addToBlockUpdateList(i-1,j);
                scr_addToBlockUpdateList(i+1,j);
                scr_addToBlockUpdateList(i,j+1);
            } else
            {
                tempBlocks[i,j] = scr_changeBlock(blocks[i,j],blocks[i,j-1],blocks[i-1,j],blocks[i+1,j],blocks[i,j+1]);
            }
        }
        
        if (tempBlocks[i,vblocks-1] != scr_changeBlock(blocks[i,vblocks-1],blocks[i,vblocks-2],blocks[i-1,vblocks-1],blocks[i+1,vblocks-1]))
        {
            tempBlocks[i,vblocks-1] = scr_changeBlock(blocks[i,vblocks-1],blocks[i,vblocks-2],blocks[i-1,vblocks-1],blocks[i+1,vblocks-1]);
            scr_addToBlockUpdateList(i,vblocks-1);
            scr_addToBlockUpdateList(i,vblocks-2);
            scr_addToBlockUpdateList(i-1,vblocks-1);
            scr_addToBlockUpdateList(i+1,vblocks-1);
        } else
        {
            tempBlocks[i,vblocks-1] = scr_changeBlock(blocks[i,vblocks-1],blocks[i,vblocks-2],blocks[i-1,vblocks-1],blocks[i+1,vblocks-1]);
        }
    }
    
    if (tempBlocks[hblocks-1,0] != scr_changeBlock(blocks[hblocks-1,0],blocks[hblocks-2,0],blocks[hblocks-1,1]))
    {
        tempBlocks[hblocks-1,0] = scr_changeBlock(blocks[hblocks-1,0],blocks[hblocks-2,0],blocks[hblocks-1,1]);
        scr_addToBlockUpdateList(hblocks-1,0);
        scr_addToBlockUpdateList(hblocks-2,0);
        scr_addToBlockUpdateList(hblocks-1,1);
    } else
    {
        tempBlocks[hblocks-1,0] = scr_changeBlock(blocks[hblocks-1,0],blocks[hblocks-2,0],blocks[hblocks-1,1]);
    }
    
    for (j = 1; j < vblocks-1; j += 1)
    {
        if (tempBlocks[hblocks-1,j] != scr_changeBlock(blocks[hblocks-1,j],blocks[hblocks-1,j-1],blocks[hblocks-2,j],blocks[hblocks-1,j+1]))
        {
            tempBlocks[hblocks-1,j] = scr_changeBlock(blocks[hblocks-1,j],blocks[hblocks-1,j-1],blocks[hblocks-2,j],blocks[hblocks-1,j+1]);
            scr_addToBlockUpdateList(hblocks-1,j);
            scr_addToBlockUpdateList(hblocks-1,j-1);
            scr_addToBlockUpdateList(hblocks-2,j);
            scr_addToBlockUpdateList(hblocks-1,j+1);
        } else
        {
            tempBlocks[hblocks-1,j] = scr_changeBlock(blocks[hblocks-1,j],blocks[hblocks-1,j-1],blocks[hblocks-2,j],blocks[hblocks-1,j+1]);
        }
    }
    
    if (tempBlocks[hblocks-1,vblocks-1] != scr_changeBlock(blocks[hblocks-1,vblocks-1],blocks[hblocks-1,vblocks-2],blocks[hblocks-2,vblocks-1]))
    {
        tempBlocks[hblocks-1,vblocks-1] = scr_changeBlock(blocks[hblocks-1,vblocks-1],blocks[hblocks-1,vblocks-2],blocks[hblocks-2,vblocks-1]);
        scr_addToBlockUpdateList(hblocks-1,vblocks-1);
        scr_addToBlockUpdateList(hblocks-1,vblocks-2);
        scr_addToBlockUpdateList(hblocks-2,vblocks-1);
    } else
    {
        tempBlocks[hblocks-1,vblocks-1] = scr_changeBlock(blocks[hblocks-1,vblocks-1],blocks[hblocks-1,vblocks-2],blocks[hblocks-2,vblocks-1]);
    }
    
    
    for (i = 0; i < hblocks; i += 1)
    {
        for (j = 0; j < vblocks; j += 1)
        {
            blocks[i,j] = tempBlocks[i,j];
        }
    }
}
