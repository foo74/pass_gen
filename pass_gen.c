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

   clear_buf(buf);

   /* Print the header info. */
   printf("\n---------------------------------------------------------");
   printf("\n- Password Generator is a program that build a list of  -");
   printf("\n- passwords using various transformations. For example, -");
   printf("\n- turning o's to 0's.                                   -");   
   printf("\n---------------------------------------------------------\n\n");


   fp_in = fopen(INPUT_FILE, "r");
   fp_out = fopen(OUTPUT_FILE, "a");

   /* While we have lines of input, process them. */
   while (fgets(buf, sizeof(buf), fp_in))
   {
      printf("processing: %s", buf);
      fprintf(fp_out, "%s", buf);

      /* Transform 1. */
      transform1(buf, MAX_LINE, fp_out);
      printf("\n");
 /*     add_nums(buf, MAX_LINE, fp_out);*/
   }

   fclose(fp_in);
   fclose(fp_out);

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
   char buf2[max];

   clear_buf(buf1);
   clear_buf(buf2);

   /* add nums to orig */
   add_nums(in, max, stream);

   /* Transform o_to_0() > e_to_3() */
   o_to_0(in, buf1, max);
   printf("-> %s", buf1);
   fprintf(stream, "%s", buf1);
   add_nums(buf1, max, stream);
   clear_buf(buf1);

   /* Transform e_to_3() > o_to_0() > then combined. */
   e_to_3(in, buf1, max);
   printf("-> %s", buf1);
   fprintf(stream, "%s", buf1);
   add_nums(buf1, max, stream);
   o_to_0(buf1, buf2, max);
   printf("-> %s", buf2);
   fprintf(stream, "%s", buf2);
   add_nums(buf2, max, stream);
   clear_buf(buf1);
   clear_buf(buf2);

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

void add_nums(char in[], int max, FILE *stream)
{
   char tmp[max];
   clear_buf(tmp);
   
   int i;
   int index;
   i = 0;
   index = 0;

   /*find the end of the line*/
   while (in[i] != '\n' && i < 1024)
   {
      tmp[i] = in[i];
      i++;
   }

   index = i;

   for (i=0; i < 10; i++)
   {
      tmp[index] = i+48;
      printf("-> %s\n", tmp);
      fprintf(stream, "%s\n", tmp);
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
