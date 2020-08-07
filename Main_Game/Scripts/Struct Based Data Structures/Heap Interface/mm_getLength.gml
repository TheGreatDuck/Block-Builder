/*zero out the leftmost bit, reserved for the free value*/
return HEAP_SPACE[argument[0]] & (~(1 << 31));
