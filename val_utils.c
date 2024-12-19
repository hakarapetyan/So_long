/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakarape <hakarape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:53:09 by hakarape          #+#    #+#             */
/*   Updated: 2024/07/13 16:51:30 by hakarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_screen(t_game *game)
{
	int	r;
	int	c;

	r = game ->g_map.ind_row + 1;
	c = game ->g_map.ind_columns + 1;
	if (r > SCREEN_H / HEIGHT || c > SCREEN_W / WIDTH)
	{
		ft_error("ERROR\nMAP IS LARG\n", NULL);
		free_mem(game->g_map.m_map);
	}
}

static void	ft_putchar(int c)
{
	char	k;

	k = c + 48;
	write(1, &k, 1);
}

void	ft_putnbr(int k)
{
	long	n;

	n = k;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
