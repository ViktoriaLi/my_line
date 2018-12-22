#include "get_next_line.h"
#include <stdio.h>

int main()
{
  char *buf;
  int fd = open("test", O_RDONLY);
  while (get_next_line(0, &buf))
  {
    printf("%s\n", buf);
    free(buf);
  }
  return (0);
}
