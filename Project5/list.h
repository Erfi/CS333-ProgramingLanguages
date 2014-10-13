/*
Erfan Azad
Date: 12 Oct 2014
File: list.h

Implementation of the Linked List methods declared in list.h

The comparison function must return value < 0 if A < B, 0 if A = B
and value > 0 if A > B
*/

#ifndef __LIST_H__
#define __LIST_H__

// Node data structure
typedef struct {
	void *data;
	void *next;
} Node;

// List data structure
typedef struct {
	Node *head;
	Node *tail;
	int size;
} LinkedList;

// allocate and return a new linked list
LinkedList *ll_create( void );

// adds a node to the front of the list, storing the given data in the node
void ll_push(LinkedList *l, void *data );

// remove the first item from the list
void *ll_pop( LinkedList *ll );

//adds a node to the end of the list, storing the given data in the node.
void ll_append(LinkedList *l, void *data );

//removes the first node in the list whose data matches target given the comparison function. 
//The function returns the pointer to the data.
void *ll_remove( LinkedList *l, void *target, int (*compfunc)(void *, void *) );

//returns the size of the list
int ll_size(LinkedList *l);

// removes all of the nodes from the list, freeing the associated data using the given function.
void ll_clear( LinkedList *ll, void (*freefunc)(const void *) );

//traverses the list and applies the given function to the data at each node.
void ll_map( LinkedList *l, void (*mapfunc)(void *) );

#endif