/* includes */
#include <stdio.h> 
#include <stdlib.h> 
#include "mem.h"

/* defines */

/* global varaiables */

// node indicates a memory block 
struct node {
	void* start;
	size_t size;
};


void *data;

/* Functions */

/* memory initializer */
int best_fit_memory_init(size_t size)
{
	free_list = linked_list_create();
	allocated_list = linked_list_create();

	start_memory = malloc(size);

	if(start_memory == NULL) {
		return -1;
	} else {
		struct node* node = malloc(sizeof(struct node));
		node->start = start_memory;
		node->size = size;
		linked_list_add_front(free_list, node);
	}

	return 0;

}

int worst_fit_memory_init(size_t size)
{
	free_list = linked_list_create();
	allocated_list = linked_list_create();

	start_memory = malloc(size);

	if(start_memory == NULL) {
		return -1;
	} else {
		struct node* node = malloc(sizeof(struct node));
		node->start = start_memory;
		node->size = size;
		linked_list_add_front(free_list, node);
	}

	// To be completed by students
	// You call malloc once here to obtain the memory to be managed.
	return 0;

}

/* memory allocators */
void *best_fit_alloc(size_t size)
{
	node = linked_list_iter_begin(free_list);
	struct node* smallest = NULL;

	// if the list is empty, don't enter
	if(node != NULL) {
		
		// find the smallest node which is large enough to hold "size" 
		for(int i = 0; i < free_list->counter; i++) {
			if(node->size >= size) {
				if(smallest == NULL || node->size < smallest->size)
					smallest = node;
					smallest->size = node->size;
			}
			node = linked_list_iter_next(free_list);
		}
		
		// perfect match 
		data = smallest->start;
		if(size == smallest->size) {
			linked_list_find_remove(free_list, smallest);
			linked_list_add_back(allocated_list, smallest);
			return data;
		} 
		
		// otherwise
		else if(size < smallest->size) {
			
			// replace it with Pointer Arithmetic  (malloc not allowed here)
			struct node* new = malloc(sizeof(struct node));
			new->start = smallest->start;
			new->size = smallest->size;
			
			
			smallest->size -= size;
			smallest->start += size;
			linked_list_add_back(allocated_list, new);
			return data;
		}
	}
	return NULL;
}


void *worst_fit_alloc(size_t size)
{
	node = dlist_iter_begin(free_list);
	struct node* largest = NULL;

	// if the list is empty, don't enter
	if(node != NULL) {
		for(int i = 0; i < free_list->counter; i++) {
			if(node->size >= size) {
				if(largest == NULL || node->size > largest->size)
					largest = node;
					largest->size = node->size;
			}
			node = dlist_iter_next(free_list);
		}
		data = largest->start;
		if(size == largest->size) {
			dlist_find_remove(free_list, largest);
			dlist_add_back(allocated_list, largest);
			return data;
		} else if(size < largest->size) {
			struct node* new = malloc(sizeof(struct node));
			new->start = largest->start;
			new->size = largest->size;
			largest->size -= size;
			largest->start += size;
			dlist_add_back(allocated_list, new);
			return data;
		}
	}
	return NULL;
}

/* memory de-allocator */
void best_fit_dealloc(void *ptr) 
{
	node = dlist_iter_begin(allocated_list);
	if(node != NULL) {
		for(int i = 0; i < allocated_list->counter; i++) {
			if(ptr == node->start) {
				dlist_find_remove(allocated_list, node);
				dlist_add_back(free_list, node);
				return 0;
			}
			node = dlist_iter_next(allocated_list);
		}
	}
	// To be completed by students
	return;
}

void worst_fit_dealloc(void *ptr) 
{

	// To be completed by students
	return;
}

/* memory algorithm metric utility function(s) */

/* count how many free nodes are less than the input size */ 
int best_fit_count_extfrag(size_t size)
{
	// To be completed by students
	return 0;
}

int worst_fit_count_extfrag(size_t size)
{
	// To be completed by students
	return 0;
}
