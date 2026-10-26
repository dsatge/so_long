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
	#ifdef __APPLE__
		if (keycode == 53)
			destroy(game, 3);
		else if (keycode == 13 || keycode == 126)
			p_move(1, game);
		else if (keycode == 1 || keycode == 125)
			p_move(-1, game);
		else if (keycode == 2 || keycode == 124)
			p_move(2, game);
		else if (keycode == 0 || keycode == 123)
			p_move(-2, game);
	#endif
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
	game->stop = 1;
	if (move == 1)
	{
		img_and_transp(game, "sprites/0_ground/ground.xpm", y_init, x_init);
		mlx_loop_hook(game->mlx, walk_in_trap, game) ;
	}
	if (move == -1)
	{
		img_and_transp(game, "sprites/0_ground/ground.xpm", y_init, x_init);
		mlx_loop_hook(game->mlx, walk_in_trap, game) ;
	}
	if (move == 2)
	{
		img_and_transp(game, "sprites/0_ground/ground.xpm", y_init, x_init);
		mlx_loop_hook(game->mlx, walk_in_trap, game) ;
	}
	if (move == -2)
	{
		img_and_transp(game, "sprites/0_ground/ground.xpm", y_init, x_init);
		mlx_loop_hook(game->mlx, walk_in_trap, game) ;
	}
}
