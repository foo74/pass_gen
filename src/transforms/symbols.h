/****************************************************
 * info
 *****************************************************/

/* Header guard so our header isn't included multiple times at compile. */ 
#ifndef SYMBOLS_H
#define SYMBOLS_H

/* Include the standard io library headers we need.*/

/* Global vars
 */

/* Public functions for this module. */
int append_symbols(char input_file[], char output_file[]);
int prepend_symbols(char input_file[], char output_file[]);
int concat_with_symbols(char input_file[], char output_file[]);

/* End of header guard. */
#endif
