/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 21:09:56 by tmerrien          #+#    #+#             */
/*   Updated: 2021/07/11 19:39:11 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

void	step_on_mob(t_sl *sl, t_pos pos)
{
	t_mob	*mob;

	mob = sl->mob;
	if (!mob)
		return ;
	while (mob->prev)
		mob = mob->prev;
	while (mob)
	{
		if (mob->pos.x == pos.x && mob->pos.y == pos.y)
			finish(sl, "You lose\n");
		mob = mob->next;
	}
}

t_mob	*new_mob(t_mob *prev, int x, int y)
{
	t_mob	*ret;

	ret = malloc(sizeof(t_mob));
	if (!ret)
		return (0);
	ret->next = NULL;
	ret->prev = prev;
	set_pos(&ret->pos, x, y);
	return (ret);
}

void	draw_mob(t_sl *sl)
{
	t_mob	*mob;

	mob = sl->mob;
	if (!mob)
		return ;
	while (mob->prev)
		mob = mob->prev;
	while (mob)
	{
		draw_texture(sl, &sl->ennemy_tex, mob->pos);
		mob = mob->next;
	}
}
