/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surrounded_by_walls.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakarape <hakarape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:48:58 by hakarape          #+#    #+#             */
/*   Updated: 2024/07/13 16:51:16 by hakarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	horizontal_wall(t_game *game)
{
	int	i;

	i = 0;
	while (i <= game->g_map.ind_columns)
	{
		if (game ->g_map.m_map[0][i] != '1')
		{
			ft_error("MAP IS NOT SURROUNDED BY WALLS\n", NULL);
			free_mem(game ->g_map.m_map);
		}
		i++;
	}
	i = 0;
	while (i <= game->g_map.ind_columns)
	{
		if (game ->g_map.m_map[game->g_map.ind_row][i] != '1')
		{
			ft_error("MAP IS NOT SURROUNDED BY WALLS\n", NULL);
			free_mem(game ->g_map.m_map);
		}
		i++;
	}
}

void	vertical_wall(t_game *game)
{
	int	i;

	i = 0;
	while (i <= game->g_map.ind_row)
	{
		if (game ->g_map.m_map[i][0] != '1')
		{
			ft_error("ERROR\nMAP IS NOT SURROUNDED BY WALLS\n", NULL);
			free_mem(game ->g_map.m_map);
		}
		i++;
	}
	i = 0;
	while (i <= game->g_map.ind_row)
	{
		if (game ->g_map.m_map[i][game ->g_map.ind_columns] != '1')
		{
			ft_error("ERROR\nMAP IS NOT SURROUNDED BY WALLS\n", NULL);
			free_mem(game ->g_map.m_map);
		}
		i++;
	}
}

void	is_surrounded(t_game *game)
{
	vertical_wall(game);
	horizontal_wall(game);
}
