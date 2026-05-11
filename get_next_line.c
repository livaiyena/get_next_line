/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapaydin <kapaydin@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 15:38:08 by kapaydin          #+#    #+#             */
/*   Updated: 2026/05/11 14:49:02 by kapaydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_from_remain(char	*remaining_data)
{

}


char	*get_next_line(int fd)
{
	static char	*remaining_data;

	remaining_data = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
}