/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaophit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:00:02 by seng              #+#    #+#             */
/*   Updated: 2024/04/01 17:08:26 by plaophit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_num p, char *map, int x)
{
	int			y;
	xpm_t		*xpm;
	mlx_image_t	*img;

	y = 0;
	while (y < p.dimensions[1])
	{
		if (map[y] == '1')
			xpm = mlx_load_xpm42("/Users/seng/Desktop/42/CG/so_long/Repo/ft_so_long/pic/wall.xpm42");
		else if (map[y] == '0')
			xpm = mlx_load_xpm42("/Users/seng/Desktop/42/CG/so_long/Repo/ft_so_long/pic/floor.xpm42");
		else if (map[y] == 'P')
			xpm = mlx_load_xpm42("/Users/seng/Desktop/42/CG/so_long/Repo/ft_so_long/pic/Center.xpm42");
		else if (map[y] == 'E' && p.mode == 1)
			xpm = mlx_load_xpm42("/Users/seng/Desktop/42/CG/so_long/Repo/ft_so_long/pic/closed.xpm42");
		else if (map[y] == 'E' && p.mode == 0)
			xpm = mlx_load_xpm42("/Users/seng/Desktop/42/CG/so_long/Repo/ft_so_long/pic/open.xpm42");
		else if (map[y] == 'C')
			xpm = mlx_load_xpm42("/Users/seng/Desktop/42/CG/so_long/Repo/ft_so_long/pic/Key.xpm42");
		else
			error_output(p.mlx, 'C');
		img = mlx_texture_to_image(p.mlx, &xpm ->texture);
		mlx_image_to_window (p.mlx, img, y * 32, x * 32);
		y++;
	}
}

void	ft_hook(void *param)
{
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_num	*p;

	p = (t_num *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_REPEAT)
		mlx_close_window(param);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		ft_go_up(p);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		ft_go_down(p);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		ft_go_left(p);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		ft_go_right(p);
	pass_check(p);
}

void	ft_draw(t_num p, int i)
{
	while (i < p.dimensions[0])
	{
		if (p.mode == 1)
			draw_map(p, p.map[i], i);
		else
			draw_map(p, p.map[i], i);
		i++;
	}
}
