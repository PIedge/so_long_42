/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_return_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 08:15:40 by tmerrien          #+#    #+#             */
/*   Updated: 2021/07/11 19:02:41 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"
#include "../includes/get_next_line.h"
#include "../includes/mlx.h"
#include <fcntl.h>
#include <stdio.h>
#include <math.h>

#include <stdio.h>

static void	p_key(t_sl *sl, int x, int y, int *yes)
{
	++(*yes);
	set_pos(&sl->player.pos, x, y);
	(sl->map_tab)[y][x] = '0';
}

static void	ennemy_add(t_sl *sl, int x, int y)
{
	(sl->map_tab)[y][x] = '0';
	if (!(sl->mob))
	{
		sl->mob = new_mob(0, x, y);
		if (!(sl->mob))
			exit_sl(1, sl);
	}
	else if (sl->mob)
	{
		sl->mob->next = new_mob(sl->mob, x, y);
		if (!(sl->mob))
			exit_sl(1, sl);
		sl->mob = sl->mob->next;
	}
}

static void	in_while(t_sl *sl, int x, int y, int *yes)
{
	char	c;

	c = (sl->map_tab)[y][x];
	if (c != '1' && c != '0' && c != 'C' && c != 'E' && c != 'P' && c != 'X')
		exit_sl(4, sl);
	if (c == 'P')
		p_key(sl, x, y, yes);
	else if (c == 'C')
		sl->collectibles += 1;
	else if (c == 'E')
		sl->exit = 1;
	else if (c == 'X')
		ennemy_add(sl, x, y);
}

t_uint	check_line_map(t_sl *sl, int *yes, int y, int len_base)
{
	int		x;
	char	**map;

	x = 1;
	map = sl->map_tab;
	if (map[y][0] != '1' || (int)ft_strlen(map[y]) != len_base || \
		map[y][len_base - 1] != '1')
		exit_sl(4, sl);
	while (x < len_base - 1)
	{
		in_while(sl, x, y, yes);
		++x;
	}
	return (1);
}
