/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsatge <dsatge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:12:14 by dsatge            #+#    #+#             */
/*   Updated: 2024/06/26 16:40:09 by dsatge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_over(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	ft_printf("You won!\n");
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
	mlx_loop_hook(game->mlx, win_animation, game);
}

int	win_animation(t_game *game)
{
	int		i;
	char	*frame;
	int		x;
	int		y;

	i = 1;
	while (i <= 8)
	{
		x = (game->tab_x_len / 2) - 1;
		y = (game->tab_y_len / 2) - 1;
		frame = frame_win(i);
		img_disp(x, y, frame, game);
		free(frame);
		delay();
		i++;
	}
	destroy(game, 0);
	return (0);
}

char	*frame_win(int i)
{
	char	*frame;

	frame = NULL;
	if (i == 1)
		frame = ft_strdup("sprites/you_won/frame1.xpm");
	else if (i == 2)
		frame = ft_strdup("sprites/you_won/frame2.xpm");
	else if (i == 3)
		frame = ft_strdup("sprites/you_won/frame3.xpm");
	else if (i == 4)
		frame = ft_strdup("sprites/you_won/frame4.xpm");
	else if (i == 5)
		frame = ft_strdup("sprites/you_won/frame1.xpm");
	else if (i == 6)
		frame = ft_strdup("sprites/you_won/frame2.xpm");
	else if (i == 7)
		frame = ft_strdup("sprites/you_won/frame3.xpm");
	else if (i == 8)
		frame = ft_strdup("sprites/you_won/frame4.xpm");
	return (frame);
}
