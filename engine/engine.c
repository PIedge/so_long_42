/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:40:06 by tmerrien          #+#    #+#             */
/*   Updated: 2021/07/04 13:36:16 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"
#include "../includes/so_long_bonus.h"
#include <unistd.h>

int	engine_init(t_sl *sl)
{
	sl->screen.tex_ptr = mlx_new_image(sl->mlx.mlx_ptr, sl->win.x, sl->win.y);
	sl->screen.x_max = sl->win.x;
	sl->screen.y_max = sl->win.y;
	sl->screen.img_data = (int *)mlx_get_data_addr(sl->screen.tex_ptr, \
		&sl->screen.bpp, &sl->screen.size_line, &sl->screen.endian);
	return (1);
}
