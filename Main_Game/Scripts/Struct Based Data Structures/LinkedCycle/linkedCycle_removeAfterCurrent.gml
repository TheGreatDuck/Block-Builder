if (linkedCycle_getLength(argument[0]) > 1)
{
    argument[1] = node_getNext(linkedCycle_getCurrentNode(argument[0]));
    
    node_setPrevious(node_getNext(argument[1]),node_getPrevious(argument[1]));
    node_setNext(node_getPrevious(argument[1]),node_getNext(argument[1]));
    
    node_deleteNode(argument[1]);
} else if (linkedCycle_getLength(argument[0]) == 1)
{
    node_deleteNode(linkedCycle_getCurrentNode(argument[0]));
    linkedCycle_setCurrentNode(argument[0]);
}

linkedCycle_setLength(argument[0],linkedCycle_getLength(argument[0])-1);
