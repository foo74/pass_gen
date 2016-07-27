#include <stdio.h>
#include "characters.h"
#include "../utils/buffer_tools.h"

int replace_chars(char input_file[], char output_file[])
{
	char buf[100];
	FILE *fp_in;
	FILE *fp_out;
	int i = 0;

	/* Make sure the buffer is zero'ed out. */
	clear_buf(buf);

	fp_in = fopen(input_file, "r");
	fp_out = fopen(output_file, "w+");

	while (fgets(buf, sizeof(buf), fp_in))
	{
		/* print the original word */
		printf("processing: %s", buf);
		fprintf(fp_out, "%s", buf);

		for (i=0; i<100 && buf[i] != 0; i++)
		{
			switch (buf[i])
			{
				case 'o':
					buf[i] = '0';
					fprintf(fp_out, "%s", buf);
					break;
				case 'a':
					buf[i] = '@';
					fprintf(fp_out, "%s", buf);
					break;
				case 'e':
					buf[i] = '3';
					fprintf(fp_out, "%s", buf);
					break;
				case 's':
					buf[i] = '$';
					fprintf(fp_out, "%s", buf);
					break;
			}
			
		}
		printf("done: %s\n", buf);
	}

	fclose(fp_in);
	fclose(fp_out);


   //char source_file[] = "input";
   //char dest_file[] = "output";
/*
   foo[0].from = 'o';
   foo[0].to = '0';
   foo[1].from = 'a';
   foo[1].to = '@';
   foo[2].from = 'e';
   foo[2].to = '3';
   foo[3].from = 's';
   foo[3].to = '$';
*/

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
