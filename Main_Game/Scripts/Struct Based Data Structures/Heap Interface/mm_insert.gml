/* the node has to fit to avoid distorting
 * the linked list's heap property
 */
if (argument[1] + 2 < mm_getLength(argument[0]))
{
    node = argument[0] + argument[1] + 2;
    /*ensure the free field is 0*/
    HEAP_SPACE[node] = 0;
    mm_setLength(node,mm_getLength(argument[0])-argument[1]-2);
    mm_setLength(argument[0],argument[1]);
} else
{
    /* all blocks and nodes are 2 byte aligned, so a difference of one
     * would only exist in the case of a system flaw
     */
    HEAP_SPACE[argument[0]] = mm_getLength(argument[0]) + (1 << 31);
}
