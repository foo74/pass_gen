/****************************************************
 * Read header, pass_gen.h, for details.
 ****************************************************/

/* Include our main header file.*/
#include "../pass_gen.h"

/* Our functions are defined below here. We could also put them 
 * in their own files and link them together or #include them.
 */

/* functions */
int append_numbers(char input_file[], char output_file[])
{
/*
   char line[1024];
   int i;
   int index;

   clear_buf(line);
   i = 0;
   index = 0;

   while (fgets(line, sizeof(line), in_stream))
   {
*/
      /*find the end of the line*/
/*
      while (line[index] != '\n' && i < 1024)
         index++;
*/
      /* for add digits 0-9 to the end */
/*
      for (i=0; i < 10; i++)
      {
         line[index] = i+48;
         line[index+1] = '\n';
         line[index+2] = 0;
         fprintf(out_stream, "%s", line);
      }
*/
      /* Reset so we are clear when grab next line. */
/*
      index = 0;
      clear_buf(line);
   }
*/
	return 0;
}
