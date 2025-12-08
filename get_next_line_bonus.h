#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#   define BUFFER_SIZE 14
# endif

# ifndef FD_MAX
#   define FD_MAX 1024
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char    *get_next_line(int fd);

char    *ft_strchr(char *str, int c);
char    *ft_join_b(char *line, char *str);
char    *ft_loop(int fd, char *str, char *line);

size_t  ft_strlen_b(const char *str);

void    ft_set(char *str);

#endif