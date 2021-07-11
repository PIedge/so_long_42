/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 11:07:41 by tmerrien          #+#    #+#             */
/*   Updated: 2021/07/03 04:34:14 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*buff;
	unsigned char	*tmp;
	size_t			size;

	size = sizeof(unsigned long long);
	tmp = (unsigned char *)src;
	buff = (unsigned char *)dst;
	if (!tmp && !buff)
		return (0);
	while (n--)
	{
		*buff = *tmp;
		buff++;
		tmp++;
	}
	return (dst);
}
