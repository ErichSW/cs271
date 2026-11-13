/****************************************
 * C-ploration 7 for CS 271
 * 
 * [NAME] Erich Winchester
 * [TERM] FALL 2026
 * 
 ****************************************/
#include "parser.h"
 
#define SYMBOL_TABLE_SIZE  1000

typedef struct address {
	int16_t hack_addr;
} address;

//struct DataItem *hashArray[SYMBOL_TABLE_SIZE];
//struct DataItem *dummyItem;
//struct DataItem *item;

int hash(int *str);
struct Symbol *symtable_find(char *key);
void symtable_insert(char *key, hack_addr addr);
void symtable_display_table();
void symtable_print_labels();