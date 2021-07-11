/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 19:09:23 by tmerrien          #+#    #+#             */
/*   Updated: 2021/07/04 13:35:37 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"
#include "../includes/so_long_bonus.h"
#include <math.h>

#include <stdio.h>

void	strafe(t_player *p, t_sl *sl)
{
	char	**map;
	t_pos	pos;

	map = sl->map_tab;
	set_pos(&pos, (int)(p->pos.x + p->mov.x), (int)(p->pos.y + p->mov.y));
	if (pos.x >= 0 && pos.x <= ft_strlen(map[0]) && pos.y >= 0 && \
		pos.y < sl->map_size && map[(int)pos.y][(int)pos.x] != '1')
		set_pos(&p->pos, (int)pos.x, (int)pos.y);
}

void	step_on(t_sl *sl, char **map, t_pos pos)
{
	draw_texture(sl, &sl->player_tex, pos);
	if (map[(int)sl->player.pos.y][(int)sl->player.pos.x] == 'C')
	{
		sl->collectibles -= 1;
		map[(int)sl->player.pos.y][(int)sl->player.pos.x] = '0';
	}
	if (map[(int)sl->player.pos.y][(int)sl->player.pos.x] == 'E' && \
		sl->collectibles == 0)
		finish(sl, "You won\n");
}

void	render(t_sl *sl, char **map)
{
	int		x;
	int		y;
	t_pos	pos;

	y = -1;
	while (++y < (int)sl->win.y / CASE_SIZE)
	{
		x = -1;
		while (++x <= (int)sl->win.x / CASE_SIZE && set_pos(&pos, x, y))
		{
			if (map[y][x] == '1')
				draw_texture(sl, &sl->wall_tex, pos);
			else if (map[y][x] == '0')
				draw_texture(sl, &sl->floor_tex, pos);
			else if (map[y][x] == 'E')
				draw_texture(sl, &sl->exit_tex, pos);
			if (map[y][x] == 'C')
			{
				draw_texture(sl, &sl->floor_tex, pos);
				draw_texture(sl, &sl->collec_tex, pos);
			}
			if (pos.x == sl->player.pos.x && pos.y == sl->player.pos.y)
				step_on(sl, map, pos);
		}
	}
}

int	loop_game(t_sl *sl)
{
	strafe(&sl->player, sl);
	render(sl, sl->map_tab);
	mlx_put_image_to_window(sl->mlx.mlx_ptr, sl->mlx.win_ptr, \
		sl->screen.tex_ptr, 0, 0);
	mlx_do_sync(sl->mlx.mlx_ptr);
	return (1);
}
