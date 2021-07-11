/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:54:25 by tmerrien          #+#    #+#             */
/*   Updated: 2021/07/10 15:50:40 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"
#include "../includes/mlx_int.h"
#include <X11/Xlib.h>
#include <unistd.h>

void	free_mob(t_mob *mob)
{
	if (!mob)
		return ;
	while (mob->prev)
		mob = mob->prev;
	while (mob->next)
	{
		mob = mob->next;
		free(mob->prev);
	}
	free(mob);
}

void	mlx_terminate(void *mlxptr)
{
	struct s_xvar	*xvar;

	if (!mlxptr)
		return ;
	xvar = mlxptr;
	if (xvar->private_cmap)
		XFreeColormap(xvar->display, (Colormap)xvar->private_cmap);
	XCloseDisplay(xvar->display);
	free(xvar);
}	
