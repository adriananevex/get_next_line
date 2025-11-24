#include "get_next_line.h"

static char  *fill_line(int fd, char *left, char *buffer)
{
    ssize_t b_read;
    char    *tmp;

    b_read = 1;
    while (b_read > 0)
    {
        b_read = read(fd, buffer, BUFFER_SIZE);
        if (b_read == -1)
            return (NULL);
        else if (b_read == 0)
            break ;
        buffer[b_read] = 0;
        if (!left)
            left = ft_strdup("");
        tmp = left;
        left = ft_strjoin(tmp, buffer);
        free(tmp);
        tmp = NULL;
        if (ft_strchr(buffer, '\n'))
            break ;
    }
    return (left);
}

static char  *set_line(char *line)
{
    char    *left;
    ssize_t i;

    i = 0;
    while(line[i] != '\n' && line[i] != '\0')
        i++;
    if (line[i] == 0 || line[1] == 0)
        return (NULL);
    left = ft_ft_substr(line, i + 1, ft_strlen(line) - i);
    if (*left == 0)
    {
        free(left);
        left = NULL;
    }
    line[i + 1] = 0;
    return (left);
}

char  *get_next_line(int fd)
{
    static char *left;
    char        *line;
    char        *buffer;

    buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
    return (NULL);
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
    {
        free(left);
        free(buffer);
        left = NULL;
        buffer = NULL;
        return (NULL);
    }
    line = fill_line(fd, left, buffer);
    free(buffer);
    buffer = NULL;
    if (!line)
    {
        free(left);
        left = NULL;
        return (NULL);
    }
    left = set_line(line);
    return (line);
}
