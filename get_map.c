/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seng <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 02:45:54 by seng              #+#    #+#             */
/*   Updated: 2024/03/26 00:56:58 by seng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_no_line(const char *s)
{
	int	i;

	if (*s == '\0' || s == NULL)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		i++;
	}
	return (i);
}

int	get_map_size(char *str, int *dimensions)
{
	int		fd;
	char	*buffer;

	dimensions[0] = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (ft_printf("cannot open"), 0);
	buffer = get_next_line(fd);
	dimensions[1] = ft_strlen_no_line(buffer);
	while (buffer != NULL)
	{
		dimensions[0]++;
		if (dimensions[1] != ft_strlen_no_line(buffer))
		{
			free(buffer);
			return (ft_printf("map not rectengle"), 0);
		}
		dimensions[1] = ft_strlen_no_line(buffer);
		free(buffer);
		buffer = get_next_line(fd);
	}
	close(fd);
	return (1);
}
