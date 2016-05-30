/****************************************************
 * Read header, pass_gen.h, for details.
 ****************************************************/

/* Include our main header file.*/
#include "pass_gen.h"

void clear_buf(char buf[]);

/* The main function of our program. */
int main()
{
   char buf[MAX_LINE];
   FILE *fp_in;
   FILE *fp_out;
   FILE *fp_out2;
   FILE *fp_out3;
   FILE *fp_out4;

   clear_buf(buf);

   fp_in = fopen("input", "r");
   fp_out = fopen("pass1", "a+");
   fp_out2 = fopen("pass2", "a+");
   fp_out3 = fopen("pass3", "a+");
   fp_out4 = fopen("output2", "a+");

   /* While we have lines of input, process them. */
   while (fgets(buf, sizeof(buf), fp_in))
   {
      /* Transform 1. */
      transform1(buf, MAX_LINE, fp_out);
   }

   rewind(fp_out);
   clear_buf(buf);

   while (fgets(buf, sizeof(buf), fp_out))
   {
      transform2(buf, MAX_LINE, fp_out2);
   }

   rewind(fp_out2);
   clear_buf(buf);

   while (fgets(buf, sizeof(buf), fp_out2))
   {
      transform3(buf, MAX_LINE, fp_out3);
   }

   /* now add 0-9 to end of all passes */
   rewind(fp_in);
   add_nums(fp_in, fp_out4);
   rewind(fp_out);
   add_nums(fp_out, fp_out4);
   rewind(fp_out2);
   add_nums(fp_out2, fp_out4);
   rewind(fp_out3);
   add_nums(fp_out3, fp_out4);

   fclose(fp_in);
   fclose(fp_out);
   fclose(fp_out2);
   fclose(fp_out3);
   fclose(fp_out4);

   /* Be a good main function and return 0 because all went fine. */
   return 0;
}

/* Our functions are defined below here. We could also put them 
 * in their own files and link them together or #include them.
 */

/* See header pass_gen.h for description. */
int transform1(char in[], int max, FILE *stream)
{
   char buf1[max];

   clear_buf(buf1);

   /* Transform o_to_0() */
   o_to_0(in, buf1, max);
   fprintf(stream, "%s", buf1);
   clear_buf(buf1);

   return 0;
}

int transform2(char in[], int max, FILE *stream)
{
   char buf1[max];

   clear_buf(buf1);

   /* Transform e_to_3() */
   e_to_3(in, buf1, max);
   fprintf(stream, "%s", buf1);
   clear_buf(buf1);

   return 0;
}

int transform3(char in[], int max, FILE *stream)
{
   char buf1[max];

   clear_buf(buf1);

   /* Transform a_to_at() */
   a_to_at(in, buf1, max);
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

void o_to_0(char in[], char out[], int max)
{
   int i;
   i = 0;

   for (i=0; i < max && in[i] != 0; i++)
      if (in[i] == 'o')
         out[i] = '0';
      else
         out[i] = in[i];
}

void a_to_at(char in[], char out[], int max)
{
   int i;
   i = 0;

   for (i=0; i < max && in[i] != 0; i++)
      if (in[i] == 'a')
         out[i] = '@';
      else
         out[i] = in[i];
}

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
