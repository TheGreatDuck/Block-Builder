//walkableBlockExists(x,y,h_unit,v_unit)

with (obj_blockNetwork)
{
    if (other.argument[0]+other.argument[2] >= 0 && other.argument[0]+other.argument[2] < hblocks && other.argument[1]+other.argument[3] >= 0 && other.argument[1]+other.argument[3] < vblocks)
    {
        if (blocks[other.argument[0]+other.argument[2],other.argument[1]+other.argument[3]] mod 1000000 == 4)
        {
            return true;
        } else if (blocks[other.argument[0]+other.argument[2],other.argument[1]+other.argument[3]] mod 1000000 == 5)
        {
            return true;
        } else if (blocks[other.argument[0]+other.argument[2],other.argument[1]+other.argument[3]] mod 1000000 == 6)
        {
            return true;
        } else if (blocks[other.argument[0]+argument[2],argument[1]+argument[3]] mod 1000000 == 8)
        {
            return true;
        } else if (blocks[argument[0]+argument[2],argument[1]+argument[3]] mod 1000000 == 9)
        {
            return true;
        } else if (blocks[argument[0]+argument[2],argument[1]+argument[3]] mod 1000000 == 10)
        {
            return true;
        } else if (blocks[argument[0]+argument[2],argument[1]+argument[3]] mod 1000000 == 23)
        {
            return true;
        } else if (blocks[argument[0]+argument[2],argument[1]+argument[3]] mod 1000000 == 32)
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
