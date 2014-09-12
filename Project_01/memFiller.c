/*
Erfan Azad
Date: 12 Sep 2014
Description: This program uses a for loop and malloc to fill memory
 and then uses free command to free the assigned memory.
*/

#include <stdio.h>
#include <stdlib.h>

 int main(int argc, char *argv[]) {
 	int* ptr;
 	for (;;){
 		ptr = malloc(sizeof(int));
 		free(ptr);
 	}

	return(0);
}
