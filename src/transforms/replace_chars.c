#include "../pass_gen.h"

struct char_transform
{
   char from;
   char to;
};

int replace_chars(char input_file[], char output_file[], char from_char, char to_char)
{
   const int MAX = 5;
   int i = 0;
   struct char_transform foo[MAX];

   //char source_file[] = "input";
   //char dest_file[] = "output";
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

/*
   {
      for (i=0; i < MAX; i++)
      {
         replace_char("custom_input", ovalue, foo[i].from, foo[i].to);
         printf("pass_a: %d\n", i);
      }
      for (i=0; i < MAX; i++)
      {
         replace_char("custom_input", ovalue, foo[i].from, foo[i].to);
         printf("pass_b: %d\n", i);
      }
   }
*/
	//else
		//printf("Input file built, use -t to transform.\n");
	return 0;
}
