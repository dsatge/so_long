# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsatge <dsatge@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 14:01:22 by dsatge            #+#    #+#              #
#    Updated: 2024/06/26 19:17:25 by dsatge           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = so_long_bonus

C_FILES = main.c\
	  valid_size_map.c\
	  error_parsing.c\
	  image_list.c\
	  click_action.c\
	  move_set.c\
	  win_game.c\
	  lose_game.c\
	  utils.c\
	  free.c

C_FILES_SIMP = valid_map.c\
		map_doable.c\
		graphic_interface.c

C_FILES_BONUS = valid_map_bonus.c\
		map_doable_bonus.c\
		graphic_interface_bonus.c

FLAGS = -Wall -Werror -Wextra -I includes/ -g

LIB = libft/libft.a printf/libftprintf.a mlx/libmlx.a

DEPS = $(addprefix lib/,${LIB:%.c=%.o})

simple: ${NAME}

${NAME} : ${C_FILES} ${C_FILES_SIMP}
	make -C lib/mlx
	make -C lib/libft
	make -C lib/printf
	cc ${FLAGS} ${C_FILES} ${C_FILES_SIMP} -L lib/mlx -l mlx -I mlx -lXext -lX11 -lm -lz -o ${NAME} ${DEPS}

bonus: ${NAME_BONUS}

${NAME_BONUS} : ${C_FILES} ${C_FILES_BONUS}
	make -C lib/mlx
	make -C lib/libft
	make -C lib/printf
	cc ${FLAGS} ${C_FILES} ${C_FILES_BONUS} -L lib/mlx -l mlx -I mlx -lXext -lX11 -lm -lz -o ${NAME_BONUS} ${DEPS}

clean:
	make -C lib/mlx clean
	make -C lib/libft clean
	make -C lib/printf clean

fclean: clean
	rm -rf ${NAME}
	rm -rf ${NAME_BONUS}

fcleansimp: clean
	rm -rf ${NAME}

fcleanbonus: clean
	rm -rf ${NAME_BONUS}

re:	fclean all

.PHONY: all clean fclean re

