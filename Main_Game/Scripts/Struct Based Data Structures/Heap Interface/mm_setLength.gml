HEAP_SPACE[argument[0]] = argument[1] + (mm_getFree(argument[0]) << 31);
HEAP_SPACE[mm_getNext(argument[0]) - 1] = argument[1];
