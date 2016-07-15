/****************************************************
 * Read header, pass_gen.h, for details.
 ****************************************************/

/* Include our main header file.*/
#include "../pass_gen.c"

void clear_buf(char buf[]);

/* Our functions are defined below here. We could also put them 
 * in their own files and link them together or #include them.
 */

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
