#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "pass_gen.h"
#include "utils/buffer_tools.h"
#include "utils/build_input.h"
#include "utils/file_tools.h"
#include "transforms/characters.h"
#include "transforms/numbers.h"


/* private print_usage function */
static void print_usage();

int main(int argc, char *argv[])
{
	/* -h flag for help */
	/* -o flag for output file */
	int oflag = 0;
	char *ovalue = NULL;

	/* -i flag for input file */
	int iflag = 0;
	char *ivalue = NULL;

	/* -q flag for questions file */
	int qflag = 0; char *qvalue = NULL;

	int opt = 0;

   /* process options */
	while ((opt = getopt(argc, argv, "hioq:")) != -1) {
		switch (opt)
		{
			/* input file */
			case 'i':
				iflag = 1;
				ivalue = optarg;
				break;
			/* output file */
			case 'o':
				oflag = 1;
				ovalue = optarg;
				break;
			/* questions file */
			case 'q':
				qflag = 1;
				qvalue = optarg;
				//printf("\nqvalue is: %s\n", qvalue);
				break;
			/* h flag or error then print usage */
			case '?':
			case 'h':
				print_usage();
				return 1;
			default:
				print_usage();
				return 1;
		}
	}

	/* Set values based in arguments. */
	if ( !oflag )
		ovalue = "myoutput";

	if ( !qflag )
	{
		qvalue = "../share/pass_gen/questions";
		if (!file_exists(qvalue))
		{
			printf("\nDefault questions file: %s\n", qvalue);
			printf("\nFile not found! Try using -q flag.\n\n");
			return -1;
		}
	}

	if ( !iflag )
		ivalue = "custom_input";

	/* Build an input file of words if not specified. */
	build_input(qvalue, ivalue);
	replace_chars(ivalue, ovalue);
	append_numbers(ovalue, "output_numbers");
	prepend_numbers(ovalue, "output_numbers2");
	concat_with_numbers(ivalue, "output_concat");

   return 0;
}

static void print_usage()
{
	printf("Usage: pass_gen [options]\n"
	"Options:\n"
	" -h		print help\n"
	" -i		input file\n"
	" -o		output file\n"
	" -t		transform input\n"
	" -q		custom questions file\n\n"
	"Examples:\n"
	"To run using default input and output files.\n"
	"pass_gen -t\n\n"
	"To run with specifying a custom words list and custom output file.\n"
	"pass_gen -t -i mywords -o myoutput\n\n"
	"To run with a custom questions file.\n"
	"pass_gen -t -q myquestions\n\n"
	"Project Page: https://github.com/foo74/pass_gen\n");
}
