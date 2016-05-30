#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
   int a_to_at = 0;
   int display_help = 0;
   int i = 0;
   FILE *input;


   if ( argv[1] == "-h")
   {
      printf("\n\nUsage: main -a -i <input file> -o <output file>\n\n");
      printf("-a transform a's to @'s.\n\n");
   }  

   input = fopen("input", "r");


   /* process options */
   for (i=1; i<argc; i++)
   {
      if (strstr(argv[i], "a") != NULL)
         a_to_at = 1;
   }

   printf("transform a_to_at = %d\n\n", a_to_at);

   return 0;
}
