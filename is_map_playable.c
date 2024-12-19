/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_playable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakarape <hakarape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:23:35 by hakarape          #+#    #+#             */
/*   Updated: 2024/07/13 16:50:22 by hakarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return (1);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return (1);
		i++;
	}
	return (0);
}

char	**cpy_map(t_game *game)
{
	int		i;
	char	**cpy;

	i = 0;
	cpy = (char **)malloc(sizeof(char *) * (game->g_map.ind_row + 2));
	if (!cpy)
	{
		free_mem(game->g_map.m_map);
		ft_error("ERROR\nALLOCATION FAILED\n", NULL);
	}
	while (i <= game->g_map.ind_row)
	{
		cpy[i] = (char *)malloc(sizeof(char) * game->g_map.ind_columns + 2);
		if (!cpy[i])
		{
			free_mem(cpy);
			free_mem(game->g_map.m_map);
			ft_error("ERROR\nALLOCATION FAILED\n", cpy[i]);
		}
		cpy[game->g_map.ind_row + 1] = NULL;
		ft_strcpy(cpy[i], game ->g_map.m_map[i]);
		i++;
	}
	return (cpy);
}

void	flood_fill(char **copy, t_position point, int c, int r)
{
	if (point.x < 0 || point.y < 0 || point.y >= r || point.x >= c)
		return ;
	if (ft_strchr("CP", copy[point.y][point.x]))
		copy[point.y][point.x] = '0';
	if (ft_strchr("E", copy[point.y][point.x]))
		copy[point.y][point.x] = 'T';
	if (copy[point.y][point.x] != '0')
		return ;
	copy[point.y][point.x] = 'F';
	flood_fill(copy, (t_position){point.x + 1, point.y}, c, r);
	flood_fill(copy, (t_position){point.x - 1, point.y}, c, r);
	flood_fill(copy, (t_position){point.x, point.y + 1}, c, r);
	flood_fill(copy, (t_position){point.x, point.y - 1}, c, r);
}

void	map_checker(t_game *game, char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((i <= game->g_map.ind_row))
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_strchr("10FT", str[i][j]))
			{
				free_mem(str);
				free_mem(game -> g_map.m_map);
				ft_error("ERROR\nIS NOT PRINTABLE\n", NULL);
			}
			j++;
		}
		i++;
	}
}

void	is_playable(t_game *game)
{
	char	**cpy;
	int		row;
	int		columns;
	int		i;

	i = 0;
	cpy = cpy_map(game);
	row = game->g_map.ind_row + 1;
	columns = game->g_map.ind_columns + 1;
	flood_fill(cpy, game ->o, columns, row);
	map_checker(game, cpy);
	free_mem(cpy);
}
