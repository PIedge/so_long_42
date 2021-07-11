/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 18:39:44 by tmerrien          #+#    #+#             */
/*   Updated: 2021/07/04 13:35:32 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"
#include "../includes/get_next_line.h"
#include <stdlib.h>

int	set_pos(t_pos *set, int x, int y)
{
	set->x = (double)x;
	set->y = (double)y;
	return (1);
}

t_map	*init_map(void)
{
	t_map	*ret;

	ret = malloc(sizeof(t_map));
	if (!ret)
		return (0);
	ret->next = 0;
	ret->prev = 0;
	return (ret);
}

int	check_app(t_sl *sl, t_map *map, int *yes)
{
	double	tmp;
	char	*line;

	tmp = -1;
	line = map->line;
	while (++tmp < map->length)
	{
		if (*line == 'P')
		{
			if (*yes == 1)
				exit_sl(10, sl);
			sl->player.pos.x = tmp;
			sl->player.pos.y = (double)map->y;
			*line = 48;
			*yes = 1;
			return (0);
		}
		++line;
	}
	return (1);
}

int	set_tmp(t_sl *sl, t_map *tmp, int fd, int *ret)
{
	int	y;
	int	yes;

	yes = 0;
	y = 0;
	while (1)
	{
		tmp->length = (int)ft_strlen(tmp->line);
		tmp->y = y++;
		check_app(sl, tmp, &yes);
		tmp->next = malloc(sizeof(t_map));
		if (!(tmp->next))
			return (0);
		tmp->next->prev = tmp;
		tmp = tmp->next;
		tmp->line = 0;
		tmp->y = -1;
		tmp->length = 0;
		tmp->next = 0;
		if (*ret == 0)
			break ;
		*ret = get_next_line(fd, &tmp->line);
	}
	tmp->y = y;
	return (y);
}

/*void	map_it(t_sl *sl)
{
	sl->map_tab[sl->map->y] = malloc(sizeof(char) * (sl->map->length + 1));
	if (!(sl->map_tab[sl->map->y]))
		exit_sl(1, sl);
	ft_memcpy(sl->map_tab[sl->map->y], sl->map->line,
		sl->map->length + 1);
	sl->map = sl->map->next;
}*/
