/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_doable_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsatge <dsatge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:14:26 by dsatge            #+#    #+#             */
/*   Updated: 2024/06/26 17:25:37 by dsatge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	road_check(char **pos, int x, int y, t_game *game)
{
	static int	c;
	static int	e;
	static int	road;

	if (pos[y][x] == 'C')
		c++;
	if (e == 0)
		e = exit_on_road(pos, x, y);
	if (c == game->collectible && e == 1)
		road = 1;
	pos[y][x] = '1';
	if (pos[y + 1][x] != '1' && pos[y + 1][x] != 'E')
		road_check(pos, x, (y + 1), game);
	if (pos[y - 1][x] != '1' && pos[y - 1][x] != 'E')
		road_check(pos, x, (y - 1), game);
	if (pos[y][x + 1] != '1' && pos[y][x + 1] != 'E')
		road_check(pos, (x + 1), y, game);
	if (pos[y][x - 1] != '1' && pos[y][x - 1] != 'E')
		road_check(pos, (x - 1), y, game);
	return (road);
}

int	exit_on_road(char **map, int x, int y)
{
	if (map[y][x + 1] == 'E')
		return (1);
	if (map[y][x - 1] == 'E')
		return (1);
	if (map[y + 1][x] == 'E')
		return (1);
	if (map[y - 1][x] == 'E')
		return (1);
	else
		return (0);
}

int	road_journey(char **map, t_game *game)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = game->p_position_x;
	y = game->p_position_y;
	i = road_check(map, x, y, game);
	return (i);
}
