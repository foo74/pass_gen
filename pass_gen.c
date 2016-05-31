#include "pass_gen.h"

int main(int argc, char *argv[])
{
   int transform = 0;
   int i = 0;

   char file[] = "blah";
   char a = 'a';
   char b = 'b';

   if ( argc == 1 || (strstr(argv[1], "-h") != NULL) )
   {
      printf("\n\nUsage: main -a -i <input file> -o <output file>\n\n");
      printf("-a transform a's to @'s.\n\n");
   }  

   /* process options */
   for (i=1; i<argc; i++)
   {
      if (strstr(argv[i], "-t") != NULL)
         transform = 1;
   }

   if ( transform )
   {
      replace_char(file, a, b);
   }

   printf("argv[1] = %s\n\n", argv[1]);

   return 0;
}
