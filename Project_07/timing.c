/*
Erfan Azad
Date: 26 November 2014
File: timing.c
Description: Timing the malloc proccess under different conditions.
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[]){

int i; //loop variable
double sum = 0;
double average;
clock_t startTime, endTime;
double runTime;
#define MegaBytes 1000000 // 1MB
#define numIterations 100

//-------------------------------TASK 1------------------------------
printf("Task 1: Mallocing and Freeing 1MB using 1 malloc call\n");
startTime = clock();

int* n = malloc(MegaBytes);
free(n);

endTime = clock();
runTime = ((double) (endTime - startTime)) / CLOCKS_PER_SEC;
printf("Task1 : runTime: %f seconds\n\n", runTime);
//-------------------------------------------------------------------

//-------------------------------TASK 2------------------------------
printf("Task 2: Mallocing and Freeing 1MB using 10^6 malloc calls\n");
startTime = clock();

for(i=0; i< MegaBytes; i++){
	int* n = malloc(1);
	free(n);
}	

endTime = clock();
runTime = ((double) (endTime - startTime)) / CLOCKS_PER_SEC;
printf("Task2 : runTime: %f seconds\n\n", runTime);
//-------------------------------------------------------------------

//-------------------------------TASK 3------------------------------
printf("Task 3: Mallocing and Freeing smallMemory (10MB) \n");
sum = 0; // resetting sum
for(i=0; i< numIterations; i++){
	startTime = clock();
	
	int* n = malloc(MegaBytes);
	free(n);

	endTime = clock();
	runTime = ((double) (endTime - startTime)) / CLOCKS_PER_SEC;

	sum += runTime;
}
average = sum / numIterations;
printf("Average Malloc/Free time: %f seconds\n\n", runTime);
//-------------------------------------------------------------------

//-------------------------------TASK 4------------------------------
printf("Task 4: Mallocing and Freeing mediumMemory (100MB) \n");
sum = 0; // resetting sum
for(i=0; i< numIterations; i++){
	startTime = clock();
	
	int* n = malloc(MegaBytes*100);
	free(n);

	endTime = clock();
	runTime = ((double) (endTime - startTime)) / CLOCKS_PER_SEC;

	sum += runTime;
}
average = sum / numIterations;
printf("Average Malloc/Free time: %f seconds\n\n", runTime);
//-------------------------------------------------------------------

//-------------------------------TASK 5------------------------------
printf("Task 5: Mallocing and Freeing bigMemory (1000MB) \n");
sum = 0; // resetting sum
for(i=0; i< numIterations; i++){
	startTime = clock();
	
	int* n = malloc(MegaBytes*1000);
	free(n);

	endTime = clock();
	runTime = ((double) (endTime - startTime)) / CLOCKS_PER_SEC;

	sum += runTime;
}
average = sum / (numIterations);
printf("Average Malloc/Free time: %f seconds\n\n", runTime);
//-------------------------------------------------------------------


printf("Done!\n");
}
