/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_return.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 08:15:40 by tmerrien          #+#    #+#             */
/*   Updated: 2021/07/04 13:35:52 by tmerrien         ###   ########.fr       */
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

t_uint	check_line_map(t_sl *sl, int *yes, int y, int len_base)
{
	int		x;
	char	c;
	char	**map;

	x = 1;
	map = sl->map_tab;
	if (map[y][0] != '1' || (int)ft_strlen(map[y]) != len_base || \
		map[y][len_base - 1] != '1')
		exit_sl(4, sl);
	while (x < len_base - 1)
	{
		c = map[y][x];
		if (c != '1' && c != '0' && c != 'C' && c != 'E' && c != 'P')
			exit_sl(4, sl);
		if (c == 'P')
			p_key(sl, x, y, yes);
		if (c == 'C')
			sl->collectibles += 1;
		if (c == 'E')
			sl->exit = 1;
		++x;
	}
	return (1);
}
