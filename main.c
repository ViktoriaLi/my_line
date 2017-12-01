#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int fd;
	char *res;

	//fd = open(argv[1], O_RDONLY);
	fd = 0;
	while (get_next_line(fd, &res))
	{
		printf("%s\n", res);
		free(res);
	}	
}