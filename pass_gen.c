/****************************************************
 * Read header, pass_gen.h, for details.
 ****************************************************/

/* Include our main header file.*/
#include "pass_gen.h"

/* The main function of our program. */
int main()
{
   char buf[1024];
   FILE *fp_in;
   FILE *fp_out;
   int i;

   i = 0;
   for (i=0; i < 1024; i++)
      buf[i] = 0;

   /* Print the header info. */
   printf("\n---------------------------------------------------------");
   printf("\n- Password Generator is a program that build a list of  -");
   printf("\n- passwords using various transformations. For example, -");
   printf("\n- turning o's to 0's.                                   -");   
   printf("\n---------------------------------------------------------\n\n");


   fp_in = fopen(INPUT_FILE, "r");
   fp_out = fopen(OUTPUT_FILE, "w");

   i = 0;

/*
   char a;
   while ((a = fgetc(fp_in)) != EOF)
      buf[i++] = a;
*/


   /* Read input. */
   printf("Reading file %s...", INPUT_FILE);
   fgets(buf, 1024, fp_in);
   printf("Done.\n");

   /* Write the original. */
   printf("Writing passwords to file...\n\n");

   printf("%s", buf);
   for (i=0; i < 1024 && buf[i] != 0; i++)
      fprintf(fp_out, "%c", buf[i]);

   /* Transofrm o's to 0's. */
   for (i=0; i < 1024 && buf[i] != 0; i++)
      if (buf[i] == 'o')
         buf[i] = '0';

   /* Write the transformed. */
   printf("%s", buf);
   for (i=0; i < 1024 && buf[i] != 0; i++)
      fprintf(fp_out, "%c", buf[i]);

   printf("\n\nDone.\n");

   fclose(fp_in);
   fclose(fp_out);


   /* Be a good main function and return 0 because all went fine. */
   return 0;
}


/* Our functions are defined below here. We could also put them 
 * in their own files and link them together or #include them.
 */

/* See header pass_gen.h for description. */
void ohtozero()
{
}
