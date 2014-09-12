/*
Erfan Azad
Date: 12 Sep 2014
Description: This program creates a struct tht has an odd
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int a;
	short b;
	char c;
}myStruct;

 int main(int argc, char *argv[]) {
 	myStruct* S = malloc(sizeof(myStruct));
 	memset(S, 0, sizeof(myStruct));
 	S->a = 444;
 	S->b = 555;
 	S->c = '1';

 	printf("sizeof structure is: %lu bytes.\n\n",sizeof(myStruct));

 	int i;
 	for (i=0; i< sizeof(myStruct); i++){
 	printf("%d: %d / %u\n",i, &S+i, *(&S+i));
	}

	return(0);
}
