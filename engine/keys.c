/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 19:06:46 by tmerrien          #+#    #+#             */
/*   Updated: 2021/07/11 19:47:26 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"
#include "../includes/mlx.h"
#include <stdlib.h>

#include <stdio.h>

static int	change_pos(int keycode, t_sl *sl, t_pos *pos)
{
	if (keycode == sl->keymap.down)
	{
		pos->y += 1;
		return (1);
	}
	else if (keycode == sl->keymap.up)
	{
		pos->y += -1;
		return (1);
	}
	else if (keycode == sl->keymap.right)
	{
		pos->x += 1;
		return (1);
	}
	else if (keycode == sl->keymap.left)
	{
		pos->x += -1;
		return (1);
	}
	return (0);
}

int	key_press(int keycode, t_sl *sl)
{
	char	*counter;
	t_pos	pos;

	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(sl->mlx.mlx_ptr, sl->mlx.win_ptr);
		sl->mlx.win_ptr = NULL;
		destroy(sl);
	}
	pos = sl->player.pos;
	change_pos(keycode, sl, &pos);
	if ((sl->map_tab)[(int)pos.y][(int)pos.x] != '1' && \
		change_pos(keycode, sl, &sl->player.pos))
	{
		sl->move_counter += 1;
		counter = ft_itoa(sl->move_counter);
		if (!counter)
			exit_sl(5, sl);
		write(1, counter, ft_strlen(counter));
		write(1, "\n", 1);
		free(counter);
	}
	return (0);
}
