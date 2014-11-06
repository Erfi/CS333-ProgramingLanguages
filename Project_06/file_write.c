/*
Erfan Azad
Date: Nov 1 2014
File: file_write.c
Discription: The first program should generate an array of 20 random floating point numbers between 0 and 1.
The program should then write them out to a user-defined file, or to the terminal if no filename is given,
putting one number on each line, with five decimal places on each number.
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>



int main(int argc, char* argv[]){
	float array[20];
	int i;

	for(i=0; i<20; i++){
		array[i] = drand48();
		// printf("%d\n", argc);
	}

	if(argc == 1){//No output file specified
		for(i=0; i<20; i++){
			printf("%.5f\n", array[i]);
		}
	}else{//output file specified 
		FILE *fp;
		fp = fopen(argv[1] , "w");
		if (fp!=NULL){
			for(i=0; i<20; i++){
				fprintf(fp, "%.5f\n",array[i]);
			}
		}
		fclose(fp);
	}

	return 0;
}