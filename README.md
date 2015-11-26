# Memory_Handler
Variable Memory Allocation strategy in Unix/Linux system


As a performance optimization, we could have two linked lists: one for allocated memory and one for unallocated
memory. That way to find a free block we do not have to look through the allocated blocks.
