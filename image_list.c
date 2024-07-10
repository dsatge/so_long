/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsatge <dsatge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:06:22 by dsatge            #+#    #+#             */
/*   Updated: 2024/06/27 15:08:20 by dsatge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_valid(t_game *game, int i)
{
	ft_bzero(game, sizeof(t_game));
	if (fd_checker(img_path2(i)) == -1)
	{
		wr_error("Error: Image missing /group 2");
		exit (EXIT_SUCCESS);
	}
	while (i <= 9)
	{
		if (fd_checker(img_path(i)) == -1)
		{
			wr_error("Error: Image missing /group 0");
			exit (EXIT_SUCCESS);
		}
		if (fd_checker(img_path1(i)) == -1)
		{
			wr_error("Error: Image missing /group 1");
			exit (EXIT_SUCCESS);
		}
		i++;
	}
}

int	fd_checker(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	free(path);
	return (fd);
}

char	*img_path(int i)
{
	char	*path;

	path = NULL;
	if (i == 0)
		path = ft_strdup("sprites/0_ground/ground.xpm");
	else if (i == 1)
		path = ft_strdup("sprites/1_wall/tree.xpm");
	else if (i == 2)
		path = ft_strdup("sprites/c_food/c_redhood.xpm");
	else if (i == 3)
		path = ft_strdup("sprites/e_house/house.xpm");
	else if (i == 4)
		path = ft_strdup("sprites/e_house/house_open.xpm");
	else if (i == 5)
		path = ft_strdup("sprites/extra/sheet1.xpm");
	else if (i == 6)
		path = ft_strdup("sprites/game_over/frame1.xpm");
	else if (i == 7)
		path = ft_strdup("sprites/game_over/frame2.xpm");
	else if (i == 8)
		path = ft_strdup("sprites/game_over/frame3.xpm");
	else if (i == 9)
		path = ft_strdup("sprites/game_over/frame4.xpm");
	return (path);
}

char	*img_path1(int i)
{
	char	*path;

	path = NULL;
	if (i == 0)
		path = ft_strdup("sprites/p_wolf/wolf_l.xpm");
	else if (i == 1)
		path = ft_strdup("sprites/p_wolf/wolf_r.xpm");
	else if (i == 2)
		path = ft_strdup("sprites/trap/frame1.xpm");
	else if (i == 3)
		path = ft_strdup("sprites/trap/frame2.xpm");
	else if (i == 4)
		path = ft_strdup("sprites/trap/frame3.xpm");
	else if (i == 5)
		path = ft_strdup("sprites/trap/frame4.xpm");
	else if (i == 6)
		path = ft_strdup("sprites/trap/frame5.xpm");
	else if (i == 7)
		path = ft_strdup("sprites/you_won/frame1.xpm");
	else if (i == 8)
		path = ft_strdup("sprites/you_won/frame2.xpm");
	else if (i == 9)
		path = ft_strdup("sprites/you_won/frame3.xpm");
	return (path);
}

char	*img_path2(int i)
{
	char	*path;

	path = NULL;
	if (i == 0)
		path = ft_strdup("sprites/you_won/frame4.xpm");
	return (path);
}
