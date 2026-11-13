/****************************************
 * C-ploration 7 for CS 271
 * 
 * [NAME] Erich Winchester
 * [TERM] FALL 2026
 * 
 ****************************************/
#include "symtable.h"
 
struct Symbol *hashArray[SYMBOL_TABLE_SIZE]; 
 
int hash(int *str)
{
	unsigned long hash = 5381;
	int c;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return hash;
}