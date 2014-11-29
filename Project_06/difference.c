/*
Erfan Azad
Date: Nov 1 2014
File: file_write.c
Discription: The third program should read two arbitrary length files of numbers,
compare the values of numbers of corresponding lines, 
and print out the difference, flagging any difference that is not zero.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
	if(argc < 3){
		printf("Not enough arguments: <program> <input1> <input2>\n");
		exit(-1);
	}else{
		FILE* fp1 = fopen(argv[1], "r");
		FILE* fp2 = fopen(argv[2], "r");
		char buffer1[30];
		char buffer2[30];
		int i =0;

		while((NULL != fgets(buffer1, sizeof(buffer1), fp1))&&(NULL != fgets(buffer2, sizeof(buffer2), fp2))){
			float a,b;
			a = atof(buffer1);
			b = atof(buffer2);
			if(a != b){
				printf("Difference in line %d: %f, %f\n",i, a, b);
			}
			i++;
		}
		fclose(fp1);
		fclose(fp2);
	}	
	return 0;
}

