/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneves <aneves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:07:37 by aneves            #+#    #+#             */
/*   Updated: 2025/12/03 21:12:30 by aneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join_b(char *line, char *str)
{
	char	*new;
	size_t	i;
	size_t	j;
	size_t	len_l;
	size_t	len_s;

	len_l = ft_strlen_b(line);
	len_s = ft_strlen_b(str);
	new = malloc(len_l + len_s + 1);
	if (!new)
		return (free(line), NULL);
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

void	ft_left(char *str)
{
	size_t	i;
	size_t	j;

	if (!str)
		return ;
	i = ft_strlen_b(str);
	j = 0;
	while (str[i])
		str[j++] = str[i++];
	str[j] = '\0';
}

size_t	ft_strlen_b(const char *c)
{
	size_t	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i] != '\n' && c[i] != '\0')
		i++;
	if (c[i] == '\n')
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
