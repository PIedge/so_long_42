/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrols_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 10:40:54 by tmerrien          #+#    #+#             */
/*   Updated: 2021/07/11 19:11:06 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static int	compare_pos(t_mob *mob, char **map, int x, int y)
{
	while (mob->prev)
		mob = mob->prev;
	if (map[y][x] != '0')
		return (0);
	while (mob)
	{
		if (mob->pos.x == x && mob->pos.y == y)
			return (0);
		mob = mob->next;
	}
	return (1);
}

void	patrols(t_sl *sl, char **map)
{
	t_mob	*mob;

	mob = sl->mob;
	if (!mob)
		return ;
	while (mob->prev)
		mob = mob->prev;
	while (mob)
	{
		if (compare_pos(sl->mob, map, mob->pos.x, mob->pos.y + 1))
			set_pos(&mob->pos, (int)mob->pos.x, (int)mob->pos.y + 1);
		else if (compare_pos(sl->mob, map, mob->pos.x, mob->pos.y - 1))
			set_pos(&mob->pos, (int)mob->pos.x, (int)mob->pos.y - 1);
		else if (compare_pos(sl->mob, map, mob->pos.x + 1, mob->pos.y))
			set_pos(&mob->pos, (int)mob->pos.x + 1, (int)mob->pos.y);
		else if (compare_pos(sl->mob, map, mob->pos.x - 1, mob->pos.y))
			set_pos(&mob->pos, (int)mob->pos.x - 1, (int)mob->pos.y);
		mob = mob->next;
	}
}
