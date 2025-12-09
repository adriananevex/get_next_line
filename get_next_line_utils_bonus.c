#include "get_next_line_bonus.h"

char    *ft_loop(int fd, char *str, char *line)
{
    ssize_t b;

    while (1)
    {
        if (str[0] == '\0')
        {
            b = read(fd, str, BUFFER_SIZE);
            if (b == -1)
                return (free(line), NULL);
            if (b == 0)
                return(line);
            str[b] = '\0';
        }
        line = ft_join_b(line, str);
        ft_set(str);
        if (ft_strchr(line, '\n'))
            return (line);
    }
}

char    *ft_join_b(char *line, char *str)
{
    size_t i;
    size_t  j;
    size_t  len_l;
    size_t  len_s;
    char    *new;

    len_l = ft_strlen_b(line);
    len_s = ft_strlen_b(str);
    new = malloc(len_l + len_s + 1);
    if (!new)
        return(free(line), NULL);
    i = 0;
    while (i < len_l)
    {
        new[i] = line[i];
        i++;
    }
    j = 0;
    while (j < len_s)
        new[i++] = str[j++];
    new[i] = '\0';
    free(line);
    return (new);
}

void    ft_set(char *str)
{
    size_t  i;
    size_t  j;

    if (!str)
        return ;
    j = 0;
    i = ft_strlen_b(str);
    while (str[i])
        str[j++] = str[i++];
    str[j] = '\0';
}

size_t  ft_strlen_b(const char *str)
{
    int i;

    i = 0;
    if(!str)
        return (0);
    while (str[i] != '\0' && str[i] != '\n')
        i++;
    if (str[i] == '\n')
        i++;
    return (i);
}

char	*ft_strchr(char *str, int c)
{
	unsigned char	d;
	size_t			i;

	i = 0;
	d = (unsigned char)c;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if ((unsigned char)str[i] == d)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == d)
		return ((char *)&str[i]);
	return (NULL);
}
