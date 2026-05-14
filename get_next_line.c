/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapaydin <kapaydin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 15:38:08 by kapaydin          #+#    #+#             */
/*   Updated: 2026/05/14 12:18:49 by kapaydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_stash(int fd, char *stash)
{
	char	*buf;
	char	*tmp;
	int		bytes_read;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf);
			free(stash);
			return (NULL);
		}
		buf[bytes_read] = '\0';
		tmp = ft_strjoin(stash, buf);
		free(stash);
		stash = tmp;
	}
	free(buf);
	return (stash);
}

static char	*extract_line(char *stash)
{
	char	*line;
	char	*src;
	char	*dst;

	if (!stash || !*stash)
		return (NULL);
	src = stash;
	while (*src && *src != '\n')
		src++;
	if (*src == '\n')
		src++;
	line = (char *)malloc(sizeof(char) * (src - stash + 1));
	if (!line)
		return (NULL);
	dst = line;
	src = stash;
	while (*src && *src != '\n')
		*dst++ = *src++;
	if (*src == '\n')
		*dst++ = '\n';
	*dst = '\0';
	return (line);
}

static char	*get_from_remain(char *stash)
{
	char	*remaining;
	char	*ptr;

	ptr = stash;
	while (*ptr && *ptr != '\n')
		ptr++;
	if (!*ptr)
	{
		free(stash);
		return (NULL);
	}
	remaining = ft_strdup(ptr + 1);
	free(stash);
	if (!remaining)
		return (NULL);
	if (!*remaining)
	{
		free(remaining);
		return (NULL);
	}
	return (remaining);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	stash = read_and_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = get_from_remain(stash);
	return (line);
}
