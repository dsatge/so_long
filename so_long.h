/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsatge <dsatge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:27:03 by dsatge            #+#    #+#             */
/*   Updated: 2024/06/27 13:01:54 by dsatge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "lib/libft/libft.h"
# include "lib/printf/ft_printf.h"
# include "lib/mlx/mlx.h"
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/cursorfont.h>

// typedef struct s_game s_game;

typedef struct s_image
{
	int		line_len;
	int		wid;
	int		hei;
	int		bpp;
	char	*adress;
	void	*ptr;
	int		endian;
}	t_image;

typedef struct s_game
{
	int		p_position_x;
	int		p_position_y;
	int		exit_x;
	int		exit_y;
	int		exit;
	int		finish;
	int		collectible;
	int		tab_x_len;
	int		tab_y_len;
	int		step_count;
	char	**map_tab;
	void	*mlx;
	void	*window;
	void	*step_disp;
	t_image	image;	
}	t_game;

//MAIN
void	print_tab(char **tab);
//VALID_MAP
void	valid_map(char *map, t_game *game);
int		no_free_space(char *map);
int		check_char(t_game *game);
int		count_status(char *map, t_game *game);
char	*map_read(int fd);
//VALID_SIZE_MAP
int		len_tab(char **map);
int		in_border(char **map, t_game *game);
int		border_1(char *line);
int		check_first_last_1(char *line, int last);
int		screen_size(t_game *game);
//MAP_DOABLE
int		road_check(char **pos, int x, int y, t_game *game);
int		exit_on_road(char **map, int x, int y);
int		road_journey(char **map, t_game *game);
//ERROR_PARSING
void	wr_error(char *str);
void	error_free_tab(t_game *game, int i);
void	error_free_line(char *map, int i);
void	error_exit(char *str);
//image_list
void	img_valid(t_game *game, int i);
int		fd_checker(char *path);
char	*img_path(int i);
char	*img_path1(int i);
char	*img_path2(int i);
//CLICK_ACT
int		click_act(int key_press, t_game *game);
int		destroy(t_game *game, int message);
void	move_trap(t_game *game, int x_init, int y_init, int move);
//MOVE_SET
void	p_move(int keycode, t_game *game);
void	up_move(t_game *game);
void	down_move(t_game *game);
void	left_move(t_game *game);
void	right_move(t_game *game);
//GRAPHIC_INTERFACE
void	get_image(t_game *game);
void	get_image2(t_game *game, int x, int y);
void	img_and_transp(t_game *game, char *path, int y, int x);
void	img_disp(int x, int y, char *path, t_game *game);
void	step_status(t_game *game);
//WIN_GAME
void	win_over(t_game *game);
int		win_animation(t_game *game);
char	*frame_win(int i);
//LOSE_GAME
void	game_over(t_game *game);
int		lost_over(t_game *game);
void	walk_in_trap(t_game *game, int x, int y);
char	*frame_lost(int i);
char	*frame_trap(int i);
//UTILS
int		count_char(char *map, char search);
int		check_0_1(int i);
char	**ft_tabdup(t_game *game);
void	exit_pos(t_game *game);
void	delay(void);
//FREE
void	tab_free(char **tab);
void	free_exit(t_game *game);
#endif
