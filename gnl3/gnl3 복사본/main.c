#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int fd;
    char *str;

  str = "1";
    fd = open("test.txt", O_RDONLY);
    while (str)
    {
      str = get_next_line(fd);
      printf("%s\n", str);
    }
   // system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
    return 0;
}