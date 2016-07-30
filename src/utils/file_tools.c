#include "file_tools.h"
#include <stdio.h>
#include <string.h>

int file_exists(char file_to_check[])
{
   FILE *fp;

   fp = fopen(file_to_check, "r");
	if (fp != NULL)
   	fclose(fp);

	return (fp!=NULL);
}
