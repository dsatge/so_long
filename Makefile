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

C_FILES = main.c\
	  valid_size_map.c\
	  error_parsing.c\
	  image_list.c\
	  click_action.c\
	  move_set.c\
	  win_game.c\
	  lose_game.c\
	  utils.c\
	  free.c\
	  valid_map_bonus.c\
	  map_doable_bonus.c\
	  graphic_interface_bonus.c


UNAME_S = $(shell uname -s)

ifeq ($(UNAME_S), Darwin)
	MLX = lib/mlx_mac
	MLX_A = $(MLX)/libmlx.a
	LIBFT = lib/libft/libft.a
	PRINTF = lib/printf/libftprintf.a
	MLXFLAG = -L$(MLX) -lmlx -framework OpenGL -framework AppKit

else ifeq ($(UNAME_S), Linux)
	MLX = lib/mlx_linux
	MLX_A = $(MLX)/libmlx.a
	LIBFT = lib/libft/libft.a
	PRINTF = lib/printf/libftprintf.a
	MLXFLAG =  -L$(MLX) -lmlx -lXext -lX11 -lm -lz

else
	$(error OS non supporte : $(UNAME_S). Utilisez macOS ou Linux / WSL.)
endif

CC = cc

CFLAGS = -Wall -Werror -Wextra -Iincludes -isystem $(MLX)

OBJS = $(C_FILES:.c=.o)

$(LIBFT):
	$(MAKE) -C lib/libft

$(PRINTF):
	$(MAKE) -C lib/printf

$(MLX_A):
	$(MAKE) -C $(MLX) > /dev/null 2>&1

all: ${NAME}

${NAME} : ${OBJS} ${MLX_A} ${LIBFT} ${PRINTF}
	${CC} ${OBJS} ${LIBFT} ${PRINTF} ${MLX_A} ${MLXFLAG} ${CFLAGS} -o ${NAME}

clean:
	make -C ${MLX} clean
	make -C lib/libft clean
	make -C lib/printf clean
	rm -f ${OBJS}

fclean: clean
	$(MAKE) -C lib/libft fclean
	$(MAKE) -C lib/printf fclean
	rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re $(LIBFT) $(PRINTF) $(MLX_A)

