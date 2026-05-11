/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapaydin <kapaydin@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 15:38:04 by kapaydin          #+#    #+#             */
/*   Updated: 2026/05/11 16:06:40 by kapaydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	const char	*s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	len;

	len = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (len)
	{
		dest[len] = s1[len];
		len--;
	}
	return (dest);
}

char	*ft_strchr(const char *str, int chr)
{
	char	c;

	c = (char)chr;
	while (*str != c)
	{
		if (!*str)
			return (NULL);
		str++;
	}
	return ((char *)str);
}

char	*ft_mini_split(const char *str, int chr)
{
	int		size;
	char	c;
	char	*line;

	size = 0;
	c = (char)chr;
	line = str;
	while (str != c)
	{
		str++;
		size++;
	}
	line[size + 1] = '\0';
	return (ft_strdup(line));
}