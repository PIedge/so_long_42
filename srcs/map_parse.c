/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 07:16:10 by tmerrien          #+#    #+#             */
/*   Updated: 2021/07/11 17:16:49 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"
#include "../includes/get_next_line.h"
#include "../includes/mlx.h"
#include <fcntl.h>
#include <stdio.h>
#include <math.h>

#include <stdio.h>

static char	**set_map_y(t_sl *sl, int fd)
{
	int		ret;
	int		y;
	char	*buff;
	char	**map;

	sl->map_size = 0;
	ret = get_next_line(fd, &buff);
	while (ret >= 0 && *buff != '\0')
	{
		++(sl->map_size);
		free(buff);
		ret = get_next_line(fd, &buff);
	}
	free(buff);
	if (ret < 0)
		exit_sl(5, sl);
	map = malloc(sizeof(char *) * (sl->map_size + 1));
	if (!map)
		exit_sl(10, sl);
	y = 0;
	while (y < sl->map_size)
		map[y++] = NULL;
	return (map);
}

static void	set_map_x(t_sl *sl, int fd)
{
	int		y;
	int		ret;
	char	**map;
	char	*line;

	y = 0;
	map = sl->map_tab;
	ret = get_next_line(fd, &line);
	while (ret >= 0 && *line != '\0')
	{
		map[y] = ft_strdup(line);
		if (!(map[y]) && y != sl->map_size)
			exit_sl(10, sl);
		free(line);
		ret = get_next_line(fd, &line);
		++y;
	}
	free(line);
	map[sl->map_size] = NULL;
	y = -1;
}

static void	first_last_line(t_sl *sl, char *line)
{
	while (*line == '1')
		++line;
	if (*line != '\0')
		exit_sl(4, sl);
}

static void	verif(t_sl *sl, char **map)
{
	int	y;
	int	len_base;
	int	yes;

	sl->exit = 0;
	y = 0;
	yes = 0;
	len_base = (int)ft_strlen(map[y]);
	first_last_line(sl, map[y]);
	while (map[y])
		check_line_map(sl, &yes, y++, len_base);
	if (!yes || !(sl->collectibles) || !(sl->exit))
		exit_sl(4, sl);
}

int	map_parse(t_sl *sl, int fd)
{
	sl->map_tab = set_map_y(sl, fd);
	if (!(sl->map_tab))
		exit_sl(10, sl);
	close(fd);
	fd = open(sl->snd_arg, O_RDONLY);
	if (fd < 0)
		exit_sl(2, sl);
	set_map_x(sl, fd);
	verif(sl, sl->map_tab);
	return (1);
}
