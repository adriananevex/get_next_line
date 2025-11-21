#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

size_t  ft_strlen(const char *str);

char    *get_next_line(int fd);
char    *ft_strdup(const char *str);
char    *ft_strchr(char *str, int c);
char    *ft_strjoin(char *s1, const char *s2);
char    *ft_ft_substr(const char *str, size_t start, size_t len);

#endif
