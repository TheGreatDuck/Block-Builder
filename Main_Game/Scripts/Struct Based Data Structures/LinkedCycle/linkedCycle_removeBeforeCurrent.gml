argument[1] = node_getPrevious(linkedCycle_getCurrentNode(argument[0]));

node_setPrevious(node_getNext(argument[1]),node_getPrevious(argument[1]));
node_setNext(node_getPrevious(argument[1]),node_getNext(argument[1]));

node_deleteNode(argument[1]);

linkedCycle_setLength(argument[0],linkedCycle_getLength(argument[0])-1);
