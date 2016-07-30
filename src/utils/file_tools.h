/****************************************************
 * info
 *****************************************************/

/* Header guard so our header isn't included multiple times at compile. */ 
#ifndef FILE_TOOLS_H
#define FILE_TOOLS_H

/* Include the standard io library headers we need.*/

/* Global vars
 */

/* Public functions for this module. */
/* returns 1 if file exists, 0 if not, and -1 if error */
int file_exists(char file_to_check[]);

/* End of header guard. */
#endif
