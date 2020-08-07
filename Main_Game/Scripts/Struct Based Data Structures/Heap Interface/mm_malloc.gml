var newsize;
var freeP;
var p;

newsize = argument[0] + (argument[0] mod 2);
freeP = HEAD_NODE;

if (mm_getLength(freeP) - newsize > 0 && !mm_getFree(freeP))
{
    mm_setFree(freeP,true);
    mm_insert(freeP, newsize);
    return freeP + 1;
}
while (mm_getNext(freeP) < TAIL_NODE)
{
    freeP=mm_getNext(freeP);
    if (mm_getLength(freeP) - newsize > 0 && !mm_getFree(freeP))
    {
        mm_setFree(freeP,true);
        mm_insert(freeP, newsize);
        return freeP + 1;
    }
}

p = TAIL_NODE; /*add to the heap and return the starting position*/
//p = mem_sbrk(newsize + 8); /*add to the heap and return the starting position*/
if (p == -1)
{
    return NULL;
} else
{
    HEAP_SPACE[p] = (newsize) + (1 << 31);
    HEAP_SPACE[mm_getNext(p) - 1] = newsize;
    if (LINKED_LIST_LENGTH == 0)
    {
        HEAD_NODE = p;
    }
    TAIL_NODE = mm_getNext(p);
    LINKED_LIST_LENGTH += 1;
    return (p + 1);
}
