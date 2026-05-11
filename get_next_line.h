/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapaydin <kapaydin@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 15:38:11 by kapaydin          #+#    #+#             */
/*   Updated: 2026/05/11 14:49:35 by kapaydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int chr);
char	*ft_mini_split(const char *str, int chr);

#endif