/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakarape <hakarape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:38:29 by hakarape          #+#    #+#             */
/*   Updated: 2024/07/13 16:47:36 by hakarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>

# define HEIGHT 50
# define WIDTH 50
# define SCREEN_W 1920
# define SCREEN_H 1080

# define EMPTY "images/empty.xpm"
# define EXIT "images/exit.xpm"
# define WALL "images/wall_beige.xpm"
# define COIN "images/coin.xpm"
# define PLAYER "images/player.xpm"

# define UP_W 126
# define DOWN_S 125
# define LEFT_A 123
# define RIGHT_D 124
# define ESC 53

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_map
{
	char	**m_map;
	int		ind_row;
	int		ind_columns;
}	t_map;

typedef struct s_map_int
{
	int	exit;
	int	player;
	int	coins;
	int	wall;
	int	empty;
	int	steps;
}	t_map_int;

typedef struct s_img
{
	void	*window;
	void	*img;
	void	*exit;
	void	*player;
	void	*coins;
	void	*wall;
	void	*empty;
}	t_img;

typedef struct s_game
{
	t_map		g_map;
	t_position	o;
	t_img		g_img;
	t_map_int	g_int;
}	t_game;

int		int_strlen(char *str);
void	ft_error(char *str, char *str1);
int		is_ber(char *str);
void	map_read(int fd, t_game *game);
char	**ft_split(char const *s, char c);
void	free_mem(char **split);
char	**all_memory(char **split, char const *s, char c);
char	*word_memory(char const *s, int f_ind, int l_ind);
int		w_count(char const *s, char c);

void	is_rectangle(t_game *game);
void	init_struct(t_game *game);
void	arg_val(int argc, char **argv);
void	open_file(int *fd, char **argv);
void	vertical_wall(t_game *game);
void	horizontal_wall(t_game *game);
void	is_surrounded(t_game *game);
void	check_elements(t_game *game);
void	count_elements(t_game *game);
void	counter(t_game *game, char c, int x, int y);
char	**cpy_map(t_game *game);
char	*ft_strcpy(char *dest, char *src);
int		ft_strchr(char *s, int c);
void	flood_fill(char **copy, t_position point, int row, int columns);
void	is_playable(t_game *game);
void	check_screen(t_game *game);
void	map_checker(t_game *game, char **str);
void	init_game(t_game *game);
void	init_images(t_game *game, int w, int h);
void	put_mlx(t_game *game, int x, int y, char element);
void	draw_map(t_game *game);
void	put_images(t_game *game);
int		movement(int key, t_game *game);
void	destroy_images(t_game *game);
void	move_player(t_game *game, int x, int y);
int		finish(t_game *game);
void	ft_putnbr(int k);
int		start_check(char *str);
void	helper_read(int fd, t_game *game);
void	f_helper(int k);

#endif
