/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 10:58:57 by tmerrien          #+#    #+#             */
/*   Updated: 2021/07/04 13:35:18 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../includes/so_long_bonus.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*copy;

	len = (int)ft_strlen(s1);
	copy = malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (0);
	ft_memcpy(copy, s1, len);
	copy[len] = '\0';
	return (copy);
}
