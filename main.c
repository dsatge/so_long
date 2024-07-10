/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsatge <dsatge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:26:11 by dsatge            #+#    #+#             */
/*   Updated: 2024/07/03 12:20:20 by dsatge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_printf("%s\n", tab[i]);
		i++;
	}
}

int	arg_check(char *arg)
{
	int		len;
	int		i;
	char	*format;
	int		fd;

	i = 3;
	len = ft_strlen(arg) - 1;
	format = ".ber";
	fd = open(arg, __O_DIRECTORY);
	if (fd != -1)
		error_exit("Error: map directory not file\n");
	while (i > 0)
	{
		if (arg[len] != format[i])
			error_exit("Error: Argument not valid\n");
		i--;
		len--;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;
	char	*map;

	if (argc != 2 || arg_check(argv[1]) == 1)
		return (0);
	img_valid(&game, 0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit("Error: open of fd failed\n");
	map = map_read(fd);
	if (!map)
		error_exit("Error: failur in map creation\n");
	valid_map(map, &game);
	game.step_count = 999999996;
	game.mlx = mlx_init();
	if (game.mlx == 0)
		error_exit("Error: mlx_init failur\n");
	game.window = mlx_new_window(game.mlx, ft_strlen(game.map_tab[0]) * 64,
			ft_count_line_split(game.map_tab) * 64, "so_long");
	get_image(&game);
	mlx_hook(game.window, 2, 1L, &click_act, &game);
	mlx_hook(game.window, 17, 1L << 17, &destroy, &game);
	mlx_loop(game.mlx);
	free(game.mlx);
	return (0);
}
