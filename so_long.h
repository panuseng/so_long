/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaophit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 02:57:27 by seng              #+#    #+#             */
/*   Updated: 2024/04/01 17:09:04 by plaophit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include "GNL/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdbool.h>

typedef struct s_num
{
	void	*mlx;
	char	**map;
	int		dimensions[2];
	int		collect;
	int		move;
	int		mode;
}	t_num;

int		get_map_size(char *str, t_num *p);
int		ft_strlen_no_line(const char *s);
int		wall_check(char **map, int *dimension);
int		one_check(char **map, int *dimension, int i);
void	draw_map(t_num p, char *map, int x);
void	get_map(char *str, t_num *p);
int		*player_pos(char **map, int *dimension);
void	error_output(void *mlx, int error);
int		key_check(t_num p, char key);
void	check(void *mlx, char **map, int *dimensions);
void	ft_hook(void *param);
void	my_keyhook(mlx_key_data_t keydata, void *param);
void	ft_go_up(t_num *p);
void	ft_go_down(t_num *p);
void	ft_go_left(t_num *p);
void	ft_go_right(t_num *p);
void	pass_check(t_num *p);
void	ft_draw(t_num p, int i);


#endif
