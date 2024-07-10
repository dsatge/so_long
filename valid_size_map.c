/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_size_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsatge <dsatge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:09:08 by dsatge            #+#    #+#             */
/*   Updated: 2024/06/26 16:08:44 by dsatge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	len_tab(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(map[0]);
	if (len == 0)
		return (-1);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			j++;
		}
		if (j != len)
			return (-1);
		i++;
	}
	return (len);
}

int	in_border(char **map, t_game *game)
{
	int	i;
	int	j;
	int	len;
	int	wide;

	i = 0;
	j = 0;
	wide = len_tab(map) - 1;
	game->tab_x_len = wide;
	len = ft_count_line_split(map) - 1;
	game->tab_y_len = len;
	if (border_1(map[0]) == 1 || border_1(map[len]) == 1)
		return (1);
	i++;
	while (i < (len - 1))
	{
		if (check_first_last_1(map[i], wide) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	border_1(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' )
			return (1);
		i++;
	}
	return (0);
}

int	check_first_last_1(char *line, int last)
{
	if (line[0] == '1' && line[last] == '1')
		return (0);
	return (1);
}

int	screen_size(t_game *game)
{
	if (game->tab_x_len > 30 || game->tab_y_len > 16)
		return (-1);
	return (0);
}
