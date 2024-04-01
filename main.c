/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaophit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 22:08:19 by seng              #+#    #+#             */
/*   Updated: 2024/04/01 17:07:17 by plaophit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_num	p;

	p.collect = 0;
	p.move = 0;
	p.mode = 0;
	(void)argc;
	if (argc != 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (!get_map_size(argv[1], &p))
	{
		ft_printf("Error\n");
		return (0);
	}
	p.mlx = mlx_init(p.dimensions[1] * 32, p.dimensions[0] * 32,\
						"So_long", true);
	get_map(argv[1], &p);
	ft_printf("key: %d\n",key_check(p, 'C'));
	mlx_loop_hook(p.mlx, ft_hook, p.mlx);
	mlx_key_hook(p.mlx, &my_keyhook, &p);
	mlx_loop(p.mlx);
}

void	error_output(void *mlx, int error)
{
	if (error == 'C')
		ft_printf("Component Error\n");
	if (error == '1')
		ft_printf("Component Num Error\n");
	if (error == 'W')
		ft_printf("Wall Check Error\n");
	mlx_close_window(mlx);
}
