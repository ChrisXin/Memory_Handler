# Memory_Handler
Variable Memory Allocation strategy in Unix/Linux system


As a performance optimization, we could have two linked lists: one for allocated memory and one for unallocated
memory. That way to find a free block we do not have to look through the allocated blocks.


Best fit. 
Considering all blocks, we choose the smallest block that is at least as big as N. 
This produces the smallest remaining unallocated space at the end. 
This would require either 
    (1) checking every available block (order(n) runtime); 
    (2) keeping the blocks sorted by increasing size (O(n) runtime). 
    
If we use an AVL tree or red-black tree, then we can get best fit to run in (ln(n)), possibly better runtime than first fit .

Worst fit. 
Choose the largest block of free memory.
When the block is split, the remaining free block is, hopefully, large enough to be useful.
Similarly wemust either 
    (1) check each available block;
    (2) keep the block sorted by size, though decreasing size this time. 
A max heap is appropriate, or a binomial or Fibonacci heap could also be appropriate.
