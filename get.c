/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaophit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 02:45:54 by seng              #+#    #+#             */
/*   Updated: 2024/04/01 17:23:52 by plaophit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*player_pos(char **map, int *dimension)
{
	int	i;
	int	j;
	int	*pos;

	i = 0;
	pos = malloc(sizeof(int) * 2);
	while (i < dimension[0])
	{
		j = 0;
		while (j < dimension[1])
		{
			if (map[i][j] == 'P')
			{
				pos[1] = j;
				pos[0] = i;
			}
			j++;
		}
		i++;
	}
	return (pos);
}

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

int	get_map_size(char *str, t_num *p)
{
	int		fd;
	char	*buffer;

	p->dimensions[0] = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (ft_printf("cannot open"), 0);
	buffer = get_next_line(fd);
	p->dimensions[1] = ft_strlen_no_line(buffer);
	while (buffer != NULL)
	{
		p->dimensions[0]++;
		if (p->dimensions[1] != ft_strlen_no_line(buffer))
		{
			free(buffer);
			return (ft_printf("map not rectengle"), 0);
		}
		p->dimensions[1] = ft_strlen_no_line(buffer);
		free(buffer);
		buffer = get_next_line(fd);
	}
	close(fd);
	return (1);
}

void	get_map(char *str, t_num *p)
{
	int		fd;
	char	*buffer;
	int		i;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		exit(0);
	p->map = malloc(sizeof(char *) * (p->dimensions[1] + 1));
	i = 0;
	buffer = get_next_line(fd);
	while (buffer)
	{
		p->map[i] = buffer;
		draw_map(*p, p->map[i], i);
		buffer = get_next_line(fd);
		i++;
	}
	check(p->mlx, p->map, p->dimensions);
	close(fd);
}
