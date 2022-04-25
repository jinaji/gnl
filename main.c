#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int fd;
    char *str;

    fd = open("41_no_nl", O_RDONLY);
    str = get_next_line(fd);
    printf("%s\n", str);
    while (1)
    {

        
    }
    return 0;
}