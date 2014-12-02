/*
Erfan Azad
Date: 29 Nov 2014
File: parSort.c
Description: comparing the time of parallel vs. sequential sort
Compile with:  gcc -Wall -pedantic -o parSort parSort.c
*/
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

typedef struct {
  int* array;
  int size;
} threadInfo;

//---------------------------------Sequential--------------------------------------
/*
Auxilary funtion to be used in qsort
*/
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}


/*
Sorts int* "array" of size "size".
NOTE: it does not return a copy but sorts the same array using qsort.
*/
void seqSort(int* array, int size){
	qsort(array, size, sizeof(int), compare);
}
//----------------------------------------------------------------------------------



//-------------------------------------Parallel-------------------------------------


void* thread_sort(void* arg){
	threadInfo* ti = (threadInfo*) arg;
	qsort(ti->array, ti->size, sizeof(int), compare);
}

/*
Sorts int* "array" of size "size".
NOTE: it does not return a copy but sorts the same array using qsort but using "numThreads" threads.
NOTE2: numTHreads cannot be higher than the size of the array.
NOTE3: size of the array muct be devisible by the number of threads
*/
void parSort(int* array, int size, int numThreads){
	int i, j, k;
	threadInfo ti[numThreads];
	pthread_t thread[numThreads];

	for(i=0;i<numThreads;i++) {
	    ti[i].size = size/numThreads;
	    ti[i].array = &( array[i*(size/numThreads)] );
  	}

  	for(j=0;j<numThreads;j++) {
    	pthread_create(&(thread[j]), NULL, thread_sort, &(ti[j]));
  	}

  	for(k=0;k<numThreads;k++) {
    pthread_join( thread[k], NULL );
  }

	
}
//----------------------------------------------------------------------------------
int main(int argc, char* argv[]){
	int i;
	int a[10];
	for(i=0; i<10; i++){
		a[i] = 10-i;
	}

	seqSort(a, 10);
	printf()


	return 0;
}

