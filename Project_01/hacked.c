/*
Erfan Azad
Date: 12 Sep 2014
Description: This program tries to overwrite an int which is afrer the an array by strcpy.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void isHacked(){
	char str[100];
	printf("Enter a string within 100 characters: "); 
	scanf("%s",str);

	char array[10];

	int a = 0;
	strcpy(array, str);
	int b = 0;

	if (a == 0 && b==0){
		printf("Safe\n");
	}else{
		printf("Hacked\n");
	}
}
int main(int argc, char *argv[]) {
	isHacked();
	return(0);
}
