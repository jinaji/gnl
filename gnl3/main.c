#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int fd;
    char *str;

    fd = open("test.txt", O_RDONLY);
    {
        printf("---------------------------------\n\n");
        str = get_next_line(fd);
        printf("main %s\n", str);
        printf("---------------------------------\n\n");
        str = get_next_line(fd);
        printf("main %s\n", str);
        printf("---------------------------------\n\n");
         str = get_next_line(fd);
        printf("main %s\n", str);
 /*          printf("---------------------------------\n\n");
       str = get_next_line(fd);
        printf("main %s\n", str);
        str = get_next_line(fd);
        printf("main %s\n", str);*/
    }
    return 0;
}