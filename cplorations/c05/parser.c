/****************************************
 * C-ploration 4 for CS 271
 * 
 * [NAME] Erich Winchester
 * [TERM] FALL 2026
 * 
 ****************************************/
#include "parser.h"


/* Function: is_Atype
 * ------------
 * determine if line is an Assembly A-type instruction
 *
 * return: 1 or 0
 */
bool is_Atype(const char * line) {
	
	if (line[0] == '@') {
		return true;
	}
	return false;
}

/* Function: is_label
 * ------------
 * determine if line is an Assembly label
 * 
 * return: 1 or 0
 */
bool is_label(const char * line) {
	
	if (line[0] == '(' 						// check if first char '(' and last char ')'
	&& line[strlen(line)-1] == ')') {		// use strlen() -1 to find last position in line
		return true;
	}
	return false;
}

/* Function: is_Ctype (incomplete)
 * ------------
 * determine if line is an Assembly C-type instruction
 *
 * return: 1 or 0
 */
bool is_Ctype(const char * line) {
	
	char Ctype[] = "ADM0";					// make list array of all possible starting values
	int i = 0;								// cycle through list until match is found
	while (i <= strlen(Ctype)) {
		if (line[0] == Ctype[i]) {
			return true;
		}
		i++;
	}
	return false;
}

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

/* Primary Function: parse
 * -------------
 * iterate each line in the file and strip whitespace and comments. 
 *
 * file: pointer to FILE to parse
 *
 * returns: nothing
 */
void parse(FILE * file){
	
	char line[MAX_LINE_LENGTH];
	
	while (fgets(line, sizeof(line), file)) {
		
		strip(line);
		
		char inst_type;						// determine instruction type
		if (is_Atype(line) == true) {
			inst_type = 'A';
		} else if (is_label(line) == true) {
			inst_type = 'L';
		} else if (is_Ctype(line) == true) {
			inst_type = 'C';
		} else {
			inst_type = '\0';
		}
		
		if (*line != '\0') {				// if not *line then continue
			printf ("%c  %s\n", inst_type, line);
		}
	}
	
}
