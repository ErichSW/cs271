/****************************************
 * C-ploration 8 for CS 271
 * 
 * [NAME] Erich Winchester
 * [TERM] FALL 2026
 * 
 ****************************************/
#include "parser.h"
#define SYMBOL_TABLE_SIZE  1000

// set up custom types
typedef int16_t hack_addr;

struct Symbol {
	char 		*name;
	hack_addr 	addr;
};

// Prototype functions: functions without brackets
	// If you get a conflicting type error, it's because the function is different from the prototype.

// hash prototypes
int hash_fn(char *str);
struct Symbol *symtable_find(char *key);
void symtable_insert(char* key, hack_addr addr);
void symtable_display_table();
void symtable_print_labels();