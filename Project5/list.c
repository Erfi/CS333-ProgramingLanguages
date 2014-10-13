/*
Erfan Azad
Date: 12 Oct 2014
File: list.c

Implementation of the Linked List methods declared in list.h

The comparison function must return value < 0 if A < B, 0 if A = B
and value > 0 if A > B
*/
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//Creates a new linked list and returns a pointer to it.
LinkedList *ll_create( void ) {
	LinkedList *ll;

	ll = malloc(sizeof(LinkedList));
	if( !ll ) {
		printf("ERROR: ll_create >> malloc failed!\n");
		return(NULL);
	}

	ll->head = NULL;
	ll->tail = NULL;
	ll->size = 0;

	return(ll);
}


// adds a node to the front of the list, storing the given data in the node
void ll_push(LinkedList *l, void *data ){
	Node *n = malloc(sizeof(Node));
	n->next = l->head;
	n->data = data;
	if(l->head == NULL){// if pushing the first node to the list
		l->tail = n;
	}
	l->head = n;
	l->size++;
}


//Removes the top element from the list and returns it.
void *ll_pop( LinkedList *ll ) {
	Node *n;
	void *node_data;
	
	if( ll->head == NULL )
		return(NULL);

	n = ll->head;
	ll->head = ll->head->next;
	ll->size--;

	node_data = n->data;
	free(n);

	return( node_data );
}

//adds a node to the end of the list, storing the given data in the node.
void ll_append(LinkedList *l, void *data ){
	Node* n = malloc(sizeof(Node));
	n->next = NULL;
	n->data = data;
	if(l->head == NULL){ // appending the first node
		l->head = n;
		l->tail = n;
		l->size++;
	}else{
		l->tail->next = n;
		l->tail = n;
		l->size++;
	}
}


//removes the first node in the list whose data matches target given the comparison function. 
//The function returns the pointer to the data.
void *ll_remove( LinkedList *l, void *target, int (*compfunc)(void *, void *) ){
	Node* p;
	Node* q;
	void* node_data;
	if(l->head == NULL){//if the list is empty
		printf("Warning: ll_remove >> Cannot remove, list is empty.");
		return NULL;
	}
	q = l->head;
	p = q->next;
	while(p){
		if(compfunc(target, p->data) == 0){
			Node* n;
			n = p;
			if(p->next == NULL){ // if p is the tail node
				l->tail = q;
			}
			q->next = p->next;
			node_data = n->data;
			free(n);

			l->size--;

			return node_data;
		}
	}
	return NULL;
}


//returns the size of the list
int ll_size(LinkedList *l){
	return l->size;
}


// removes all of the nodes from the list, freeing the associated data using the given function.
void ll_clear( LinkedList *ll, void (*freefunc)(const void *) ) {
	Node *p, *q;

	p = ll->head;
	while( p != NULL ) {
		q = p->next;
		if(freefunc && p->data)
			freefunc( p->data );
		free(p);
		p = q;
	}
	ll->head = NULL;
	ll->tail = NULL;
	ll->size = 0;
}

//traverses the list and applies the given function to the data at each node.
void ll_map( LinkedList *l, void (*mapfunc)(void *) ){
	Node* p;
	p = l->head;
	while(p){
		if(mapfunc && p->data){
			mapfunc(p->data);
		}
		p = p->next;
	}
}


