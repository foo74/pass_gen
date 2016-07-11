#include "pass_gen.h"

struct char_transform
{
   char from;
   char to;
};

int main(int argc, char *argv[])
{
	/* -h flag for help */
	/* -o flag for output file */
	int oflag = 0;
	char *ovalue = NULL;

	/* -i flag for input file */
	int iflag = 0;
	char *ivalue = NULL;

	/* -t flag for transform */
	int tflag = 0;

	int opt = 0;
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

   /* process options */
	while ((opt = getopt(argc, argv, "hti:o:")) != -1)
	{
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
			/* perform transform */
			case 't':
				tflag = 1;
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

	if (iflag == 0)
	{
		print_usage();
		return -1;
	}
	else if (oflag == 0)
	{
		print_usage();
		return -1;
	}
	

	//printf("\n\niflag = %d, ivalue = %s\n", iflag, ivalue);
	//printf("\n\noflag = %d, ovalue = %s\n", oflag, ovalue);

	if ( oflag )
	{
		build_input(ovalue);
	}

   if ( tflag == 1 )
   {
      for (i=0; i < MAX; i++)
      {
         replace_char(ivalue, ovalue, foo[i].from, foo[i].to);
         printf("pass_a: %d\n", i);
      }
      for (i=0; i < MAX; i++)
      {
         replace_char(ivalue, ovalue, foo[i].from, foo[i].to);
         printf("pass_b: %d\n", i);
      }
   }

   return 0;
}

void print_usage()
{
	printf("Usage: pass_gen [options] -i <input file> -o <output file>\n"
	"Options:\n"
	" -h		print help\n"
	" -t		transform input\n"
	"Examples:\n"
	"Project Page: https://github.com/foo74/pass_gen\n");
}
