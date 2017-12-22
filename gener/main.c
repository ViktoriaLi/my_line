#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int fd;
	char *res;
	char *res1;
	char *res2;
	int lenk;
	if (argc == 1)
	{
		while (get_next_line(0, &res1, &lenk))
		{
			write(1, res1, lenk - 1);
			write(1, "\n", 1);
			free(res1);
		}
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			while (get_next_line(1, &res2, &lenk))
			{
				write(1, res2, lenk - 1);
				write(1, "\n", 1);
				free(res2);
			}
		}
		while (get_next_line(fd, &res, &lenk))
		{
			write(1, res, lenk - 1);
			write(1, "\n", 1);
			free(res);
		}
	}
}

/*
if (argc == 1)
	{
		while (get_next_line(0, &res1))
		{
			printf("%s\n", res1);
			free(res1);
		}
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			while (get_next_line(1, &res2))
			{
				printf("%s\n", res2);
				free(res2);
			}
		}
		else
			while (get_next_line(fd, &res))
			{
				printf("%s\n", res);
				free(res);
		}
	}
	*/