#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int fd;
	char *res;
	char *res1;
	char *res2;
	if (argc == 1)
	{
		while (get_next_line(0, &res1))
		{
			printf("MAIN1 %s\n", res1);
			//free(res1);
		}
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			while (get_next_line(1, &res2))
			{
				printf("MAIN2 %s\n", res2);
				//free(res2);
			}
		}
		else
			while (get_next_line(fd, &res))
			{
				printf("MAIN3 %s\n", res);
				//free(res);
		}
	}
}

/*
#include <project.h>

static void simple_string(t_test *test)
{
	char *line;
	int		out;
	int		p[2];
	int		fd;
	int		gnl_ret;

	fd = 1;
	out = dup(fd);
	pipe(p);
	dup2(p[1], fd);
	write(fd, "aaa", 3);
	close(p[1]);
	dup2(out, fd);
	gnl_ret = get_next_line(p[0], &line);
	mt_assert(strcmp(line, "aaa") == 0);
	mt_assert(gnl_ret == 0 || gnl_ret == 1);
}

void	suite_02_test_eof_with_close(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_string);
}

*/
