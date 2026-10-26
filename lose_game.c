/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lose_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsatge <dsatge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:12:33 by dsatge            #+#    #+#             */
/*   Updated: 2024/06/26 16:38:50 by dsatge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_over(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	ft_printf("You lose!\n");
	game->finish = 1;
	while (game->map_tab[y])
	{
		x = 0;
		while (game->map_tab[y][x])
		{
			img_disp(x, y, "sprites/0_ground/ground.xpm", game);
			x++;
		}
		y++;
	}
	mlx_loop_hook(game->mlx, lost_over, game);
}

int	lost_over(t_game *game)
{
	static int		lostframe_i = 1;
	static int time = 0;
	char	*frame;
	int		x;
	int		y;

	if (time++ < 2400)
		return (0);
	time = 0;
	if (lostframe_i > 5)
	{
		destroy(game, 1);
		return (0);
	}
	img_disp(game->p_position_x, game->p_position_y,
		"sprites/0_ground/ground.xpm", game);

	x = (game->tab_x_len / 2) - 1;
	y = (game->tab_y_len / 2) - 1;
	frame = frame_lost(lostframe_i);
	img_disp(x, y, frame, game);
	lostframe_i++;
	free(frame);
	return (0);
}

int	walk_in_trap(t_game *game)
{
	static int	trap_i = 1;
	static int	time_trap = 0;
	char	*img;

	if (time_trap++ < 2000)
		return (0);
	time_trap = 0;
	if (trap_i > 5)
	{
		game_over(game);
		return (0);
	}
	img_disp(game->p_position_x, game->p_position_y, "sprites/0_ground/ground.xpm", game);
	img_and_transp(game, "sprites/p_wolf/wolf_r.xpm", game->p_position_y, game->p_position_x);
	img = frame_trap(trap_i);
	img_and_transp(game, img, game->p_position_y, game->p_position_x);
	if (img)
	{
		img_and_transp(game, img, game->p_position_y, game->p_position_x);
		free(img);
	}
	trap_i++;
	return (0);
}

char	*frame_lost(int i)
{
	char	*frame;

	frame = NULL;
	if (i == 1)
		frame = ft_strdup("sprites/game_over/frame1.xpm");
	else if (i == 2)
		frame = ft_strdup("sprites/game_over/frame2.xpm");
	else if (i == 3)
		frame = ft_strdup("sprites/game_over/frame3.xpm");
	else if (i == 4)
		frame = ft_strdup("sprites/game_over/frame4.xpm");
	else if (i == 5)
		frame = ft_strdup("sprites/game_over/frame4.xpm");
	return (frame);
}

char	*frame_trap(int i)
{
	char	*frame;

	frame = NULL;
	if (i == 1)
		frame = ft_strdup("sprites/trap/frame1.xpm");
	if (i == 2)
		frame = ft_strdup("sprites/trap/frame2.xpm");
	if (i == 3)
		frame = ft_strdup("sprites/trap/frame3.xpm");
	if (i == 4)
		frame = ft_strdup("sprites/trap/frame4.xpm");
	if (i == 5)
		frame = ft_strdup("sprites/trap/frame5.xpm");
	return (frame);
}
