/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsatge <dsatge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:11:39 by dsatge            #+#    #+#             */
/*   Updated: 2024/06/26 16:04:52 by dsatge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	p_move(int keycode, t_game *game)
{
	void	*img;

	img = NULL;
	if ((keycode == 1) && (game->map_tab[game->p_position_y - 1]
			[game->p_position_x] != '1'))
		up_move(game);
	else if ((keycode == -1) && (game->map_tab[game->p_position_y + 1]
			[game->p_position_x] != '1'))
		down_move(game);
	else if ((keycode == 2) && (game->map_tab[game->p_position_y]
			[game->p_position_x + 1] != '1'))
		right_move(game);
	else if ((keycode == -2) && (game->map_tab[game->p_position_y]
			[game->p_position_x - 1] != '1'))
		left_move(game);
	if (game->p_position_x == game->exit_x && game->p_position_y
		== game->exit_y)
		win_over(game);
}

void	up_move(t_game *game)
{
	if (game->map_tab[game->p_position_y - 1][game->p_position_x] != '1')
	{
		if (game->map_tab[game->p_position_y - 1][game->p_position_x] == 'C')
			game->collectible--;
		if (game->collectible == 0)
			img_and_transp(game, "sprites/e_house/house_open.xpm", game->exit_y,
				game->exit_x);
		if (game->map_tab[game->p_position_y - 1][game->p_position_x] == 'T')
			move_trap(game, game->p_position_x, game->p_position_y, 1);
		if (game->map_tab[game->p_position_y - 1][game->p_position_x] != 'E' ||
			(game->map_tab[game->p_position_y - 1][game->p_position_x] == 'E'
			&& game->collectible == 0))
		{
			game->map_tab[game->p_position_y][game->p_position_x] = '0';
			img_and_transp(game, "sprites/0_ground/ground.xpm",
				game->p_position_y, game->p_position_x);
			game->p_position_y--;
			game->map_tab[game->p_position_y][game->p_position_x] = 'P';
			img_and_transp(game, "sprites/p_wolf/wolf_r.xpm",
				game->p_position_y, game->p_position_x);
			step_status(game);
		}
	}
}

void	down_move(t_game *game)
{
	if (game->map_tab[game->p_position_y + 1][game->p_position_x] != '1')
	{
		if (game->map_tab[game->p_position_y + 1][game->p_position_x] == 'C')
			game->collectible--;
		if (game->collectible == 0)
			img_and_transp(game, "sprites/e_house/house_open.xpm",
				game->exit_y, game->exit_x);
		if (game->map_tab[game->p_position_y + 1][game->p_position_x] == 'T')
			move_trap(game, game->p_position_x, game->p_position_y, -1);
		if (game->map_tab[game->p_position_y + 1][game->p_position_x] != 'E' ||
			(game->map_tab[game->p_position_y + 1][game->p_position_x] == 'E'
			&& game->collectible == 0))
		{
			game->map_tab[game->p_position_y][game->p_position_x] = '0';
			img_and_transp(game, "sprites/0_ground/ground.xpm",
				game->p_position_y, game->p_position_x);
			game->p_position_y++;
			game->map_tab[game->p_position_y][game->p_position_x] = 'P';
			img_and_transp(game, "sprites/p_wolf/wolf_l.xpm",
				game->p_position_y, game->p_position_x);
			step_status(game);
		}
	}
}

void	left_move(t_game *game)
{
	if (game->map_tab[game->p_position_y][game->p_position_x - 1] != '1')
	{
		if (game->map_tab[game->p_position_y][game->p_position_x - 1] == 'C')
			game->collectible--;
		if (game->collectible == 0)
			img_and_transp(game, "sprites/e_house/house_open.xpm",
				game->exit_y, game->exit_x);
		if (game->map_tab[game->p_position_y][game->p_position_x - 1] == 'T')
			move_trap(game, game->p_position_x, game->p_position_y, -2);
		if (game->map_tab[game->p_position_y][game->p_position_x - 1] != 'E' ||
			(game->map_tab[game->p_position_y][game->p_position_x - 1] == 'E'
			&& game->collectible == 0))
		{
			game->map_tab[game->p_position_y][game->p_position_x] = '0';
			img_and_transp(game, "sprites/0_ground/ground.xpm",
				game->p_position_y, game->p_position_x);
			game->p_position_x--;
			game->map_tab[game->p_position_y][game->p_position_x] = 'P';
			img_and_transp(game, "sprites/p_wolf/wolf_l.xpm",
				game->p_position_y, game->p_position_x);
			step_status(game);
		}
	}
}

void	right_move(t_game *game)
{
	if (game->map_tab[game->p_position_y][game->p_position_x + 1] != '1')
	{	
		if (game->map_tab[game->p_position_y][game->p_position_x + 1] == 'C')
			game->collectible--;
		if (game->collectible == 0)
			img_and_transp(game, "sprites/e_house/house_open.xpm",
				game->exit_y, game->exit_x);
		if (game->map_tab[game->p_position_y][game->p_position_x + 1] == 'T')
			move_trap(game, game->p_position_x, game->p_position_y, 2);
		if (game->map_tab[game->p_position_y][game->p_position_x + 1] != 'E' ||
			(game->map_tab[game->p_position_y][game->p_position_x + 1] == 'E'
			&& game->collectible == 0))
		{
			game->map_tab[game->p_position_y][game->p_position_x] = '0';
			img_and_transp(game, "sprites/0_ground/ground.xpm",
				game->p_position_y, game->p_position_x);
			game->p_position_x++;
			game->map_tab[game->p_position_y][game->p_position_x] = 'P';
			img_and_transp(game, "sprites/p_wolf/wolf_r.xpm",
				game->p_position_y, game->p_position_x);
			step_status(game);
		}
	}
}
