argument[2] = node_createNode();
node_setData(argument[2],argument[1]);
node_setDataDestructor(argument[2],linkedCycle_getDataDestructor(argument[0]));

if (linkedCycle_getLength(argument[0]) == 0)
{
    node_setNext(argument[2],argument[2]);
    node_setPrevious(argument[2],argument[2]);
    linkedCycle_setCurrentNode(argument[0],argument[2]);
} else
{
    argument[3] = linkedCycle_getCurrentNode(argument[0]);
    argument[4] = node_getNext(argument[3]);
    node_setNext(argument[3], argument[2]);
    node_setPrevious(argument[4],argument[2]);
    node_setPrevious(argument[2], argument[3]);
    node_setNext(argument[2],argument[4]);
}

linkedCycle_setLength(argument[0],linkedCycle_getLength(argument[0])+1);
