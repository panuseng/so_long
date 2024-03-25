/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seng <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:00:02 by seng              #+#    #+#             */
/*   Updated: 2024/03/26 00:32:51 by seng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(int *dimensions, void *mlx)
{
	int	x;
	int	y;

	xpm_t *xpm = mlx_load_xpm42("/Users/seng/Desktop/42/CG/so_long/Repo/ft_so_long/pic/floor.xpm42");
	mlx_image_t *img = mlx_texture_to_image(mlx, &xpm ->texture);
	x = 0;
	while (x < dimensions[1])
	{
		y = 0;
		while (y < dimensions[0])
		{
			ft_printf("x: %d, y: %d\n", x, y);
			mlx_image_to_window(mlx, img, x*32, y*32);
			y++;
		}
		x++;
	}
}
