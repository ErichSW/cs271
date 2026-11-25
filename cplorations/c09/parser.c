#include "parser.h"
#include "symtable.h"
#include "error.h"

/* Function: strip
 * -------------
 * remove whitespace and comments from a line
 *
 * s: the char* string to strip
 *
 * returns: the stripped char* string
 */
char *strip(char *s){	
	
	int i = 0;
	for (char *s2 = s; *s2 != '\0'; s2++) {
		if (*s2 == '/' && *(s2+1) == '/') { // ignore comments
			break;
		} else if (!isspace((unsigned char) *s2)) {	// if current char is not whitespace
			s[i++] = *s2;
		} 
	}
	s[i] = '\0';							// set ith index of s to be \0
	
    return s;
}

/* Function: is_Atype
 * ------------
 * determine if line is an Assembly A-type instruction
 *
 * return: 1 or 0
 */
bool is_Atype(const char *line) {
	
	if (line[0] == '@') {
		return true;
	}
	return false;
}

/* Function: is_Ctype
 * ------------
 * determine if line is an Assembly C-type instruction
 *
 * return: 1 or 0
 */
bool is_Ctype(const char *line) {
	
	char Ctype[] = "ADM0";					// make list array of all possible starting values
	int i = 0;								// cycle through list until match is found
	while (i < strlen(Ctype)) {
		if (line[0] == Ctype[i]) {
			return true;
		}
		i++;
	}
	return false;
}

/* Function: is_label
 * ------------
 * determine if line is an Assembly label
 * 
 * return: 1 or 0
 */
bool is_label(const char *line) {
	
	if (line[0] == '(' 						// check if first char '(' and last char ')'
	&& line[strlen(line)-1] == ')') {		// use strlen() -1 to find last position in line
		return true;
	}
	return false;
}

/* Function: extract_label
 * -------------
 * extract label name from parentheses
 *
 */
char *extract_label(const char *line, char *label) {

	// label is line without front and back parentheses
	int label_pos = 0;
	int line_pos = 1;
	int len = strlen(line);
	
	while (len-1 > line_pos) {
		label[label_pos] = line[line_pos];
		label_pos++;
		line_pos++;
	}
	label[label_pos] = '\0';
	
	return label;
}

/* Function: add_predefined_symbols

*/
void add_predefined_symbols() {
	for (int i =0; i < NUM_PREDEFINED_SYMBOLS; i++) {
		
	}
	
}

/** Primary Function: parser
 * -------------
 * iterate each line in the file and strip whitespace and comments. 
 *
 * file: pointer to FILE to parse
 *
 * returns: nothing
 **/
void parse(FILE *file){
	
	char line[MAX_LINE_LENGTH];
	char label[MAX_LINE_LENGTH];
	unsigned int line_num = 0;
	unsigned int instr_num = 0;
	
	while (fgets(line, sizeof(line), file)) {

		line_num++;

		if (instr_num > MAX_INSTRUCTIONS) {
			exit_program(EXIT_TOO_MANY_INSTRUCTIONS, MAX_INSTRUCTIONS + 1);
		}

		strip(line);

		if (is_label(line)) {
			extract_label(line, label);
			strcpy(line, label);                       // for error messages

			if (!isalpha((unsigned char)label[0])) {
				exit_program(EXIT_INVALID_LABEL, line_num, line);
			}
			if (symtable_find(label) != NULL) {
				exit_program(EXIT_SYMBOL_ALREADY_EXISTS, line_num, line);
			}

			symtable_insert(label, instr_num);         // address of NEXT instruction

		} else if (*line != '\0') {
			char inst_type = is_Atype(line) ? 'A' :
							 is_Ctype(line) ? 'C' : '\0';
			printf("%u: %c  %s\n", instr_num, inst_type, line);
			instr_num++;
		}
	}
}
