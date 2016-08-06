/****************************************************
 * Read header, pass_gen.h, for details.
 ****************************************************/

/* Include our main header file.*/
#include "buffer_tools.h"
#include <stdio.h>

/* Our functions are defined below here. We could also put them 
 * in their own files and link them together or #include them.
 */

/* Clear buffers. */
void clear_buf(char buf[])
{
   int i;
   i = 0;

   for (i=0; i < BUFSIZ; i++)
   {
      buf[i] = 0;
   }
}

void clear_buf_t(char buf[], int size)
{
   int i;
   i = 0;

   for (i=0; i < size; i++)
   {
      buf[i] = 0;
   }
}
