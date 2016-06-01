/****************************************************
 * Read header, transform.h, for details.
 ****************************************************/

/* Include our main header file.*/
#include "transforms.h"

void clear_buf(char buf[]);

/* Our functions are defined below here. We could also put them 
 * in their own files and link them together or #include them.
 */

/* functions */
int replace_char(char input_file[], char output_file[], char from_char, char to_char)
{
   char buf[1024];
   int i;
   FILE *input_stream;
   FILE *output_stream;

   i = 0;
   input_stream = fopen(input_file, "r");
   output_stream = fopen(output_file, "a+");

   while (fgets(buf, sizeof(buf), input_stream))
   {
      for (i=0; i < 1024 && buf[i] != 0; i++)
         if (buf[i] == from_char)
            buf[i] = to_char;

      fprintf(output_stream, "%s", buf);
   }

   fclose(input_stream);
   fclose(output_stream);

/*
   rewind(fp_out2);
   clear_buf(buf);
   add_nums(fp_out5, fp_out4);
*/

   return 0;
}

/* See header pass_gen.h for description. */
/*
int transform1(char in[], int max, FILE *stream)
{
   char buf1[max];

   clear_buf(buf1);
*/
   /* Transform o_to_0() */
/*
   o_to_0(in, buf1, max);
   fprintf(stream, "%s", buf1);
   clear_buf(buf1);

   return 0;
}

void e_to_3(char in[], char out[], int max)
{
   int i;
   i = 0;

   for (i=0; i < max && in[i] != 0; i++)
      if (in[i] == 'e')
         out[i] = '3';
      else
         out[i] = in[i];
}
*/
void add_nums(FILE *in_stream, FILE *out_stream)
{
   char line[1024];
   int i;
   int index;

   clear_buf(line);
   i = 0;
   index = 0;

   while (fgets(line, sizeof(line), in_stream))
   {
      /*find the end of the line*/
      while (line[index] != '\n' && i < 1024)
         index++;

      /* for add digits 0-9 to the end */
      for (i=0; i < 10; i++)
      {
         line[index] = i+48;
         line[index+1] = '\n';
         line[index+2] = 0;
         fprintf(out_stream, "%s", line);
      }

      /* Reset so we are clear when grab next line. */
      index = 0;
      clear_buf(line);
   }
}

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
