/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:05:18 by tmerrien          #+#    #+#             */
/*   Updated: 2021/07/11 19:05:27 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long_bonus.h"
#include "includes/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>

#include <stdio.h>

int	destroy(t_sl *i)
{
	free_img(i, &i->ennemy_tex);
	free_img(i, &i->wall_tex);
	free_img(i, &i->screen);
	free_img(i, &i->player_tex);
	free_img(i, &i->exit_tex);
	free_img(i, &i->floor_tex);
	free_img(i, &i->player_left_tex);
	free_img(i, &i->collec_tex);
	free_double_tab(i);
	free_mob(i->mob);
	if (i->mlx.win_ptr)
		mlx_destroy_window(i->mlx.mlx_ptr, i->mlx.win_ptr);
	mlx_terminate(i->mlx.mlx_ptr);
	exit(0);
}

void	init_t_image(t_image *img)
{
	img->path = NULL;
	img->img_data = NULL;
	img->tex_ptr = NULL;
}

void	initialize(t_sl *info)
{
	set_pos(&info->player.pos, 0, 0);
	set_pos(&info->player.mov, 0, 0);
	info->win.x = 0;
	info->win.y = 0;
	info->map_tab = 0;
	init_t_image(&info->screen);
	init_t_image(&info->player_tex);
	init_t_image(&info->player_left_tex);
	init_t_image(&info->wall_tex);
	init_t_image(&info->collec_tex);
	init_t_image(&info->exit_tex);
	init_t_image(&info->floor_tex);
	init_t_image(&info->ennemy_tex);
	info->move_counter = 0;
	info->keymap.down = S;
	info->keymap.left = A;
	info->keymap.right = D;
	info->keymap.up = W;
	info->collectibles = 0;
	info->used_player_tex = info->player_tex;
	info->mob = NULL;
}

int	main(int ac, char **av)
{
	t_sl	info;

	info.snd_arg = av[1];
	info.mlx.mlx_ptr = mlx_init();
	if (!(info.mlx.mlx_ptr))
		exit_sl(0, &info);
	initialize(&info);
	if (ac == 1 || !valid_name(av[1]) || ac > 2)
		exit_sl(3, &info);
	sl_parsing(&info);
	engine_init(&info);
	info.mlx.win_ptr = mlx_new_window(info.mlx.mlx_ptr, info.win.x, info.win.y, \
		"so_long");
	mlx_hook(info.mlx.win_ptr, 2, 1L << 0, &key_press, &info);
	mlx_hook(info.mlx.win_ptr, 17, 0, &destroy, &info);
	mlx_loop_hook(info.mlx.mlx_ptr, &loop_game, &info);
	mlx_loop(info.mlx.mlx_ptr);
	destroy(&info);
}
