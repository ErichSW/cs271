/****************************************
 * C-ploration 7 for CS 271
 * 
 * [NAME] Erich Winchester
 * [TERM] FALL 2026
 * 
 ****************************************/
#include "symtable.h"
 
struct Symbol *hashArray[SYMBOL_TABLE_SIZE]; 
 
/* Function: hash_fn
 * -------------
 * takes a string and "hashes" it
 *
 * returns: hash-ified value
 */
int hash_fn(char *str) {
	unsigned long hash = 5381;
	int c;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return hash % SYMBOL_TABLE_SIZE;
}

/* Function: symtable_insert
 * -------------
 * inserting hashed value into table
 *
 * returns: nothing
 */
void symtable_insert(char *key,hack_addr addr) {

   struct Symbol *item = malloc(sizeof(struct Symbol));
   item->name = strdup(key);
   item->addr = addr;

   int hashIndex = hash_fn(key);

   while(hashArray[hashIndex] != NULL) {
      hashIndex++;
      hashIndex %= SYMBOL_TABLE_SIZE;
   }
	
   hashArray[hashIndex] = item;
}

/* Function: symtable_find
 * -------------
 * determine if symbol exists in table
 *
 * returns: nothing
 */
 struct Symbol *symtable_find(char *key) {
	 int hashIndex = hash_fn(key);
	 
	 while (hashArray[hashIndex] != NULL) {
		if (strcmp(hashArray[hashIndex]->name, key) == 0)
			return hashArray[hashIndex];
		
		hashIndex++;
		hashIndex %= SYMBOL_TABLE_SIZE;		// wrap around table
	 }
	return NULL;
 };
 
 /* Function: symtable_display_table
 * -------------
 *  prints all names and address in hash table
 *
 * returns: print only
 */
 void symtable_display_table() {
	 
	int i = 0;
	for(i = 0; i<SYMBOL_TABLE_SIZE; i++) {
		if(hashArray[i] != NULL)
			printf(" (%s,%d)",hashArray[i]->name,hashArray[i]->addr);
		else
			printf(" ~~ ");
	}
	printf("\n");
 };
 
/* Function: symtable_print_labels
 * -------------
 * ?????
 *
 * returns:
 */
 void symtable_print_labels() {
   int i = 0;    
   for(i = 0; i<SYMBOL_TABLE_SIZE; i++) {
        if(hashArray[i] != NULL){
             printf("{%s,%d}\n",hashArray[i]->name,hashArray[i]->addr);
        }
   }
} 