/****************************************************
 * Password generator.
 * A program that generates a list of paswords based
 * on a set of input.
 *****************************************************/

/* Include the standard io library.*/
#include <stdio.h>
#include <string.h>
#include "transforms/transforms.h"

/* Define the vars we will use to test so we can
 * easily change them. 
 */
#define INPUT_FILE "input"
#define OUTPUT_FILE "output"
#define MAX_LINE 1024

int build_input();
void print_usage();
