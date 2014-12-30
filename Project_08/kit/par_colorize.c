/*
Erfan Azad
Date: 17 Des 2014
File: par_colorize.c
Description: parallelized version of colorize.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include "ppmIO.h"

#define NUMTHREADS 3

//structure that holds information about the tread and its pixel array
typedef struct{ 
	int Thread_ID;
	int size;
	Pixel* data;
}ThreadInfo;

//Function to be called by each thread to do the pixel color manipulation
//Parameter: takes a void* as the argument. in out case the void* will be 
//interpreted as a pointer to a ThreadInfo structure.
void* par_colorize(void* info){ 
	ThreadInfo* Tinfo = (ThreadInfo*) info;
	int i;
	for(i=0;i<Tinfo->size;i++) {
		// Tinfo->data[i].r = Tinfo->data[i].r > 128 ? (220+Tinfo->data[i].r)/2 : (30+Tinfo->data[i].r)/2;
		// Tinfo->data[i].g = Tinfo->data[i].g > 128 ? (220+Tinfo->data[i].g)/2 : (30+Tinfo->data[i].g)/2;
		// Tinfo->data[i].b = Tinfo->data[i].b > 128 ? (220+Tinfo->data[i].b)/2 : (30+Tinfo->data[i].b)/2;

		//creates the negative of the image
		Tinfo->data[i].r = 255 - Tinfo->data[i].r;
		Tinfo->data[i].g = 255 - Tinfo->data[i].g;
		Tinfo->data[i].b = 255 - Tinfo->data[i].b;
	}
}

int main(int argc, char *argv[]) {
	printf("Starting....\n");
	Pixel *src;
	int rows, cols, colors;
	int i;
	int numthreads;
	clock_t start; 
	clock_t end; 
   	double time_elapsed_in_seconds;


	numthreads = NUMTHREADS;
	if(argc == 3){ // changing the number of threads from user input
		numthreads = atoi(argv[2]);
	}

	// check usage
	if( argc < 2 ) {
		printf("Usage: %s <image filename>\n", argv[0]);
		exit(-1);
	}

	// read image and check for errors
	src = ppm_read( &rows, &cols, &colors, argv[1] );
	if( !src ) {
		printf("Unable to read file %s\n", argv[1]);
		exit(-1);
	}

	//initializing threads and ThreadInfo structs
	ThreadInfo ti[numthreads];
	pthread_t thread[numthreads];

	for(i=0; i<numthreads; i++){
		ti[i].Thread_ID = i;
		ti[i].size = (rows*cols)/numthreads;
		ti[i].data = &(src[i*((rows*cols)/numthreads)]); //setting the data field to the begining of each portion of the image array
	}

	//create threads
	start = clock();
	for(i=0; i<numthreads; i++){
		pthread_create(&(thread[i]),NULL, par_colorize, &(ti[i])); 
	}

	//join threads
	for(i=0; i<numthreads; i++){
		pthread_join(thread[i],NULL); 
	}
	end = clock();
	time_elapsed_in_seconds = (end - start)/(double)CLOCKS_PER_SEC;
	printf("Time Elapsed using %d threds: %.6f s\n",numthreads, time_elapsed_in_seconds);


	// write out the image
	ppm_write( src, rows, cols, colors, "bold.ppm" );


	free(src);

	return(0);
}