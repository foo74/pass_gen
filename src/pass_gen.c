#include "pass_gen.h"

struct char_transform
{
   char from;
   char to;
};

int main(int argc, char *argv[])
{

	/* -o flag for output file */
	int oflag = 0;
	char *ovalue = NULL;

	/* -i flag for input file */
	int iflag = 0;
	char *ivalue = NULL;

	/* -h flag for help */
	int hflag = 0;
	char *hvalue = NULL;

	/* external opterr to see if option errors, from getopt() 
	 * set opterr to 0, we will handle the '?' case.
	 */
//	opterr = 0;
	int opt = 0;

   const int MAX = 5;
   int transform = 0;
   int usage = 0;
   int i = 0;
   struct char_transform foo[MAX];

   char source_file[] = "input";
   char dest_file[] = "output";
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
	if (argc == 1)
		build_input();
*/

	while ((opt = getopt(argc, argv, "hi:o:")) != -1)
	{
		switch (opt)
		{
			case 'i':
				iflag = 1;
				ivalue = optarg;
				break;
			case 'o':
				oflag = 1;
				ovalue = optarg;
				break;
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

	printf("\n\niflag = %d, ivalue = %s\n", iflag, ivalue);
	printf("\n\noflag = %d, ovalue = %s\n", oflag, ovalue);

   /* process options */
/*
   for (i=1; i<argc; i++)
   {
      if (strstr(argv[i], "-h") != NULL)
         usage = 1;
      else if (strstr(argv[i], "-t") != NULL)
         transform = 1;
      else if (strstr(argv[i], "-i") != NULL)
         input_file = 1;
      else if (strstr(argv[i], "-o") != NULL)
         output_file = 1;
   }

	if ( usage)
		print_usage();
*/

/*
   if ( transform )
   {
      for (i=0; i < MAX; i++)
      {
         replace_char(source_file, dest_file, foo[i].from, foo[i].to);
         printf("pass_a: %d\n", i);
      }
      for (i=0; i < MAX; i++)
      {
         replace_char(dest_file, dest_file, foo[i].from, foo[i].to);
         printf("pass_b: %d\n", i);
      }
   }
*/

   return 0;
}

void print_usage()
{
	printf("\n\nUsage: pass_gen -a -i <input file> -o <output file>\n\n");
	printf("-a transform a's to @'s.\n\n");
}
