#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int fd;
    char *str;

    fd = open("test.txt", O_RDONLY);
    str = "1";
    while (str)
    {
        str = get_next_line(fd);
        printf("%s\n", str);
    }
    return 0;
}