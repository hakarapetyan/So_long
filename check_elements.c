/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakarape <hakarape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:58:00 by hakarape          #+#    #+#             */
/*   Updated: 2024/07/13 16:49:43 by hakarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	counter(t_game *game, char c, int x, int y)
{
	if (c == '1')
		game->g_int.wall++;
	else if (c == '0')
		game->g_int.empty++;
	else if (c == 'C')
		game->g_int.coins++;
	else if (c == 'E')
		game->g_int.exit++;
	else if (c == 'P')
	{
		game->g_int.player++;
		game->o.x = x;
		game->o.y = y;
	}
	else
	{
		ft_error("ERROR\nINVALID ELEMENT\n", NULL);
		free_mem(game->g_map.m_map);
	}
}

void	count_elements(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->g_map.m_map[i])
	{
		j = 0;
		while (game->g_map.m_map[i][j])
		{
			counter(game, game->g_map.m_map[i][j], j, i);
			j++;
		}
		i++;
	}
}

void	check_elements(t_game *game)
{
	count_elements(game);
	if (game->g_int.coins < 1 || game->g_int.player != 1
		|| game->g_int.exit != 1)
	{
		ft_error("ERROR\nELEMENTS COUNT IS INCORRECT\n", NULL);
		free_mem(game ->g_map.m_map);
	}
}
