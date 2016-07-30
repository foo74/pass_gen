/****************************************************
 * Read header, numbers.h, for details.
 ****************************************************/

/* Include our main header file.*/
#include "numbers.h"
#include "../utils/buffer_tools.h"
#include <stdio.h>

/* Our functions are defined below here. We could also put them 
 * in their own files and link them together or #include them.
 */

/* functions */
int append_numbers(char input_file[], char output_file[])
{
	char buf[100];
	FILE *fp_in;
	FILE *fp_out;
	int i = 0;
	int index = 0;

	/* Make sure the buffer is zero'ed out. */
	clear_buf(buf);

	fp_in = fopen(input_file, "r");
	fp_out = fopen(output_file, "w+");

	while (fgets(buf, sizeof(buf), fp_in))
	{
		/* print the original word */
		printf("processing: %s", buf);

		/* find the end of the line */
      while (buf[index] != '\n' && index < 100)
         index++;

      /* add digits 0-9 to the end */
      for (i=0; i < 10; i++)
      {
         buf[index] = i+48;
         buf[index+1] = '\n';
         buf[index+2] = 0;

			fprintf(fp_out, "%s", buf);
			printf("done: %s\n", buf);
      }

      /* Reset so we are clear when grab next line. */
		index =0;
      clear_buf(buf);
	}

	fclose(fp_in);
	fclose(fp_out);

	return 0;
}

int concat_with_numbers(char input_file[], char output_file[])
{
	return 0;
}
