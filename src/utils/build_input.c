#include "build_input.h"
#include <stdio.h>
#include <string.h>

int build_input(char questions_file[], char output_file[])
{
   FILE *input_stream;
   FILE *output_stream;
   char buf_in[100];
   char buf_out[100];

   input_stream = fopen(questions_file, "r");
   output_stream = fopen(output_file, "w+");

printf("questions_file = %s\noutput_file = %s\n", questions_file, output_file);
   while (fgets(buf_in, sizeof(buf_in), input_stream))
   {
      buf_in[strcspn(buf_in, "\n")] = 0;
      printf("%s ", buf_in);
      /* The %100s reads only up to 100 chars plus NULL terminator. */
      if (scanf("%100s", buf_out) == EOF)
			printf("EOF reached!\n");
      fprintf(output_stream, "%s\n", buf_out);
   }

   fclose(input_stream);
   fclose(output_stream);

   return 0;
}
