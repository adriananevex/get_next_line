/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneves <aneves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:07:33 by aneves            #+#    #+#             */
/*   Updated: 2025/12/01 15:42:41 by aneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	str[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (str[0] == '\0')
		{
			n = read(fd, str, BUFFER_SIZE);
			if (n == -1)
				return (free(line), NULL);
			if (n == 0)
				return (line);
			str[n] = '\0';
		}
		line = ft_join_b(line, str);
		ft_left(str);
		if (ft_strchr(line, '\n'))
			return (line);
	}
}

/* #include <stdio.h>

int	main(void)
{
	int	fd;
	int	i;
	char	*line;

	fd = open("get_next_line_test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	i = 1;
	while ((line = get_next_line(fd)))
	{
		printf("Line [%d] %s", i, line);
		i++;
		free(line);
	}
	close(fd);
	return (0);
} */