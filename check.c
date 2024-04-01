/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaophit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 07:00:50 by seng              #+#    #+#             */
/*   Updated: 2024/04/01 13:40:39 by plaophit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	one_check(char **map, int *dimension, int i)
{
	int	j;
	int	check[3];

	i = 0;
	check[0] = 0;
	check[1] = 0;
	check[2] = 0;
	while (i < dimension[0])
	{
		j = 0;
		while (j < dimension[1])
		{
			if (map[i][j] == 'C')
				check[0]++;
			if (map[i][j] == 'E')
				check[1]++;
			if (map[i][j] == 'P')
				check[2]++;
			j++;
		}
		i++;
	}
	if (check[0] == 0 || check[1] == 0 || check[2] == 0)
		return (0);
	return (1);
}

int	wall_check(char **map, int *dimension)
{
	int		i;
	int		j;

	i = 0;
	while (i < dimension[0])
	{
		j = 0;
		while (i == (dimension[0] - 1) || i == 0)
		{
			while (j < dimension[1])
			{
				if (map[i][j] != '1')
					return (0);
				j++;
			}
			i++;
		}
		if (map[0][0] != '1' || map[0][dimension[1] - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	key_check(t_num p, char key)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	check = 0;
	while (i < p.dimensions[0])
	{
		j = 0;
		while (j < p.dimensions[1])
		{
			if (p.map[i][j] == key)
				check++;
			j++;
		}
		i++;
	}
	return (check);
}

void	check(void *mlx, char **map, int *dimensions)
{

	if (one_check(map, dimensions, 0) == 0)
		error_output(mlx, '1');
	if (wall_check(map, dimensions) == 0)
		error_output(mlx, 'W');
}
