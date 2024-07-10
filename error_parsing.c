/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsatge <dsatge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:44:52 by dsatge            #+#    #+#             */
/*   Updated: 2024/06/27 15:08:36 by dsatge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wr_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (2, &str[i], 1);
		i++;
	}
}

void	error_free_tab(t_game *game, int i)
{
	if (i == 2)
		wr_error("ERROR: Invalid character in map creation\n");
	if (i == 3)
		wr_error("ERROR: Map not set up as a rectangle shape");
	if (i == 4)
		wr_error("ERROR: Map issues, wrong definition of borders");
	if (i == 5)
		wr_error("Error: Map too big for screen display\n");
	if (i == 6)
		wr_error("Error: Map not finishable.\n");
	if (i > 1)
		tab_free(game->map_tab);
	exit (EXIT_SUCCESS);
}

void	error_free_line(char *map, int i)
{
	if (i == 1)
		wr_error("Error: Wrong amount of E, P or C in map creation\n");
	if (i == -1)
		wr_error("Error: Empty line in map\n");
	free(map);
	exit (EXIT_SUCCESS);
}

void	error_exit(char *str)
{
	wr_error(str);
	exit (EXIT_SUCCESS);
}
