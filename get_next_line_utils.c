/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneves <aneves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:07:37 by aneves            #+#    #+#             */
/*   Updated: 2025/11/26 20:38:11 by aneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strdup(const char *str)
{
	int		i;
	char	*copy;

	i = 0;
	copy = malloc(ft_strlen(str) + 1 * sizeof(char));
	if (!copy)
		return (NULL);
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_substr(const char *str, size_t start, size_t len)
{
	size_t	atual_len;
	char	*sub;
	size_t	i;

	if (!str)
		return (NULL);
	if (start >= ft_strlen(str))
		return (ft_strdup(""));
	if (len > ft_strlen(str + start))
		atual_len = ft_strlen(str + start);
	else
		atual_len = len;
	sub = (char *)malloc(atual_len + 1 * sizeof(char));
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
