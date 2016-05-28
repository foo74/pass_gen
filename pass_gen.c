/****************************************************
 * Read header, pass_gen.h, for details.
 ****************************************************/

/* Include our main header file.*/
#include "pass_gen.h"

/* The main function of our program. */
int main()
{
   char buf1[MAX_LINE];
   char buf2[MAX_LINE];
   FILE *fp_in;
   FILE *fp_out;
   int i;

   i = 0;
   for (i=0; i < MAX_LINE; i++)
   {
      buf1[i] = 0;
      buf2[i] = 0;
   }

   /* Print the header info. */
   printf("\n---------------------------------------------------------");
   printf("\n- Password Generator is a program that build a list of  -");
   printf("\n- passwords using various transformations. For example, -");
   printf("\n- turning o's to 0's.                                   -");   
   printf("\n---------------------------------------------------------\n\n");


   fp_in = fopen(INPUT_FILE, "r");
   fp_out = fopen(OUTPUT_FILE, "w");

   i = 0;

   /* While we have lines of input, process them. */
   while (fgets(buf1, sizeof(buf1), fp_in))
   {
      printf("processing: %s", buf1);

      /* Transform o's to 0's. */
      ohtozero(buf1, buf2, MAX_LINE);
      printf("-> %s\n\n", buf2);
      fprintf(fp_out, "%s\n", buf2);


      /* Clear buffers. */
      for (i=0; i < MAX_LINE; i++)
      {
         buf1[i] = 0;
         buf2[i] = 0;
      }
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
int ohtozero(char in[], char out[], int max)
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
