/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapaydin <kapaydin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 15:38:04 by kapaydin          #+#    #+#             */
/*   Updated: 2026/05/14 02:16:48 by kapaydin         ###   ########.fr       */
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
	char	*d;
	size_t	len;

	len = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	d = dest;
	while (*s1)
		*d++ = *s1++;
	*d = '\0';
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

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	char	*ptr;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!str)
		return (NULL);
	ptr = str;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (str);
}
