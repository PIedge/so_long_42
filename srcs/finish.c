/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 23:50:25 by tmerrien          #+#    #+#             */
/*   Updated: 2021/07/11 19:40:38 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"
#include <unistd.h>

void	finish(t_sl *sl, char *str)
{
	write(1, str, ft_strlen(str));
	exit_sl(0, sl);
}
