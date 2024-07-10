/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsatge <dsatge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:36:18 by dsatge            #+#    #+#             */
/*   Updated: 2024/06/26 16:05:12 by dsatge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	click_act(int keycode, t_game *game)
{
	if (keycode == 65307)
		destroy(game, 3);
	else if (keycode == 119 || keycode == 65362)
		p_move(1, game);
	else if (keycode == 115 || keycode == 65364)
		p_move(-1, game);
	else if (keycode == 100 || keycode == 65363)
		p_move(2, game);
	else if (keycode == 97 || keycode == 65361)
		p_move(-2, game);
	return (0);
}

int	destroy(t_game *game, int message)
{
	if (!(message == 0 || message == 1))
		ft_printf("Game session: over\n");
	free_exit(game);
	exit(0);
	return (0);
}

void	move_trap(t_game *game, int x_init, int y_init, int move)
{
	if (move == 1)
	{
		img_and_transp(game, "sprites/0_ground/ground.xpm", y_init, x_init);
		game->p_position_y--;
		walk_in_trap(game, game->p_position_x, game->p_position_y);
	}
	if (move == -1)
	{
		img_and_transp(game, "sprites/0_ground/ground.xpm", y_init, x_init);
		game->p_position_y++;
		walk_in_trap(game, game->p_position_x, game->p_position_y);
	}
	if (move == 2)
	{
		img_and_transp(game, "sprites/0_ground/ground.xpm", y_init, x_init);
		game->p_position_x++;
		walk_in_trap(game, game->p_position_x, game->p_position_y);
	}
	if (move == -2)
	{
		img_and_transp(game, "sprites/0_ground/ground.xpm", y_init, x_init);
		game->p_position_x--;
		walk_in_trap(game, game->p_position_x, game->p_position_y);
	}
}
