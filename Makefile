# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/26 07:08:10 by tde-souz          #+#    #+#              #
#    Updated: 2023/04/28 06:29:25 by tde-souz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ******************************************************************************
# *									SETTINGS								   *
# ******************************************************************************
NAME		:=	cub3d

CURRENT_OS	:=	$(shell uname)
INCLUDES	:=	-I libft/ -I includes -I minilibx/minilibx_mac/
LIBFT_DIR	:=	libft/
LIBFT		:=	libft
MLX_DIR		:=	minilibx/minilibx_mac/
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
else
TITLE		:=	"Silent Viras [ Mac edition ]"
LDFLAGS		=	-L ${MLX_DIR} -l mlx -L libft/ -l ft -framework OpenGL -framework AppKit
endif

# ******************************************************************************
# *								   SOURCE FILES								   *
# ******************************************************************************
SRCS		:=	\
				srcs/init/config_init.c	\
				srcs/init/data_init.c	\
				srcs/init/render_init.c	\
				srcs/main.c

# ******************************************************************************
# *								   SOURCE FILES								   *
# ******************************************************************************
OBJS		=	$(SRCS:.c=.o)

# ********************************************************************************
#                                      RULES                                     *
# ********************************************************************************
all:		${NAME}

#${MLX_DIR}${MLX}.a
${NAME}:	${LIBFT_DIR}${LIBFT}.a  ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}
#	${CC} ${CFLAGS} ${LDFLAGS} ${OBJS} -o ${NAME}

${LIBFT_DIR}${LIBFT}.a:
	make -C ${LIBFT_DIR}

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

.PHONY: all clean fclean re
