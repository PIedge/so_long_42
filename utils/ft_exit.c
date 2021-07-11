/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:41:50 by tmerrien          #+#    #+#             */
/*   Updated: 2021/07/11 17:25:58 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"
#include "../includes/mlx.h"
#include <stdlib.h>

void	free_double_tab(t_sl *sl)
{
	while (sl->map_tab != 0 && sl->map_size > 0)
		free(sl->map_tab[--(sl->map_size)]);
	free(sl->map_tab);
	sl->map_tab = 0;
}

void	free_img(t_sl *sl, t_image *img)
{
	if (img->tex_ptr != 0)
		mlx_destroy_image(sl->mlx.mlx_ptr, img->tex_ptr);
}

void	exit_sl(t_uint exit_code, t_sl *i)
{
	if (exit_code == 1)
		write(1, MSG_E_MALLOC, sizeof(MSG_E_MALLOC) / sizeof(char));
	else if (exit_code == 2)
		write(1, MSG_E_EXTENS, sizeof(MSG_E_EXTENS) / sizeof(char));
	else if (exit_code == 3)
		write(1, MSG_E_ARGS, sizeof(MSG_E_ARGS) / sizeof(char));
	else if (exit_code == 4)
		write(1, MSG_E_MAP, sizeof(MSG_E_MAP) / sizeof(char));
	else if (exit_code == 5)
		write(1, MSG_E_ELE, sizeof(MSG_E_ELE) / sizeof(char));
	else if (exit_code == 10)
		write(1, MSG_E_MAP, sizeof(MSG_E_MAP) / sizeof(char));
	if (exit_code)
		write(1, "Error\n", 6);
	destroy(i);
}
