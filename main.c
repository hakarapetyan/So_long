/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakarape <hakarape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:56:59 by hakarape          #+#    #+#             */
/*   Updated: 2024/07/13 16:52:41 by hakarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_game	*game;

	game = malloc(sizeof(t_game));
	arg_val(argc, argv);
	open_file(&fd, argv);
	map_read(fd, game);
	close(fd);
	open_file(&fd, argv);
	helper_read(fd, game);
	init_struct(game);
	is_rectangle(game);
	is_surrounded(game);
	check_elements(game);
	check_screen(game);
	is_playable(game);
	init_game(game);
	put_images(game);
	mlx_hook(game -> g_img.window, 2, 0, movement, game);
	mlx_hook(game -> g_img.window, 17, 0, finish, game);
	mlx_loop(game ->g_img.img);
}
	// int l = 0;
	// int m = 0;
	// printf("syun index: %d\n", game ->g_map.ind_row);
	// while (game->g_map.m_map[l])
	// {
	// 	m = 0;
	// 	while (game->g_map.m_map[l][m])
	// 	{
	// 		printf("%c", game->g_map.m_map[l][m]);
	// 		++m;
	// 	}
	// 	printf("\n");
	// 	++l;
	// }
	// printf("\n-------------------------\n");
	// printf("hihi\n");
	// printf("syun index: %d\n", game ->g_map.ind_row);
