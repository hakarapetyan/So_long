/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakarape <hakarape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:02:35 by hakarape          #+#    #+#             */
/*   Updated: 2024/07/12 13:45:44 by hakarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_game *game)
{
	game -> g_map.ind_columns = int_strlen(game->g_map.m_map[0]) - 1;
	game -> o.x = 0;
	game -> o.y = 0;
	game -> g_img.coins = 0;
	game -> g_img.wall = 0;
	game -> g_img.exit = 0;
	game -> g_img.empty = 0;
	game -> g_img.player = 0;
	game -> g_int.coins = 0;
	game -> g_int.player = 0;
	game -> g_int.exit = 0;
	game -> g_int.empty = 0;
	game -> g_int.wall = 0;
	game -> g_int.steps = 0;
}

// void	init_game(t_game **game, char **map)
// {
// 	(*game) = (t_game *)malloc(sizeof(t_game));
// 	if (!(*game))
// 	{
// 		free_mem(map);
// 		free(*game);
// 		ft_error("MALLOC IS ENABLE", NULL);
// 	}
// 	(*game) -> map_game = map;
// }