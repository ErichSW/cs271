#ifndef ERROR_H
#define ERROR_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

enum exitcode{
	//Error code 1 represents that given file does not exist.
	EXIT_INCORRECT_ARGUMENTS = 1,
	EXIT_CANNOT_OPEN_FILE = 2,
	EXIT_TOO_MANY_INSTRUCTIONS, // = 3
	EXIT_INVALID_LABEL,
	EXIT_SYMBOL_ALREADY_EXISTS,
};

void exit_program(enum exitcode code, ...);	// variable length argument list

#endif