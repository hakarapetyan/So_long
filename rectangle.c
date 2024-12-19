/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakarape <hakarape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:03:03 by hakarape          #+#    #+#             */
/*   Updated: 2024/07/13 16:51:00 by hakarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_rectangle(t_game *game)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	size = int_strlen(game ->g_map.m_map[i]);
	while (game ->g_map.m_map[i])
	{
		if (size != int_strlen(game ->g_map.m_map[i]))
		{
			ft_error("ERROR\nIS NOT RECTANGLE\n", game ->g_map.m_map[i]);
			free_mem(game ->g_map.m_map);
		}
		i++;
	}
}
