/*
Erfan Azad
Date: Nov 1 2014
File: file_write.c
Discription: The second program should read in a file consisting of one number per line.
It should not know how many lines are in the file, and it should be able to read in an arbitrary size file.
You will probably need to read through the file first to get the number of numbers, 
then re-read it to actually grab the data. After reading in the data, 
it should write the set of numbers back to a user-defined file or the terminal if no filename is given.
*/

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){
	// int lineNum =0;
	int i;
	FILE* fp1;
	FILE* fp2;
	char buffer[30];
	if(argc < 2){
		printf("not enough arguments: <file> <input file> <OPTIONAL: outfile> \n");
	}else{
		fp1 = fopen(argv[1] , "r");
		if (fp1 == NULL) perror ("Error opening file");
		if(argc == 2){//write to stdout
			while(NULL != fgets(buffer, sizeof(buffer), fp1)){
				puts(buffer);
			}
		}else{//write to output file
			fp2 = fopen(argv[2], "w");
			if (fp2 == NULL) perror ("Error opening file");
			while(NULL != fgets(buffer, sizeof(buffer), fp1)){
				fputs(buffer, fp2);
			}
			fclose(fp2);
		}
		fclose(fp1);
	}
	return 0;
}

