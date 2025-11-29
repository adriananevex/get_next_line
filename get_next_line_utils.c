/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneves <aneves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:07:37 by aneves            #+#    #+#             */
/*   Updated: 2025/11/29 19:38:10 by aneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *str)
{
	char	*buffer;
	char	*tmp;
	ssize_t	n;

	if (!str)
		str = ft_substr("", 0, 0);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(str, '\n'))
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n <= 0)
			break ;
		buffer[n] = '\0';
		tmp = str;
		str = ft_strjoin(tmp, buffer);
		if (!str)
			return (free(buffer), free(tmp), NULL);
	}
	free(buffer);
	if (!*str)
		return (free(str), NULL);
	return (str);
}

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	unsigned char	d;
	size_t			i;

	i = 0;
	d = (unsigned char)c;
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

char	*ft_substr(const char *str, size_t start, size_t len)
{
	size_t	atual_len;
	char	*sub;
	size_t	i;

	if (!str)
		return (NULL);
	if (start >= ft_strlen(str))
	{
		len = 0;
	}
	if (len > ft_strlen(str + start))
		atual_len = ft_strlen(str + start);
	else
		atual_len = len;
	sub = (char *)malloc((atual_len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < atual_len)
	{
		sub[i] = str[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*copy;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	copy = malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
	if (!copy)
		return (free(s1), NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		copy[i + j] = s2[j];
		j++;
	}
	copy[i + j] = '\0';
	free(s1);
	return (copy);
}
