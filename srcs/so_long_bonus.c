/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 04:32:55 by tmerrien          #+#    #+#             */
/*   Updated: 2021/07/11 19:40:12 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"
#include "../includes/so_long_bonus.h"
#include <math.h>
#include <stdlib.h>

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
	draw_texture(sl, &sl->used_player_tex, pos);
	if (map[(int)sl->player.pos.y][(int)sl->player.pos.x] == 'C')
	{
		sl->collectibles -= 1;
		map[(int)sl->player.pos.y][(int)sl->player.pos.x] = '0';
	}
	if (map[(int)sl->player.pos.y][(int)sl->player.pos.x] == 'E' && \
		sl->collectibles == 0)
		finish(sl, "You won\n");
	step_on_mob(sl, sl->player.pos);
}

void	which_to_draw(t_sl *sl, char c, t_pos pos, char **map)
{
	if (c == '1')
		draw_texture(sl, &sl->wall_tex, pos);
	else if (c == '0')
		draw_texture(sl, &sl->floor_tex, pos);
	else if (c == 'E')
		draw_texture(sl, &sl->exit_tex, pos);
	if (c == 'C')
	{
		draw_texture(sl, &sl->floor_tex, pos);
		draw_texture(sl, &sl->collec_tex, pos);
	}
	if (c == 'X')
	{
		draw_texture(sl, &sl->floor_tex, pos);
		draw_texture(sl, &sl->ennemy_tex, pos);
	}
	if (pos.x == sl->player.pos.x && pos.y == sl->player.pos.y)
		step_on(sl, map, pos);
}

void	render(t_sl *sl, char **map)
{
	int			x;
	int			y;
	t_pos		pos;
	static int	frame = 0;

	y = -1;
	while (++y < (int)sl->win.y / CASE_SIZE)
	{
		x = -1;
		while (++x <= (int)sl->win.x / CASE_SIZE && set_pos(&pos, x, y))
			which_to_draw(sl, map[y][x], pos, map);
	}
	if (frame == 1000)
	{
		patrols(sl, sl->map_tab);
		frame = -1;
	}
	draw_mob(sl);
	++frame;
}

int	loop_game(t_sl *sl)
{
	char	*counter;

	strafe(&sl->player, sl);
	render(sl, sl->map_tab);
	mlx_put_image_to_window(sl->mlx.mlx_ptr, sl->mlx.win_ptr, \
		sl->screen.tex_ptr, 0, 0);
	counter = ft_itoa(sl->move_counter);
	if (!counter)
		exit_sl(5, sl);
	mlx_string_put(sl->mlx.mlx_ptr, sl->mlx.win_ptr, 16, 16, 65280, counter);
	free(counter);
	mlx_do_sync(sl->mlx.mlx_ptr);
	return (1);
}
