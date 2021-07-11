/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsings_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:31:40 by tmerrien          #+#    #+#             */
/*   Updated: 2021/07/05 04:12:37 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"
#include "../includes/get_next_line.h"
#include "../includes/mlx.h"
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>

int	valid_name(char *s)
{
	int		len;
	int		ext_len;
	char	*ext;

	len = gnl_strlen(s);
	ext_len = sizeof(EXTENS);
	ext = EXTENS;
	while (*(ext + --ext_len) == *(s + len))
		--len;
	if (ext_len > -1)
		return (0);
	return (1);
}

void	get_txt_ptr(t_sl *sl, char *path, t_image *tex)
{
	tex->tex_ptr = mlx_xpm_file_to_image(sl->mlx.mlx_ptr, path, \
		&(tex->x_max), &(tex->y_max));
	if (!(tex->tex_ptr))
		exit_sl(5, sl);
	tex->img_data = (int *)mlx_get_data_addr(tex->tex_ptr, \
		&tex->bpp, &tex->size_line, &tex->endian);
}

void	sl_parsing(t_sl *sl)
{
	int	fd;

	fd = open(sl->snd_arg, O_RDONLY);
	if (fd < 0)
		exit_sl(2, sl);
	map_parse(sl, fd);
	sl->win.x = (int)ft_strlen((sl->map_tab)[0]) * CASE_SIZE;
	sl->win.y = sl->map_size * CASE_SIZE;
	get_txt_ptr(sl, P_COLLEC, &sl->collec_tex);
	get_txt_ptr(sl, P_ENNEMY, &sl->ennemy_tex);
	get_txt_ptr(sl, P_EXIT, &sl->exit_tex);
	get_txt_ptr(sl, P_FLOOR, &sl->floor_tex);
	get_txt_ptr(sl, P_PLAYER, &sl->player_tex);
	get_txt_ptr(sl, P_WALL, &sl->wall_tex);
	get_txt_ptr(sl, P_PLAYER_L, &sl->player_left_tex);
	sl->used_player_tex = sl->player_tex;
}
