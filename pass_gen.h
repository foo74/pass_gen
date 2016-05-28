/****************************************************
 * Password generator.
 * A program that generates a list of paswords based
 * on a set of input.
 *****************************************************/

/* Include the standard io library.*/
#include <stdio.h>

/* Define the vars we will use to test so we can
 * easily change them. 
 */
#define INPUT_FILE "input"
#define OUTPUT_FILE "output"
#define MAX_LINE 1024

/* Function that takes two string pointers s and t. The t
 * in:   Contains the input.
 * out:  Contains the output.
 * max:  The maximum buffer size in bytes.
 */
int o_to_0(char in[], char out[], int max);
int e_to_3(char in[], char out[], int max);
