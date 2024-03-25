/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seng <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 22:08:19 by seng              #+#    #+#             */
/*   Updated: 2024/03/25 23:49:50 by seng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	int dimensions[2];

	(void)argc;
	if (!get_map_size(argv[1], dimensions))
	{
		ft_printf("Error\n");
		return (0);
	}

	int window_height = dimensions[0] * 32;
	int window_width = dimensions[1] * 32;
	
	ft_printf("width: %d, height: %d\n", window_width, window_height);
	mlx = mlx_init(window_width, window_height, "Hello world!", true);
	draw_map(dimensions, mlx);
	mlx_loop(mlx);
}
