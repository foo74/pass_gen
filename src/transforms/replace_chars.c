#include "../pass_gen.h"

int replace_chars(char input_file[], char output_file[])
{
	char buf[100];
	FILE *fp_in;
	FILE *fp_out;


	clear_buf(buf);
	printf("\nyo foo\n");

	fp_in = fopen(input_file, "r");
	fp_out = fopen(output_file, "w+");

	while (fgets(buf, sizeof(buf), fp_in))
	{
		printf("processing: %s", buf);
		fprintf(fp_out, "%s", buf);
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
