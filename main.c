#include "get_next_line.h"

int main(void)
{
    int     fd;
    void    *line;

    fd = open("./test1", O_RDWR);
    get_next_line(fd, &line);
    printf("%s\n", line);
    get_next_line(fd, &line);
    printf("%s\n", line);
    get_next_line(fd, &line);
    printf("%s\n", line);
    
    return (0);
}

