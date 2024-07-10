/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsatge <dsatge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:05:56 by dsatge            #+#    #+#             */
/*   Updated: 2024/06/26 16:06:46 by dsatge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_char(char *map, char search)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		if (map[i] == search)
			count++;
		i++;
	}
	return (count);
}

int	check_0_1(int i)
{
	if (i == '1')
		return (0);
	if (i == '0')
		return (0);
	return (1);
}

char	**ft_tabdup(t_game *game)
{
	char	**dup;
	int		i;

	i = 0;
	dup = ft_calloc((sizeof(char *)), 10000);
	if (!dup)
		return (NULL);
	while (game->map_tab[i])
	{
		dup[i] = ft_strdup(game->map_tab[i]);
		i++;
	}
	dup[i] = 0;
	return (dup);
}

void	exit_pos(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map_tab[y])
	{
		x = 0;
		while (game->map_tab[y][x])
		{
			if (game->map_tab[y][x] == 'E')
			{
				game->exit_x = x;
				game->exit_y = y;
			}
			x++;
		}
		y++;
	}
}

void	delay(void)
{
	long	delay;

	delay = 0;
	while (delay < 700000000)
		delay++;
}
