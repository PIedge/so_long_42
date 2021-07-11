/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:06:15 by tmerrien          #+#    #+#             */
/*   Updated: 2021/07/04 13:29:47 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
/*
** Strings defines
*/
# define EXTENS ".ber"
# define MSG_E_MALLOC "Malloc didn't work accordingly.\n"
# define MSG_E_EXTENS "Wrong file name or wrong path.\n"
# define MSG_E_ARGS "No arg or too much args were passed, pass only one.\n"
# define MSG_E_N_MAP "Where the fuck is your map bro ?!"
# define MSG_E_ELE "Missing or bogus element/s in description file.\n"
# define MSG_E_MAP "Your map is wrong.\n"
# define MSG_E_DEF "Error\n"
# define P_COLLEC "./assets/collec.xpm"
# define P_ENNEMY "./assets/ennemy.xpm"
# define P_EXIT "./assets/exit.xpm"
# define P_FLOOR "./assets/floor.xpm"
# define P_PLAYER "./assets/player.xpm"
# define P_WALL "./assets/wall.xpm"
/*
** Input Keys
*/
# define Z 122
# define Q 113
# define D 100
# define S 115
# define W 119
# define A 97
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define ESC_KEY 65307
/*
** Map Keys
*/
# define ENEMY 'X'
# define E_SPACE '0'
# define WALL '1'
# define COLLEC 'C'
# define EXIT 'E'
# define SPAWN 'P'
/*
** Uncategorized
*/
# define CASE_SIZE 32
# define RANGE 10
# include <unistd.h>

typedef unsigned int	t_uint;

typedef struct s_keymap
{
	int				up;
	int				left;
	int				right;
	int				down;
	int				rotate_right;
	int				rotate_left;
}					t_keymap;

typedef struct s_image
{
	int				bpp;
	int				size_line;
	int				endian;
	int				x_max;
	int				y_max;
	void			*tex_ptr;
	int				*img_data;
	char			*path;
	int				x_dis;
}					t_image;

typedef struct s_map
{
	char			*line;
	long			length;
	struct s_map	*next;
	struct s_map	*prev;
	int				y;
}					t_map;

typedef struct s_win
{
	double			x;
	double			y;
}					t_win;

typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_mlx;

typedef struct s_pos
{
	double			x;
	double			y;
}					t_pos;

typedef struct s_player
{
	int				rot;
	t_pos			mov;
	t_pos			pos;
}					t_player;

typedef struct s_sl
{
	char			*snd_arg;
	int				count;
	t_mlx			mlx;
	t_keymap		keymap;
	t_pos			caze_size;
	t_image			screen;
	t_image			wall_tex;
	t_image			player_tex;
	t_image			collec_tex;
	t_image			exit_tex;
	t_image			ennemy_tex;
	t_image			floor_tex;
	t_image			player_left_tex;
	t_image			used_player_tex;
	t_win			win;
	t_player		player;
	char			**map_tab;
	int				map_size;
	int				move_counter;
	int				collectibles;
	int				exit;
}					t_sl;

/*
** Functions
*/
int		valid_name(char *s);
int		ft_malloc(void *v, size_t size);
t_map	*init_map(void);
void	sl_parsing(t_sl *sl);
int		map_parse(t_sl *sl, int fd);

int		set_pos(t_pos *set, int x, int y);
int		set_tmp(t_sl *sl, t_map *tmp, int fd, int *ret);
void	map_it(t_sl *sl);
t_uint	check_line_map(t_sl *sl, int *yes, int y, int len_base);

int		key_press(int keycode, t_sl *sl);
int		loop_game(t_sl *sl);
void	strafe(t_player *p, t_sl *sl);

int		destroy(t_sl *i);
void	exit_sl(t_uint exit_code, t_sl *i);

char	*ft_itoa(int n);

int		engine_init(t_sl *sl);

/*
** Libft redux
*/
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
/*
** Free
*/
void	finish(t_sl *sl, char *str);
void	mlx_terminate(void *mlxptr);
void	free_img(t_sl *sl, t_image *img);
void	free_double_tab(t_sl *sl);
/*
** Draw
*/
void	draw_pixel(t_image *s, int color, int y, int x);
void	draw_texture(t_sl *sl, t_image *tex, t_pos pos_on_map);
void	draw_line_texture(t_image *s, t_image *tex, \
	t_pos pos_on_map, int line_h);
#endif
