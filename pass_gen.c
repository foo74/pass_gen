/****************************************************
 * Read header, pass_gen.h, for details.
 ****************************************************/

/* Include our main header file.*/
#include "pass_gen.h"

void clear_buf(char buf[]);

/* The main function of our program. */
int main()
{
   char buf1[MAX_LINE];
   char buf2[MAX_LINE];
   FILE *fp_in;
   FILE *fp_out;

   clear_buf(buf1);
   clear_buf(buf2);

   /* Print the header info. */
   printf("\n---------------------------------------------------------");
   printf("\n- Password Generator is a program that build a list of  -");
   printf("\n- passwords using various transformations. For example, -");
   printf("\n- turning o's to 0's.                                   -");   
   printf("\n---------------------------------------------------------\n\n");


   fp_in = fopen(INPUT_FILE, "r");
   fp_out = fopen(OUTPUT_FILE, "w");

   /* While we have lines of input, process them. */
   while (fgets(buf1, sizeof(buf1), fp_in))
   {
      printf("processing: %s", buf1);

      /* Transform o's to 0's. */
      o_to_0(buf1, buf2, MAX_LINE);
      printf("-> %s\n", buf2);
      fprintf(fp_out, "%s\n", buf2);
      clear_buf(buf2);

      /* Transform e's to 3's. */
      e_to_3(buf1, buf2, MAX_LINE);
      printf("-> %s\n", buf2);
      fprintf(fp_out, "%s\n", buf2);
      clear_buf(buf1);
      clear_buf(buf2);
      printf("\n");
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
int o_to_0(char in[], char out[], int max)
{
   int i;
   i = 0;

   /* Transform o's to 0's. */
   for (i=0; i < max && in[i] != 0 && in[i] != '\n'; i++)
      if (in[i] == 'o')
         out[i] = '0';
      else
         out[i] = in[i];

   return 0;
}

/* See header pass_gen.h for description. */
int e_to_3(char in[], char out[], int max)
{
   int i;
   i = 0;

   /* Transform e's to 3's. */
   for (i=0; i < max && in[i] != 0 && in[i] != '\n'; i++)
      if (in[i] == 'e')
         out[i] = '3';
      else
         out[i] = in[i];

   return 0;
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
