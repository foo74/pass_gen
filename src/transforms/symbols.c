/****************************************************
 * Read header, symbols.h, for details.
 ****************************************************/

/* Include our main header file.*/
#include "symbols.h"
#include "../utils/buffer_tools.h"
#include <stdio.h>
#include <string.h>

/* Our functions are defined below here. We could also put them 
 * in their own files and link them together or #include them.
 */

/* append each word with symbols. */
int append_symbols(char input_file[], char output_file[])
{
	char buf[BUFSIZ];
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
		/* find the end of the line */
      while (buf[index] != '\n' && index < BUFSIZ)
         index++;

      /* add symbols --- asci 32-47 --->(space)!"#$%&'()*+,/ */
      for (i=32; i < 48; i++)
      {
         buf[index] = i;
         buf[index+1] = '\n';
         buf[index+2] = 0;

			fprintf(fp_out, "%s", buf);
      }

      /* add symbols --- asci 58-64 ---> :;<=>?@ */
      for (i=58; i < 65; i++)
      {
         buf[index] = i;
         buf[index+1] = '\n';
         buf[index+2] = 0;

			fprintf(fp_out, "%s", buf);
      }

      /* add symbols --- asci 91-96 ---> [\]^_` */
      for (i=91; i < 97; i++)
      {
         buf[index] = i;
         buf[index+1] = '\n';
         buf[index+2] = 0;

			fprintf(fp_out, "%s", buf);
      }

      /* add symbols --- asci 123-126 ---> {|}~ */
      for (i=123; i < 127; i++)
      {
         buf[index] = i;
         buf[index+1] = '\n';
         buf[index+2] = 0;

			fprintf(fp_out, "%s", buf);
      }

      /* Reset so we are clear when grab next line. */
		index = 0;
      clear_buf(buf);
	}

	fclose(fp_in);
	fclose(fp_out);

	return 0;
}

/* Prepend each word with symbols. */
int prepend_symbols(char input_file[], char output_file[])
{
	char buf[BUFSIZ];
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
      while (buf[index] != '\n' && index < BUFSIZ)
         index++;

		/* Shift forward to make room at the front of the line for the prepend. */
		while (index > 0)
		{
			buf[index+1] = buf[index];
			index--;
		}

		/* Dont forget the first digit. */
		buf[index+1] = buf[index];

      /* add symbols --- asci 32-47 --->(space)!"#$%&'()*+,/ */
      for (i=32; i < 48; i++)
      {
         buf[index] = i;
			fprintf(fp_out, "%s", buf);
      }

      /* add symbols --- asci 58-64 ---> :;<=>?@ */
      for (i=58; i < 65; i++)
      {
         buf[index] = i;
			fprintf(fp_out, "%s", buf);
      }

      /* add symbols --- asci 91-96 ---> [\]^_` */
      for (i=91; i < 97; i++)
      {
         buf[index] = i;
			fprintf(fp_out, "%s", buf);
      }

      /* add symbols --- asci 123-126 ---> {|}~ */
      for (i=123; i < 127; i++)
      {
         buf[index] = i;
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

int concat_with_symbols(char input_file[], char output_file[])
{
	
	char buf[100];
	char combined[BUFSIZ];

	// an array of char pointers, max 100. 
	char words[BUFSIZ][100];

	FILE *fp_in;
	FILE *fp_out;
	int i = 0;
	int j = 0;
	int k = 0;
	int last = 0;
	int index = 0;

	/* Make sure the buffer is zero'ed out. */
	clear_buf_t(buf, 100);

	for (i=0; i<BUFSIZ; i++)
		words[i][0] = 0;

	fp_in = fopen(input_file, "r");
	fp_out = fopen(output_file, "w+");

	/* Add all the words to the array, words. */
	while (fgets(buf, sizeof(buf), fp_in))
	{
		strcpy(words[index], buf);
		index++;

      /* Reset so we are clear when grab next line. */
      clear_buf_t(buf, 100);
	}

	/* Now concat all the words together. */
	for (i=0; words[i][0] != 0 && i < BUFSIZ; i++)
	{
		for (j=0; words[j][0] != 0 && j < BUFSIZ; j++)
		{
			/* add symbols --- asci 32-47 --->(space)!"#$%&'()*+,/ */
			for (k=32; k < 48; k++)
			{
				strcpy(combined, words[i]);
				last = strlen(combined);
				combined[last-1] = k;
				strcat(combined, words[j]);
				fprintf(fp_out, "%s", combined);
			}

			/* add symbols --- asci 58-64 ---> :;<=>?@ */
			for (k=58; k < 65; k++)
			{
				strcpy(combined, words[i]);
				last = strlen(combined);
				combined[last-1] = k;
				strcat(combined, words[j]);
				fprintf(fp_out, "%s", combined);
			}

			/* add symbols --- asci 91-96 ---> [\]^_` */
			for (k=91; k < 97; k++)
			{
				strcpy(combined, words[i]);
				last = strlen(combined);
				combined[last-1] = k;
				strcat(combined, words[j]);
				fprintf(fp_out, "%s", combined);
			}

			/* add symbols --- asci 123-126 ---> {|}~ */
			for (k=123; k < 127; k++)
			{
				strcpy(combined, words[i]);
				last = strlen(combined);
				combined[last-1] = k;
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
