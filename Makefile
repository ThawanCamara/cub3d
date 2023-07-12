# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/26 07:08:10 by tde-souz          #+#    #+#              #
#    Updated: 2023/07/12 12:45:09 by tde-souz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ******************************************************************************
# *									SETTINGS								   *
# ******************************************************************************
NAME		:=	cub3D

CURRENT_OS	:=	$(shell uname)
INCLUDES	=	-I libft/ -I includes 
LIBFT_DIR	:=	libft/
LIBFT		:=	libft
MLX			:=	libmlx

# ******************************************************************************
# *								   TEXT COLORS								   *
# ******************************************************************************
GREEN		:=	\e[38;5;118m
GOLD		:=	\e[38;5;220m
RESET		:=	\e[0m
BOLD		:=	\e[1m

# ******************************************************************************
# *								 COMPILATION FLAGS							   *
# ******************************************************************************
CC			:=	cc
CFLAGS		=	-Wall -Wextra -Werror -g $(INCLUDES) -DTITLE='${TITLE}'

ifeq ($(CURRENT_OS), Linux)
CFLAGS		+=	-fPIE
TITLE		:=	"Silent Viras [ Linux edition ]"
LDFLAGS		=	-L ${MLX_DIR} -l mlx -L libft/ -l ft -lXext -lX11 -lm -lz -O3
INCLUDES	+=	-I minilibx/minilibx_linux/
MLX_DIR		=	minilibx/minilibx_linux/
else
TITLE		:=	"Silent Viras [ Mac edition ]"
LDFLAGS		=	-L ${MLX_DIR} -l mlx -L libft/ -l ft -framework OpenGL -framework AppKit
INCLUDES	+=	-I minilibx/minilibx_mac/
MLX_DIR		=	minilibx/minilibx_mac/
endif

# ******************************************************************************
# *								   SOURCE FILES								   *
# ******************************************************************************
SRCS		:=	\
				srcs/init/config_init.c	\
				srcs/init/data_init.c	\
				srcs/init/map_init.c	\
				srcs/init/inst_init.c	\
				srcs/utils/log.c	\
				srcs/draw/draw_rect.c	\
				srcs/draw/check_bounds.c	\
				srcs/controls/keyboard_controls.c	\
				srcs/controls/mouse_controls.c	\
				srcs/controls/window_controls.c	\
				srcs/controls/keymapper.c	\
				srcs/controls/setup_controls.c	\
				srcs/draw/draw_pixel.c	\
				srcs/draw/vector_utils.c	\
				srcs/draw/draw_line.c	\
				srcs/init/screen_init.c	\
				srcs/init/pane_init.c	\
				srcs/init/window_init.c	\
				srcs/init/pane_utils.c	\
				srcs/utils/ui.c	\
				srcs/init/ui_init.c	\
				srcs/render/fov.c	\
				srcs/render/minimap.c	\
				srcs/render/render.c	\
				srcs/behaviour/navigation.c	\
				srcs/commands/change_dir.c	\
				srcs/commands/change_rot.c	\
				srcs/init/inst_utils.c	\
				srcs/utils/loop_handler.c	\
				srcs/render/skyfloor.c	\
				srcs/raycaster/ray.c	\
				srcs/debug/debug_ray.c	\
				srcs/validation/data_textures.c	\
				srcs/validation/data_skyfloor.c	\
				srcs/validation/input_args.c	\
				srcs/validation/map_loader.c	\
				srcs/validation/map_read_loop.c	\
				srcs/validation/build_map.c	\
				srcs/validation/build_checker.c	\
				srcs/validation/validation_utils.c	\
				srcs/validation/extra_val.c	\
				srcs/render/textures.c	\
				srcs/raycaster/ray_utils.c	\
				srcs/main.c

# ******************************************************************************
# *								   OBJECT FILES								   *
# ******************************************************************************
OBJS		=	$(SRCS:.c=.o)
# ********************************************************************************
#                                     RULES                                    *
# ******************************************************************************
all:		${NAME}

${NAME}:	${LIBFT_DIR}${LIBFT}.a ${MLX_DIR}${MLX}.a ${OBJS}
ifeq (${CURRENT_OS}, Linux)
		${CC} ${CFLAGS} ${OBJS} ${LDFLAGS} -o ${NAME}
else
		${CC} ${CFLAGS} ${LDFLAGS} ${OBJS} -o ${NAME}
endif

${LIBFT_DIR}${LIBFT}.a:
	make -s -C ${LIBFT_DIR} extra

${MLX_DIR}${MLX}.a:
	make -C ${MLX_DIR}

clean:
	${RM} ${OBJS}

fclean:		clean
	make -C ${LIBFT_DIR} fclean
	make -C ${MLX_DIR} clean
	${RM} -r ${NAME}.dSYM
	${RM} ${NAME}

re:			fclean all

leak:
	@make && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME}

.PHONY: all clean fclean re leak
