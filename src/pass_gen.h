/****************************************************
 * Password generator.
 * A program that generates a list of paswords based
 * on a set of input.
 *****************************************************/

/* Include the standard io library.*/
#include <stdio.h>
#include <string.h>
#include <unistd.h> /* For the getopt() to process args. */
#include <getopt.h>

/* Define the vars we will use to test so we can
 * easily change them. 
 */
#define INPUT_FILE "input"
#define OUTPUT_FILE "output"
#define MAX_LINE 1024

int replace_chars(char input_file[], char output_file[], char from_char, char to_char);
int append_numbers(char input_file[], char output_file[]);
int build_input(char questions_file[], char output_file[]);
int build_input(char questions_file[], char output_file[]);
void clear_buf(char buf[]);
void print_usage();
