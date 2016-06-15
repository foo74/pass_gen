#include "pass_gen.h"

struct char_transform
{
   char from;
   char to;
};

int main(int argc, char *argv[])
{
   const int MAX = 5;
   int transform = 0;
   int i = 0;
   struct char_transform foo[MAX];

   char source_file[] = "input";
   char dest_file[] = "output";
   foo[0].from = 'o';
   foo[0].to = '0';
   foo[1].from = 'a';
   foo[1].to = '@';
   foo[2].from = 'e';
   foo[2].to = '3';
   foo[3].from = 's';
   foo[3].to = '$';
   foo[4].from = 'a';
   foo[4].to = '4';

   if ( argc == 1 || (strstr(argv[1], "-h") != NULL) )
   {
      printf("\n\nUsage: pass_gen -a -i <input file> -o <output file>\n\n");
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
      for (i=0; i < MAX; i++)
      {
         replace_char(source_file, dest_file, foo[i].from, foo[i].to);
         printf("pass_a: %d\n", i);
      }
      for (i=0; i < MAX; i++)
      {
         replace_char(dest_file, dest_file, foo[i].from, foo[i].to);
         printf("pass_b: %d\n", i);
      }
   }

   printf("argv[1] = %s\n", argv[1]);

   return 0;
}

