argument[0] = mm_malloc(4);
node_setData(argument[0],-1);
node_setNext(argument[0],-1);
node_setPrevious(argument[0],-1);
node_setDataDestructor(argument[0],node_byteDataDestructor);
return argument[0];
