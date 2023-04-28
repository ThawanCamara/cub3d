# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/27 11:08:47 by tde-souz          #+#    #+#              #
#    Updated: 2023/04/27 11:11:51 by tde-souz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NOM		=	libmlx.a
SRC		=	\
			mlx_shaders.c	\
			mlx_new_window.m	\
			mlx_init_loop.m	\
			mlx_new_image.m	\
			mlx_xpm.c	\
			mlx_int_str_to_wordtab.c	\
			mlx_png.c	\
			mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11 -w

#colorscheme
LIME=\033[38;5;118m
FUSCHIA=\033[38;5;214m
RESET=\033[0m

all: $(NOM)

$(NOM):	$(OBJ)
	@ar -r $(NOM) $(OBJ)
	@ranlib $(NOM)
	@printf "$(LIME)Done$(RESET) - MinilibX [$(FUSCHIA) mac $(RESET)] ready to use."

clean:
	rm -f $(OBJ) *~

fclean: clean
	${RM} ${NOM}
	rm -f mlx_app

re: clean all

.PHONY: all clean fclean re
