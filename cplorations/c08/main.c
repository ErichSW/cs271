/****************************************
 * C-ploration 8 for CS 271
 * 
 * [NAME] Erich Winchester
 * [TERM] FALL 2026
 * 
 ****************************************/
#include "parser.h"
#include "symtable.h"

int main(int argc, const char *argv[]) {
	if (argc != 2) {
		printf("Please select a file with 1 argument: %s [filename]\n", argv[0]);
		exit(EXIT_FAILURE);					//ensure correct no. of args
	}
	
	FILE *file = fopen (argv[1], "r" ); 	//read input file
	
	if (file == NULL) {
		perror("Can't open the file!");		//error output stream
		exit(EXIT_FAILURE);
	}
	
	parse (file);							// call function 'parse'
	symtable_print_labels();				// print hash table
	fclose (file);							// close file pointer
}
