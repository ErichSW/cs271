#ifndef PARSER_H		// prevents redefinition later
#define PARSER_H
 
#include <stdio.h>		// input/output, file reading
#include <string.h>		// strings
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>	// booleans
#include <stdint.h>		// more integer types

#define MAX_LINE_LENGTH  200
#define ALT_LINE_LENGTH  (MAX_LINE_LENGTH - 2)
#define MAX_HACK_ADDRESS  INT16_MAX
#define MAX_INSTRUCTIONS  MAX_HACK_ADDRESS

/** function prototypes **/
char *strip(char *s);
bool is_Atype(const char *line);	// const means read-only
bool is_Ctype(const char *line);
bool is_label(const char *line);
char *extract_label(const char *line, char *label);
void parse(FILE *file);

/* define new types */
typedef int16_t hack_addr;
typedef	int16_t opcode;

/* build data structure */
typedef enum instruction{
	Invalid = -1,
	A_Type, // = 0
	C_Type, // = 1
} instruction_type;

typedef struct c_instruction{
	opcode a:1;
	opcode comp:6;
	opcode dest:3;
	opcode jump:3;
} c_instruction_type;

typedef struct a_instruction{
	union {
		hack_addr address;
		char *label;
	} addr;
	bool is_addr;
} a_instruction_type;

typedef struct complete_instruction{
	union {
		a_instruction_type a;
		c_instruction_type c;
	} instruct;
	instruction_type type;
} complete_instruction_type;


#endif