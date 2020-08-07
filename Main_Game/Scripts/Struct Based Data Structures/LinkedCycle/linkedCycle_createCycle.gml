//current node
//data destructor
//length

argument[1] = mm_malloc(3);
HEAP_SPACE[argument[1]] = -1;
HEAP_SPACE[argument[1]+1] = argument[0];
HEAP_SPACE[argument[1]+2] = 0;
return argument[1];
