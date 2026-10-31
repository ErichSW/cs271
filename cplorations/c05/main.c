/****************************************
 * C-ploration 4 for CS 271
 * 
 * [NAME] Erich Winchester
 * [TERM] FALL 2026
 * 
 ****************************************/
 
 // Learning objective: strip away all comments and whitespace
 
#include "parser.h" 	// contains all libraries

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
	fclose (file);							// close file pointer
}


