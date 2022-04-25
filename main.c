#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int fd;
    char *str;

    fd = open("41_with_nl", O_RDONLY);
    str = get_next_line(fd);
    printf("%s\n", str);
    return 0;
}