/****************************************************
 * Read header, numbers.h, for details.
 ****************************************************/

/* Include our main header file.*/
#include "numbers.h"
#include "../utils/buffer_tools.h"
#include <stdio.h>
#include <string.h>

/* Our functions are defined below here. We could also put them 
 * in their own files and link them together or #include them.
 */

/* Prepend each word with numbers 0-9. */
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
		//printf("processing: %s", buf);

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
			//printf("done: %s\n", buf);
      }

      /* Reset so we are clear when grab next line. */
		index =0;
      clear_buf(buf);
	}

	fclose(fp_in);
	fclose(fp_out);

	return 0;
}

/* Prepend each word with numbers 0-9. */
int prepend_numbers(char input_file[], char output_file[])
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
		/* Find the end of the buffer. */
      while (buf[index] != '\n' && index < 100)
         index++;

		/* Shift forward to make room at the front of the line for the prepend. */
		while (index > 0)
		{
			buf[index+1] = buf[index];
			index--;
		}

		buf[index+1] = buf[index];

      /* add digits 0-9 to the end */
      for (i=0; i < 10; i++)
      {
         buf[index] = i+48;

			fprintf(fp_out, "%s", buf);
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
	
	char buf[100];
	char combined[1000];

	// an array of char pointers, max 100. 
	char words[1000][100];

	FILE *fp_in;
	FILE *fp_out;
	int i = 0;
	int j = 0;
	int k = 0;
	int last = 0;
	int index = 0;

	/* Make sure the buffer is zero'ed out. */
	clear_buf(buf);

	for (i=0; i<1000; i++)
		words[i][0] = 0;

	fp_in = fopen(input_file, "r");
	fp_out = fopen(output_file, "w+");

	/* Add all the words to the array, words. */
	while (fgets(buf, sizeof(buf), fp_in))
	{
		strcpy(words[index], buf);
		index++;

      /* Reset so we are clear when grab next line. */
      clear_buf(buf);
	}

	/* Now concat all the words together. */
	for (i=0; words[i][0] != 0 && i < 1000; i++)
	{
		for (j=0; words[j][0] != 0 && j < 1000; j++)
		{
			for (k=0; k<10; k++)
			{
				strcpy(combined, words[i]);
				last = strlen(combined);
				combined[last-1] = k+48;
				strcat(combined, words[j]);
				fprintf(fp_out, "%s", combined);
			}

			clear_buf(combined);
		}
		clear_buf(combined);
	}

	fclose(fp_in);
	fclose(fp_out);

	return 0;
}
