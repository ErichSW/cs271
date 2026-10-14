/****************************************
 * C-ploration 3 for CS 271
 * 
 * [NAME] Erich Winchester
 * [TERM] FALL 2026
 * 
 ****************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH  200



/* 	argc is the number of arguments passed
	argv[] is a pointer to an array of strings (array of array of characters)
	1. accepting arguments
*/
int main(int argc, const char *argv[]) {
	
	/* 2: find out if user inputted correct number of arguments */
	if (argc != 2) {
		printf("Usage: %s [filename]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	/* 3: open the input file */
	FILE *fin = fopen( argv[1], "r" ); 		//read-only
	if (argv[1] == NULL) {
		perror("Can't open the file!");
		exit(EXIT_FAILURE);
	}
	
	/* 4: open the output file */
	char out_file[99];
	strcat (out_file, ".echo");
	FILE *fout = fopen (out_file, "w+"); 	//writable
	
	/* 5: reading in the file */
	
	
	
	
	return 1;
}
