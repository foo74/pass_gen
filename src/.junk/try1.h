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
 * max:  The maximum buffer size in bytes.
 * stream: The output file straem.
 */
int transform1(char in[], int max, FILE *stream);
int transform2(char in[], int max, FILE *stream);
int transform3(char in[], int max, FILE *stream);
int transform4(char in[], int max, FILE *stream);
void o_to_0(char in[], char out[], int max);
void e_to_3(char in[], char out[], int max);
void a_to_at(char in[], char out[], int max);
void s_to_dol(char in[], char out[], int max);
void add_nums(FILE *in_stream, FILE *out_stream);
int change_char(FILE *stream, char from_char, char to_char);
