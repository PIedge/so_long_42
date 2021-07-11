/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:30:36 by tmerrien          #+#    #+#             */
/*   Updated: 2021/07/05 01:51:21 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"
#include "../includes/so_long_bonus.h"
#include <unistd.h>

#include <stdio.h>

void	draw_texture(t_sl *sl, t_image *tex, t_pos pos_on_map)
{
	int	i;

	i = -1;
	while (++i < CASE_SIZE)
		draw_line_texture(&sl->screen, tex, pos_on_map, i);
}

void	draw_line_texture(t_image *s, t_image *tex, t_pos pos_on_map, \
	int line_h)
{
	int	i;

	i = -1;
	while (++i < CASE_SIZE)
	{
		if (tex->img_data[tex->x_max * line_h + i] != 0)
		{
			draw_pixel(s, tex->img_data[tex->y_max * line_h + i], \
				(pos_on_map.x * CASE_SIZE) + i, pos_on_map.y * \
					CASE_SIZE + line_h);
		}
	}
}

void	draw_pixel(t_image *s, int color, int start, int height)
{
	*((int *)s->img_data + start + (s->x_max * height)) = color;
}
