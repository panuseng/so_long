/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seng <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 02:57:27 by seng              #+#    #+#             */
/*   Updated: 2024/03/25 22:10:53 by seng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include "GNL/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include <stdio.h>

int		get_map_size(char *str, int *dimensions);
int		ft_strlen_no_line(const char *s);
void	draw_map(int *dimensions, void *mlx);

#endif
