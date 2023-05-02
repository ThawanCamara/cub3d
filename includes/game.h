/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:55:59 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/02 14:08:33 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

// ****************************************************************************
// *                                  INCLUDES                                *
// ****************************************************************************

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include "colortag.h"

// ****************************************************************************
// *                                  DEFINES                                 *
// ****************************************************************************

# ifndef TITLE
#  define TITLE			"SILENT VIRAS"
# endif

# define SCREEN_OFFSET	800
# define SCREEN_WIDTH	1600
# define SCREEN_HEIGHT	600

# define FUNC_TABLE_SIZE 6

// ****************************************************************************
// *                                   ENUMS                                  *
// ****************************************************************************

enum	e_screen_mapping
{
	X = 0,
	Y = 1,
	WIDTH = 2,
	HEIGHT = 3
};

// ****************************************************************************
// *                                  STRINGS                                 *
// ****************************************************************************

# define STR_SUCCESS "SUCCESS"
# define STR_FAILURE "FAILURE"
# define STR_MLX_CONNECT "Connecting MLX..."
# define STR_MLX_CONNECT_S "Successfully connected to mlx!"
# define STR_MLX_CONNECT_F "Failed to connect to mlx."
# define STR_BUILD_DATA "Initializing game data..."
# define STR_BUILD_DATA_S "Successfully initialized game data!"
# define STR_BUILD_DATA_F "Failed to initialize game data."
# define STR_BUILD_MAP "Building map data..."
# define STR_BUILD_MAP_S "Successfully built map data!"
# define STR_BUILD_MAP_F "Failed to build map data."
# define STR_SET_INST "Creating game instances..."
# define STR_SET_INST_S "Successfully created game instances!"
# define STR_SET_INST_F "Failed to create game instances."
# define STR_SET_RENDER "Setting up rendering data..."
# define STR_SET_RENDER_S "Successfully rendering setup!"
# define STR_SET_RENDER_F "Failed to properly render data."

// ****************************************************************************
// *                                  STRUCTS                                 *
// ****************************************************************************

typedef struct	s_imgdata {
	void	*img;
	char	*addr;
	unsigned int	*addr2;
	unsigned long	*addr3;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_imgdata;

/* typedef struct s_ray
{

}	t_ray; */

typedef struct s_map
{
	char	**map;
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	// int		bound_X;
	// int		bound_Y;
	char	*inst_rot;
}	t_map;

typedef struct s_cam
{	
	double	rotation;
	double	collision;
	double	pos[2];
}	t_cam;

typedef struct s_instance
{
	double		start_rotation;
	t_cam		*cam;
}	t_inst;

typedef struct s_game
{
	short		total_insts;
	char		enable_parallax;
	void		*mlx;
	void		*win;
	t_map		*mapdata;
	t_inst		*inst;
	t_imgdata	*imgdata;
}	t_game;

const void	**config_table_builder(void);
void		init_handler(t_game *game);
void		clear_handler(t_game *game, int i);

int			data_init(t_game *game);
void		data_clear(t_game *game);
void		safe_exit(t_game *game);

int			inst_init(t_game *game);
void		inst_clear(t_game *game);

int			map_init(t_game *game);
void		map_clear(t_game *game);

int			render_init(t_game *game);
void		render_clear(t_game *game);

void		print_log(int n, ...);
void		condition_log(char test, char *str_true, char *str_false);
void		header_log(char *header, char *message, char *color);


/* Drawing Functions */
void	draw_rect(t_game *game, int *size, int *pos, int color);

#endif