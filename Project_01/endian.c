/*
Erfan Azad
Date: 12 Sep 2014
Description: This is a program to figure out if the computer is big endian
	or small endian.
*/

#include <stdio.h>
#include <stdlib.h>

void print_mem(unsigned char* start, int n){
	int i;
	for (i=0; i<n; i++){
		printf("%.2x ",start[i]);
	}
	printf("\n");
}


int main(int argc, char *argv[]){
	int i = 1;
	long l = 1;
	short s = 1;
	double d = 1;
	char c = 1;

	printf("%s","Long: " );
	print_mem((unsigned char*)&l, sizeof(l));

	printf("%s","Double: " );
	print_mem((unsigned char*)&d, sizeof(d));

	printf("%s","Integer: " );
	print_mem((unsigned char*)&i, sizeof(i));

	printf("%s","Short: " );
	print_mem((unsigned char*)&s, sizeof(s));

	printf("%s","Char: " );
	print_mem((unsigned char*)&c, sizeof(c));

	
	
	unsigned char* ptr = (unsigned char*)&(i);
	if (((int)ptr[0] != 0) && (i != 0)){
		printf("%s\n","It is little endian!" );
	}else{
		printf("%s\n","It is big endian!" );
	}


	return(0);
}
