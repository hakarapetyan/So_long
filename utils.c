/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakarape <hakarape@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:15:06 by hakarape          #+#    #+#             */
/*   Updated: 2024/07/13 16:54:40 by hakarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	int_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	open_file(int *fd, char **argv)
{
	*fd = open(argv[1], O_RDONLY);
	if (*fd == -1)
		ft_error("ERROR\nOPENING FILE\n", NULL);
}

void	ft_error(char *str, char *str1)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	free(str1);
	exit(1);
}
