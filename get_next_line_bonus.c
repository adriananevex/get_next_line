#include "get_next_line_bonus.h"

char    *get_next_line(int fd)
{
    static char *str[FD_MAX];
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FD_MAX)
        return (NULL);
    if (!str[fd])
    {
        str[fd] = malloc(BUFFER_SIZE + 1);
        if (!str[fd])
            return (NULL);
        str[fd][0] = '\0';
    }
    line = ft_loop(fd, str[fd], NULL);
    if (!line)
    {
        free(str[fd]);
        str[fd] = NULL;
    }
    return (line);
}

/* #include <stdio.h>

int main(void)
{
    int fd1, fd2, fd3;
    char    *line;

    fd1 = open("text1.txt", O_RDONLY);
    fd2 = open("text2.txt", O_RDONLY);
    fd3 = open("text3.txt", O_RDONLY);

    if (fd1 < 0 || fd2 < 0 || fd3 < 0)
    {
        perror("open");
        return (1);
    }
    while (1)
    {
        int ended = 0;

        line = get_next_line(fd1);
        if (line)
        {
            printf("[FD1] %s \n", line);
            free(line);
        }
        else
            ended++;
        line = get_next_line(fd2);
        if (line)
        {
            printf("[FD2] %s\n", line);
            free(line);
        }
        else
            ended++;
        line = get_next_line(fd3);
        if (line)
        {
            printf("[FD3] %s\n", line);
            free(line);
        }
        else
            ended++;
        if (ended == 3)
            break ;
    }
    close(fd1);
    close(fd2);
    close(fd3);
    return (0);
} */