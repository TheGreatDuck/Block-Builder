/* adjust so that ptr points
 * to the node for this block
 */
var p;
p = argument[0] - 1;
HEAP_SPACE[p] = mm_getLength(p);

/*did the pointer originate from the heap*/
if (p > HEAD_NODE && p < TAIL_NODE)
{
    if (!mm_getFree(mm_getPrevious(p)))
    {
        /* the previous node
         * can be coalesced
         */
        mm_removeNode(p);
        p = mm_getPrevious(p);
    }
    
    if (!mm_getFree(mm_getNext(p)) && mm_getNext(p) <= TAIL_NODE)
    {
        /* the next node
         * can be coalesced
         */
        if (mm_getNext(p) == TAIL_NODE)
        {
            TAIL_NODE = p;
        }
        mm_removeNode(mm_getNext(p));
    }
}
