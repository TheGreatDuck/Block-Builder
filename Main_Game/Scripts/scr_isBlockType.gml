//isBlockType(x,y,type)

with (obj_blockNetwork)
{
    if (argument[0] >= 0 && argument[0] < hblocks && argument[1] >= 0 && argument[1] < vblocks)
    {
        if (blocks[argument[0],argument[1]] == argument[2])
        {
            return true;
        } else
        {
            return false;
        }
    } else
    {
        return false;
    }
}
