/****************************************
 * C-ploration 8 for CS 271
 * 
 * [NAME] Erich Winchester
 * [TERM] FALL 2026
 * 
 ****************************************/
 
#include "parser.h"
#include "symtable.h"
#include "error.h"

int main(int argc, const char *argv[]) {
	if (argc != 2) {
		// incorrect number of arguments
		exit_program(EXIT_INCORRECT_ARGUMENTS, argv[0]);        
	}  

	FILE *file = fopen (argv[1], "r" ); 	//read input file
	if (file == NULL){ 
		exit_program(EXIT_CANNOT_OPEN_FILE, argv[1]);
	}	
	
	parse (file);							// call function 'parse'
	symtable_print_labels();
	fclose (file);							// close file pointer
}

// a