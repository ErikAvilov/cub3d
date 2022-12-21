# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 21:52:54 by eavilov           #+#    #+#              #
#    Updated: 2022/12/21 15:05:38 by eavilov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

BLACK=\033[30m
RED=\033[31m
GREEN=\033[32m
YELLOW=\033[33m
BLUE=\033[34m
PURPLE=\033[35m
CYAN=\033[36m
WHITE=\033[37m
ERASE=\033[2K\r
RESET=\033[0m
BOLD=\033[1m
FAINT=\033[2m
ITALIC=\033[3m
UNDERLINE=\033[4m

#--------------------------------------------------------#
#						--FILES--						 #
#--------------------------------------------------------#

NAME	= cub3d

MAIN	= srcs/main.c

SRCS	= $(MAIN) \
		srcs/mlx_init.c \
		srcs/pressing.c \
		srcs/bresenham.c \
		srcs/loop.c \
		srcs/misc.c \
		srcs/rays_algo.c \
		srcs/drawings.c \
		srcs/mouse.c \
		srcs/rays.c \
		srcs/dda.c \
		srcs/dda_init.c \
		srcs/player_collision.c \
		srcs/player_movement.c \
		srcs/player_rotation.c \
		srcs/algo_stuff.c \
		srcs/bs_formulas.c \
		srcs/parsing.c \
		srcs/parsing_check.c \
		srcs/parsing_color.c \
		srcs/parsing_map.c \
		srcs/parsing_texture_ea_we.c \
		srcs/parsing_texture_no_so.c \
		srcs/free_map.c \
		srcs/free_texture.c \
		srcs/strcomplete.c

HEADER	= srcs/cub3d.h \
		srcs/functions.h \
		srcs/defines.h
		
LIBFT	= my_libft/libft.a

#--------------------------------------------------------#
#				--	SOME OTHER BULLSHIT IDK	--			 #
#--------------------------------------------------------#

OBJS	= $(patsubst srcs/%.c, objs/%.o, $(SRCS))
MLX		= -I libx/minilibx_opengl_20191021/ -framework OpenGL -framework AppKit
LIBMLX 	= libx/minilibx_opengl_20191021/libmlx.a
CFLAGS	=
CC		= gcc
RM		= rm -rf

all:	${NAME} ${LIBFT}

${NAME}:	${OBJS} ${HEADER} ${LIBFT} Makefile
	${MAKE} -C libx/minilibx_opengl_20191021
	${CC} ${CFLAGS} ${MLX} ${OBJS} ${LIBMLX} ${LIBFT} -o $@
	printf "${ERASE}${FAINT}${CC} ${CFLAGS} -c -o ${RESET} ${CYAN} ${BOLD}$@ ${RESET} ${FAINT} ${BLUE}$< ${RESET}"

objs/%.o : srcs/%.c ${HEADER}
	$(CC) -c -o $@ $< $(CFLAGS)
	printf "${ERASE} ${FAINT} ${CC} ${CFLAGS} -c -o ${RESET} ${CYAN} ${BOLD}$@ ${RESET} ${FAINT} ${BLUE}$< ${RESET}"

${LIBFT}:	my_libft/Makefile
	$(MAKE) -j 3 -C my_libft/
	

#--------------------------------------------------------#
#					--	 MAKE COMMANDS	--			 	 #
#--------------------------------------------------------#

clean:
	${RM} ${OBJS} ${LIBMLX}
	make clean -C my_libft/

norm: 
	norminette ${SRCS} $(HEADER)

fclean:	clean
	${RM} ${NAME}
	make fclean -C my_libft/

re: fclean all

sus: 
	@echo "⠀⠀⠀⡯⡯⡾⠝⠘⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢊⠘⡮⣣⠪⠢⡑⡌"
	@echo "⠀⠀⠀⠟⠝⠈⠀⠀⠀⠡⠀⠠⢈⠠⢐⢠⢂⢔⣐⢄⡂⢔⠀⡁⢉⠸⢨⢑⠕⡌"
	@echo "⠀⠀⡀⠁⠀⠀⠀⡀⢂⠡⠈⡔⣕⢮⣳⢯⣿⣻⣟⣯⣯⢷⣫⣆⡂⠀⠀⢐⠑⡌"
	@echo "⣬⠂⠀⠀⢀⢂⢪⠨⢂⠥⣺⡪⣗⢗⣽⢽⡯⣿⣽⣷⢿⡽⡾⡽⣝⢎⠀⠀⠀⢡"
	@echo "⣿⠀⠀⠀⢂⠢⢂⢥⢱⡹⣪⢞⡵⣻⡪⡯⡯⣟⡾⣿⣻⡽⣯⡻⣪⠧⠑⠀⠁⢐"
	@echo "⣿⠀⠀⠀⠢⢑⠠⠑⠕⡝⡎⡗⡝⡎⣞⢽⡹⣕⢯⢻⠹⡹⢚⠝⡷⡽⡨⠀⠀⢔"
	@echo "⣿⡯⠀⢈⠈⢄⠂⠂⠐⠀⠌⠠⢑⠱⡱⡱⡑⢔⠁⠀⡀⠐⠐⠐⡡⡹⣪⠀⠀⢘"
	@echo "⣿⣽⠀⡀⡊⠀⠐⠨⠈⡁⠂⢈⠠⡱⡽⣷⡑⠁⠠⠑⠀⢉⢇⣤⢘⣪⢽⠀⢌⢎"
	@echo "⣿⢾⠀⢌⠌⠀⡁⠢⠂⠐⡀⠀⢀⢳⢽⣽⡺⣨⢄⣑⢉⢃⢭⡲⣕⡭⣹⠠⢐⢗"
	@echo "⣿⡗⠀⠢⠡⡱⡸⣔⢵⢱⢸⠈⠀⡪⣳⣳⢹⢜⡵⣱⢱⡱⣳⡹⣵⣻⢔⢅⢬⡷"
	@echo "⣷⡇⡂⠡⡑⢕⢕⠕⡑⠡⢂⢊⢐⢕⡝⡮⡧⡳⣝⢴⡐⣁⠃⡫⡒⣕⢏⡮⣷⡟"
	@echo "⣷⣻⣅⠑⢌⠢⠁⢐⠠⠑⡐⠐⠌⡪⠮⡫⠪⡪⡪⣺⢸⠰⠡⠠⠐⢱⠨⡪⡪⡰"
	@echo "⣯⢷⣟⣇⡂⡂⡌⡀⠀⠁⡂⠅⠂⠀⡑⡄⢇⠇⢝⡨⡠⡁⢐⠠⢀⢪⡐⡜⡪⡊"
	@echo "⣿⢽⡾⢹⡄⠕⡅⢇⠂⠑⣴⡬⣬⣬⣆⢮⣦⣷⣵⣷⡗⢃⢮⠱⡸⢰⢱⢸⢨⢌"
	@echo "⣯⢯⣟⠸⣳⡅⠜⠔⡌⡐⠈⠻⠟⣿⢿⣿⣿⠿⡻⣃⠢⣱⡳⡱⡩⢢⠣⡃⠢⠁"
	@echo "⡯⣟⣞⡇⡿⣽⡪⡘⡰⠨⢐⢀⠢⢢⢄⢤⣰⠼⡾⢕⢕⡵⣝⠎⢌⢪⠪⡘⡌⠀"
	@echo "⡯⣳⠯⠚⢊⠡⡂⢂⠨⠊⠔⡑⠬⡸⣘⢬⢪⣪⡺⡼⣕⢯⢞⢕⢝⠎⢻⢼⣀⠀"
	@echo "⠁⡂⠔⡁⡢⠣⢀⠢⠀⠅⠱⡐⡱⡘⡔⡕⡕⣲⡹⣎⡮⡏⡑⢜⢼⡱⢩⣗⣯⣟"
	@echo "⢀⢂⢑⠀⡂⡃⠅⠊⢄⢑⠠⠑⢕⢕⢝⢮⢺⢕⢟⢮⢊⢢⢱⢄⠃⣇⣞⢞⣞⢾"
	@echo "⢀⠢⡑⡀⢂⢊⠠⠁⡂⡐⠀⠅⡈⠪⠪⠪⠣⠫⠑⡁⢔⠕⣜⣜⢦⡰⡎⡯⡾⡽"

.PHONY: re all fclean clean norm sus
