/****************************************************
 * info
 *****************************************************/

/* Header guard so our header isn't included multiple times at compile. */ 
#ifndef BUFFER_TOOLS_H
#define BUFFER_TOOLS_H

/* Include the standard io library headers we need.*/

/* Global vars
 */

/* Public functions for this module. */
void clear_buf(char buf[]);
void clear_buf_t(char buf[], int size);

/* End of header guard. */
#endif
