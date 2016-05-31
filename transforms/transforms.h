/****************************************************
 * Password generator.
 * A program that generates a list of paswords based
 * on a set of input.
 *****************************************************/

/* Include the standard io library.*/
#include <stdio.h>
#include <string.h>

/* Define the vars we will use to test so we can
 * easily change them. 
 */
#define INPUT_FILE "input"
#define OUTPUT_FILE "output"
#define MAX_LINE 1024

/* Function replaces char occurances in a given file.
 * file_name: The file.
 * from_char: The char to replace. 
 * to_char: The new char that replaces the old.
 */
int replace_char(char file_name[], char from_char, char to_char);
