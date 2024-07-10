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
	int		i;
	char	*frame;
	int		x;
	int		y;

	i = 1;
	img_disp(game->p_position_x, game->p_position_y,
		"sprites/0_ground/ground.xpm", game);
	while (i <= 4)
	{
		x = (game->tab_x_len / 2) - 1;
		y = (game->tab_y_len / 2) - 1;
		frame = frame_lost(i);
		img_disp(x, y, frame, game);
		free(frame);
		delay();
		i++;
	}
	destroy(game, 1);
	return (0);
}

void	walk_in_trap(t_game *game, int x, int y)
{
	int		i;
	char	*img;

	i = 1;
	img_disp(x, y, "sprites/0_ground/ground.xpm", game);
	while (i < 6)
	{
		img_disp(x, y, "sprites/0_ground/ground.xpm", game);
		img_and_transp(game, "sprites/p_wolf/wolf_r.xpm", y, x);
		img = frame_trap(i);
		img_and_transp(game, img, y, x);
		free(img);
		delay();
		img_disp(x, y, "sprites/0_ground/ground.xpm", game);
		i++;
	}
	game_over(game);
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
