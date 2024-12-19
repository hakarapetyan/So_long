/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakarape <hakarape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:06:51 by hakarape          #+#    #+#             */
/*   Updated: 2024/07/13 16:49:58 by hakarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->g_img.img = mlx_init();
	if (!game->g_img.img)
	{
		ft_error("ERROR\nMLX DOSE NOT WORK\n", NULL);
		free_mem(game->g_map.m_map);
	}
	game->g_img.window = mlx_new_window(game->g_img.img,
			(game->g_map.ind_columns + 1) * WIDTH,
			(game->g_map.ind_row + 1) * HEIGHT, "so_long" );
	if (!game->g_img.window)
	{
		ft_error("ERROR\nMLX DOSE NOT WORK\n", NULL);
		free_mem(game->g_map.m_map);
	}
}

void	init_images(t_game *game, int w, int h)
{
	game->g_img.empty = mlx_xpm_file_to_image(game ->g_img.img, EMPTY, &w, &h);
	game->g_img.exit = mlx_xpm_file_to_image(game ->g_img.img, EXIT, &w, &h);
	game->g_img.wall = mlx_xpm_file_to_image(game ->g_img.img, WALL, &w, &h);
	game->g_img.coins = mlx_xpm_file_to_image(game ->g_img.img, COIN, &w, &h);
	game->g_img.player = mlx_xpm_file_to_image(game ->g_img.img,
			PLAYER, &w, &h);
}

void	put_mlx(t_game *game, int x, int y, char element)
{
	if (element == '1')
		mlx_put_image_to_window(game ->g_img.img, game->g_img.window,
			game->g_img.wall, x * WIDTH, y * HEIGHT);
	else if (element == '0')
		mlx_put_image_to_window(game ->g_img.img, game->g_img.window,
			game->g_img.empty, x * WIDTH, y * HEIGHT);
	else if (element == 'E')
		mlx_put_image_to_window(game ->g_img.img, game->g_img.window,
			game->g_img.exit, x * WIDTH, y * HEIGHT);
	else if (element == 'C')
		mlx_put_image_to_window(game ->g_img.img, game->g_img.window,
			game->g_img.coins, x * WIDTH, y * HEIGHT);
	else if (element == 'P')
		mlx_put_image_to_window(game ->g_img.img, game->g_img.window,
			game->g_img.player, x * WIDTH, y * HEIGHT);
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= game->g_map.ind_row)
	{
		j = 0;
		while (j <= game->g_map.ind_columns)
		{
			put_mlx(game, j, i, game->g_map.m_map[i][j]);
			j++;
		}
		i++;
	}
}

void	put_images(t_game *game)
{
	init_images(game, WIDTH, HEIGHT);
	draw_map(game);
}
