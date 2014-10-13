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
	ll->tail = ll->head;
	ll->current = ll_head;
	ll->size = 0;

	return(ll);
}


// adds a node to the front of the list, storing the given data in the node
void ll_push(LinkedList *l, void *data ){
	Node *n = malloc(sizeof(Node));
	n->next = ll_head;
	n->data = data;

	l->head = n;
	l->size++;
}


//Removes the top element from the list and returns it.
void *ll_pop( LinkedList *ll ) {
	Node *n;
	void *node_data;
	
	if( ll->root == NULL )
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

	l->tail->next = n;
	l->size++;
}


//removes the first node in the list whose data matches target given the comparison function. 
//The function returns the pointer to the data.
void *ll_remove( LinkedList *l, void *target, int (*compfunc)(void *, void *) ){
	Node* p;
	Node* q;
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
			free(n);

			l->size--;
		}
	}
}


//returns the size of the list
int ll_size(LinkedList *l){
	return l->size;
}


// removes all of the nodes from the list, freeing the associated data using the given function.
void ll_clear( LinkedList *ll, void (*freefunc)(const void *) ) {
	Node *p, *q;

	p = ll->root;
	while( p != NULL ) {
		q = p->next;
		if(freefunc && p->data)
			freefunc( p->data );
		free(p);
		p = q;
	}
	free( ll );
	return;
}

//traverses the list and applies the given function to the data at each node.
void ll_map( LinkedList *l, void (*mapfunc)(void *) ){
	Node* p;
	p = l->head;
	while(P){
		if(mapfunc && p->data){
			mapfunc(p->data);
		}
		p = p->next;
	}
}



/* 
	 Inserts the item into the list using the specified comparison
	 function.
*/
void ll_insert( LinkedList *ll, void *item, int (*comp)(const void *, const void *) ) {
	Node *p, *q, *n;

	// see if the list is empty or the item replaces the starting element
	if( ll->root == NULL || comp(item, ll->root->data) <= 0 ) {
		n = malloc(sizeof(Node));
		n->next = ll->root;
		n->data = item;
		ll->root = n;
		return;
	}

	// deal with the rest of the list, it doesn't go in front
	q = ll->root;
	p = q->next;
	while( p ) {
		// see if it comes between p and q
		if( comp(item, p->data) <= 0 ) {
			n = malloc(sizeof(Node));
			n->data = item;
			n->next = p;
			q->next = n;
			return;
		}
		q = p;
		p = q->next;
	}
	
	// goes at the end
	n = malloc(sizeof(Node));
	n->data = item;
	n->next = NULL;
	q->next = n;

	return;
}

/*
	Returns true if the list is empty
*/
int ll_empty( LinkedList *ll ) {
	if( ll->root == NULL )
		return(1);
	return(0);
}

/* 
	 Return a pointer to the top item in the list
*/
void *ll_peek( LinkedList *ll ) {
	if( ll->root == NULL )
		return(NULL);

	return(ll->root->data);
}

/*
	Sets the current iterator to the head of the list and returns the
	data from the first node.
 */
void *ll_head( LinkedList *ll ) {
	ll->current = ll->root;
	if( ll->current != NULL )
		return( ll->current->data );

	return(NULL);
}

/*
	Returns the data from the next element in the list as specified by
	the iterator.  Returns NULL if the end of the list has been reached.
 */
void *ll_next( LinkedList *ll ) {
	if( ll->current != NULL )
		ll->current = ll->current->next;

	if( ll->current != NULL )
		return( ll->current->data );

	return(NULL);
}





