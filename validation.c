/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakarape <hakarape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:29:55 by hakarape          #+#    #+#             */
/*   Updated: 2024/07/13 16:51:50 by hakarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_ber(char *str)
{
	int	n;

	n = int_strlen(str);
	if (str[n - 1] == 'r' && str[n - 2] == 'e'
		&& str[n - 3] == 'b' && str[n - 4] == '.')
		return (1);
	return (0);
}

void	map_read(int fd, t_game *game)
{
	char	*line;
	char	*tmp;

	line = get_next_line(fd);
	if (!line)
		ft_error("ERROR\nTERE IS NOTHING TO READ\n", line);
	game->g_map.ind_row = 0;
	while (2)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		line = ft_strjoin(line, tmp);
		free(tmp);
		game->g_map.ind_row++;
		if (!line)
			ft_error("ERROR\nIT CAN NOT BE JOINED\n", line);
	}
	game -> g_map.m_map = ft_split(line, '\n');
	if (!game -> g_map.m_map)
		ft_error("ERROR\nREADING MAP\n", NULL);
	free(line);
	free(tmp);
}

void	helper_read(int fd, t_game *game)
{
	char	*tmp;

	while (1)
	{
		tmp = get_next_line(fd);
		if (!(tmp))
			break ;
		if (!start_check(tmp))
		{
			free_mem(game->g_map.m_map);
			ft_error("ERROR\nMAP IS INVALID\n", NULL);
		}
		free(tmp);
	}
	close(fd);
	free(tmp);
}

int	start_check(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	if (str[i] == '\n' || str[i] == '\v' || str[i] == '\t')
	{
		return (0);
	}
	return (1);
}

void	arg_val(int argc, char **argv)
{
	if (argc != 2)
		ft_error("ERROR\nARGC != 2\n", NULL);
	if (!is_ber(argv[1]))
		ft_error("ERROR\nIS NOT BER\n", NULL);
}
