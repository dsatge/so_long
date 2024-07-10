/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsatge <dsatge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:33:49 by dsatge            #+#    #+#             */
/*   Updated: 2024/06/26 17:21:48 by dsatge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_map(char *map, t_game *game)
{
	char	**copy_tab;

	if (count_status(map, game) == 1)
		error_free_line(map, 1);
	if (no_free_space(map) == 1)
		error_free_line(map, -1);
	game->map_tab = ft_split(map, '\n');
	free(map);
	if (check_char(game) == -1)
		error_free_tab(game, 2);
	if (len_tab(game->map_tab) == -1)
		error_free_tab(game, 3);
	if (in_border(game->map_tab, game) == 1)
		error_free_tab(game, 4);
	if (screen_size(game) == -1)
		error_free_tab(game, 5);
	copy_tab = ft_tabdup(game);
	if (road_journey(copy_tab, game) == 0)
	{
		tab_free(copy_tab);
		error_free_tab(game, 6);
	}
	exit_pos(game);
	tab_free(copy_tab);
	return ;
}

int	no_free_space(char *map)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(map) - 1;
	while (map[i] && map[i] != '1')
		i++;
	while (map[j] > i && map[j] != '1')
		j--;
	while (map[i] && i < j)
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	check_char(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_tab[i])
	{
		j = 0;
		while (game->map_tab[i][j])
		{
			if (game->map_tab[i][j] != 'E' && game->map_tab[i][j] != 'C'
				&& game->map_tab[i][j] != 'P')
			{
				if (check_0_1(game->map_tab[i][j]) == 1)
					return (-1);
			}
			if (game->map_tab[i][j] == 'P')
			{
				(*game).p_position_x = j;
				(*game).p_position_y = i;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	count_status(char *map, t_game *game)
{
	int	status;

	(*game).collectible = count_char(map, 'C');
	status = 0;
	if (count_char(map, 'P') != 1)
		status = 1;
	if (count_char(map, 'E') != 1)
		status = 1;
	if ((*game).collectible < 1)
		status = 1;
	game->exit = 0;
	return (status);
}

char	*map_read(int fd)
{
	char	*buff;
	char	*temp;
	char	*saved;
	int		i;

	buff = ft_calloc(sizeof(char), 10000);
	if (!buff)
		return (NULL);
	saved = ft_calloc(sizeof(char), 10000);
	if (!saved)
		return (NULL);
	i = 1;
	while (i != 0)
	{
		i = read(fd, buff, 10000);
		temp = saved;
		if (i != 0)
		{
			saved = ft_strjoin(saved, buff);
			free(temp);
		}
	}
	free(buff);
	return (saved);
}
