/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakarape <hakarape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:20:26 by hakarape          #+#    #+#             */
/*   Updated: 2024/07/13 16:53:41 by hakarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_images(t_game *game)
{
	mlx_destroy_image(game ->g_img.img, game->g_img.coins);
	mlx_destroy_image(game ->g_img.img, game->g_img.empty);
	mlx_destroy_image(game ->g_img.img, game->g_img.exit);
	mlx_destroy_image(game ->g_img.img, game->g_img.player);
	mlx_destroy_image(game ->g_img.img, game->g_img.wall);
	free_mem(game ->g_map.m_map);
	if (game ->g_img.window)
		mlx_destroy_window(game->g_img.img, game->g_img.window);
	if (game)
	{
		free(game);
		game = NULL;
	}
}

void	move_player(t_game *game, int x, int y)
{
	char	symb;

	symb = game->g_map.m_map[y][x];
	if (symb == '1')
		return ;
	if (symb == 'C')
		game -> g_int.coins--;
	if (symb == 'E')
	{
		if (game -> g_int.coins <= 0)
		{
			f_helper(game->g_int.steps);
			put_mlx(game, game -> o.x, game -> o.y, '0');
			put_mlx(game, x, y, 'P');
			destroy_images(game);
			exit (0);
		}
		else
			return ;
	}
	game ->g_int.steps++;
	put_mlx(game, game -> o.x, game -> o.y, '0');
	game ->o.x = x;
	game ->o.y = y;
	put_mlx(game, x, y, 'P');
}

void	f_helper(int k)
{
	k++;
	ft_putnbr(k);
	write (1, "\n", 1);
}

int	movement(int key, t_game *game)
{
	if (key == ESC)
	{
		destroy_images(game);
		game = NULL;
		exit(0);
	}
	else if (key == UP_W)
		move_player(game, game -> o.x, (game -> o.y - 1));
	else if (key == DOWN_S)
		move_player(game, game -> o.x, (game -> o.y + 1));
	else if (key == RIGHT_D)
		move_player(game, (game -> o.x + 1), game -> o.y);
	else if (key == LEFT_A)
		move_player(game, (game -> o.x - 1), game -> o.y);
	ft_putnbr(game ->g_int.steps);
	write (1, "\n", 1);
	return (0);
}

int	finish(t_game *game)
{
	destroy_images(game);
	game = NULL;
	exit(0);
	return (0);
}
