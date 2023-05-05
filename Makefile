# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/26 07:08:10 by tde-souz          #+#    #+#              #
#    Updated: 2023/05/03 15:07:14 by tde-souz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ******************************************************************************
# *									SETTINGS								   *
# ******************************************************************************
NAME		:=	cub3d

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
LDFLAGS		=	-L ${MLX_DIR} -l mlx -L libft/ -l ft -lXext -lX11 -lm -lz -O3
TITLE		:=	"Silent Viras [ Linux edition ]"
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
				srcs/main.c

# ******************************************************************************
# *								   SOURCE FILES								   *
# ******************************************************************************
OBJS		=	$(SRCS:.c=.o)

# ********************************************************************************
#                                      RULES                                     *
# ********************************************************************************
all:		${NAME}

${NAME}:	${LIBFT_DIR}${LIBFT}.a ${MLX_DIR}${MLX}.a ${OBJS}
ifeq (${CURRENT_OS}, Linux)
		${CC} ${CFLAGS} ${OBJS} ${LDFLAGS} -o ${NAME}
else
		${CC} ${CFLAGS} ${LDFLAGS} ${OBJS} -o ${NAME}
endif

${LIBFT_DIR}${LIBFT}.a:
	make -C ${LIBFT_DIR} extra

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
