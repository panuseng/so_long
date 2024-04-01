/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaophit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:51:56 by plaophit          #+#    #+#             */
/*   Updated: 2024/04/01 17:23:31 by plaophit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_go_up(t_num *p)
{
	int	x;
	int	y;

	y = player_pos(p->map, p->dimensions)[1];
	x = player_pos(p->map, p->dimensions)[0];
	if (((x - 1) < p->dimensions[0] && (x - 1) >= 0) \
		&& p->map[x - 1][y] != '1' && p->map[x - 1][y] != 'E')
	{
		p->map[x][y] = '0';
		p->map[x - 1][y] = 'P';
		if (p->map[x][y] == 'C')
		{
			pass_check(p);
			p->map[x][y] = '0';
		}
		else
			ft_draw(*p, 0);
		p->move++;
	}
	ft_printf("Move: %d\n", p->move);
}

void	ft_go_down(t_num *p)
{
	int	x;
	int	y;

	y = player_pos(p->map, p->dimensions)[1];
	x = player_pos(p->map, p->dimensions)[0];
	if (((x + 1) < p->dimensions[0] && (x + 1) >= 0) \
		&& p->map[x + 1][y] != '1' && p->map[x + 1][y] != 'E')
	{
		p->map[x][y] = '0';
		p->map[x + 1][y] = 'P';
		if (p->map[x][y] == 'C')
		{
			pass_check(p);
			p->map[x][y] = '0';
		}
		else
			ft_draw(*p, 0);
		p->move++;
	}
	ft_printf("Move: %d\n", p->move);
}

void	ft_go_left(t_num *p)
{
	int	x;
	int	y;

	y = player_pos(p->map, p->dimensions)[1];
	x = player_pos(p->map, p->dimensions)[0];
	if (((y - 1) < p->dimensions[1] && (y - 1) >= 0) \
		&& p->map[x][y - 1] != '1' && p->map[x][y - 1] != 'E')
	{
		p->map[x][y] = '0';
		p->map[x][y - 1] = 'P';
		if (p->map[x][y] == 'C')
		{
			pass_check(p);
			p->map[x][y] = '0';
		}
		else
			ft_draw(*p, 0);
		p->move++;
	}
	ft_printf("Move: %d\n", p->move);
}

void	ft_go_right(t_num *p)
{
	int	x;
	int	y;

	y = player_pos(p->map, p->dimensions)[1];
	x = player_pos(p->map, p->dimensions)[0];
	if (((y + 1) < p->dimensions[1] && (y + 1) >= 0) \
		&& p->map[x][y + 1] != '1' && p->map[x][y + 1] != 'E')
	{
		if (p->map[x][y + 1] == 'C')
		{
			p->map[x][y + 1] = 'P';
			p->map[x][y] = '0';
			pass_check(p);
		}
		else
		{
			p->map[x][y + 1] = 'P';
			p->map[x][y] = '0';
			ft_draw(*p, 0);
		}
		p->move++;
	}
	ft_printf("Move: %d\n", p->move);
}

void	pass_check(t_num *p)
{
	p->collect = key_check(*p, 'C');
	if (p->collect != 0)
	{
		p->mode = 1;
		ft_printf("You need to collect all the keys\n");
		ft_printf("Key: %d\n", p->collect);
		ft_draw(*p, 0);
	}
	else
		ft_draw(*p, 0);
}
