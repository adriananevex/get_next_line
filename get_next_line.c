/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neves <neves@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:07:33 by aneves            #+#    #+#             */
/*   Updated: 2025/11/28 22:32:07 by neves            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_line(int fd, char *left, char *buffer)
{
	ssize_t	b_read;
	char	*tmp;

	if (left && ft_strchr(left, '\n'))
			return (left);
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

static char	*set_line(char *line)
{
	char	*left;
	ssize_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	left = ft_substr(line, i + 1, ft_strlen(line) - (i + 1));
	if (!left)
		return (NULL);
	if (*left == '\0')
	{
		free(left);
		left = NULL;
	}
	line[i + 1] = '\0';
	return (left);
}

char	*get_next_line(int fd)
{
	static char	*left;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(left);
		free(buffer);
		left = NULL;
		buffer = NULL;
		return (NULL);
	}
	line = fill_line(fd, left, buffer);
	if (!line)
	{
		free(left);
		left = NULL;
		return (NULL);
	}
	free(buffer);
	buffer = NULL;
	left = set_line(line);
	return (line);
}
