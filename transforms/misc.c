/****************************************************
 * Read header, transform.h, for details.
 ****************************************************/

/* Include our main header file.*/
#include "misc.h"

void clear_buf(char buf[]);

/* Clear buffers. */
void clear_buf(char buf[])
{
   int i;
   i = 0;

   for (i=0; i < MAX_LINE; i++)
   {
      buf[i] = 0;
   }
}
