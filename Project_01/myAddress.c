/*
Erfan Azad
Date: 12 Sep 2014
Description: This program assigns the address of 
a variable to itself and uses a for loop to go through memory, until segfault!
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int alpha;
	int beta;
	unsigned char* ptr;

	alpha = 333;
	beta = 444;
	ptr = &ptr;

	int i;
	for(i=0; i> -1; i++){
		printf("%d => address / value: %d / %d\n", i,&ptr+i, *(&ptr+i));
	}

	return(0);
}