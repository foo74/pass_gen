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


	return 0;
}
