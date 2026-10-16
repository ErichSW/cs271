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

// Goal of program: read and write a file

/* 	argc is the number of arguments passed
	argv[] is a pointer to an array of strings (array of array of characters)
*/
int main(int argc, const char *argv[]) {
	
	if (argc != 2) {
		printf("Usage: %s [filename]\n", argv[0]);
		exit(EXIT_FAILURE);		//ensure correct no. of args
	}
	
	FILE *fin = fopen( argv[1], "r" ); 		//read input file
	if (argv[1] == NULL) {
		perror("Can't open the file!");		//error output stream
		exit(EXIT_FAILURE);
	}
	
	char out_file[256];
	strcat (out_file, ".echo");
	FILE *fout = fopen (out_file, "w+"); 	//writable
	
	/* 5: reading in the file */
	char line[MAX_LINE_LENGTH] = {0};		//store current line
	unsigned int line_num = 0;				//store current line number, unsigned because always positive
	while (fgets(line, sizeof(line), fin)) {
		line_num++;							// increment line no. variable
		printf ("[%04d] %s", line_num, line);			// print line no. in brackets + text
		fprintf (fout, "%s", line);						// print the line to output file (fprintf)
	}
	
	fclose (fin);		// close file pointers
	fclose (fout);
	
	return 1;
}
