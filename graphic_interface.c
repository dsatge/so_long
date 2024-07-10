/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_interface.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsatge <dsatge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:13:33 by dsatge            #+#    #+#             */
/*   Updated: 2024/06/26 19:14:46 by dsatge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_image(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y <= game->tab_y_len)
	{
		x = 0;
		while (x <= game->tab_x_len)
		{
			img_disp(x, y, "sprites/0_ground/ground.xpm", game);
			get_image2(game, x, y);
			x++;
		}
		y++;
	}
	step_status(game);
}

void	get_image2(t_game *game, int x, int y)
{
	if (game->map_tab[y][x] == '1')
		img_and_transp(game, "sprites/1_wall/tree.xpm", y, x);
	else if (game->map_tab[y][x] == 'C')
		img_and_transp(game, "sprites/c_food/c_redhood.xpm", y, x);
	else if (game->map_tab[y][x] == 'E' && game->collectible > 0)
		img_and_transp(game, "sprites/e_house/house.xpm", y, x);
	else if (game->map_tab[y][x] == 'E' && game->collectible == 0)
		img_and_transp(game, "sprites/e_house/house_open.xpm", y, x);
	else if (game->map_tab[y][x] == 'P')
		img_and_transp(game, "sprites/p_wolf/wolf_r.xpm", y, x);
	else if (game->map_tab[y][x] == 'T')
		img_and_transp(game, "sprites/trap/frame1.xpm", y, x);
}

void	img_and_transp(t_game *game, char *path, int y, int x)
{
	int	pixel;
	int	x_img;
	int	y_img;

	y_img = 0;
	game->image.ptr = mlx_xpm_file_to_image(game->mlx, (char *)path,
			&(game->image.wid), &(game->image.hei));
	game->image.adress = mlx_get_data_addr(game->image.ptr, &game->image.bpp,
			&game->image.line_len, &game->image.endian);
	while (++y_img < game->image.hei)
	{
		x_img = 0;
		while (++x_img < game->image.wid)
		{
			pixel = *(int *)(game->image.adress + y_img * game->image.line_len
					+ x_img * (game->image.bpp / 8));
			if (pixel != 0x58e87c)
			{
				mlx_pixel_put(game->mlx, game->window, x * 64 + x_img, y * 64
					+ y_img, pixel);
			}
		}
	}
	mlx_destroy_image(game->mlx, game->image.ptr);
}

void	img_disp(int x, int y, char *path, t_game *game)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(game->mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(game->mlx, game->window, img, (x * 64), (y * 64));
	mlx_destroy_image(game->mlx, img);
}

void	step_status(t_game *game)
{
	if (game->step_count > 999999999)
	{
		ft_printf("you walked too much, you died from hunger\n");
		lost_over(game);
	}
	if (game->finish != 1)
		ft_printf("step count : %i\n", game->step_count);
	game->step_count++;
}
