/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:55:59 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/19 10:50:47 by tde-souz         ###   ########.fr       */
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
// # include "mlx_int.h"
# include "keys.h"
# include "events.h"
# include "colortag.h"

// ****************************************************************************
// *                                  DEFINES                                 *
// ****************************************************************************

# ifndef TITLE
#  define TITLE			"SILENT VIRAS"
# endif

# define SCREEN_OFFSET	800 // could be a screen variable
# define SCREEN_WIDTH	800
# define SCREEN_HEIGHT	600

# define FUNC_TABLE_SIZE 14

# define PANE_AMOUNT	6

/* Size of the boxes drawn by mapdata measured in pixels */
# define BOX_SIZE		16
# define PLAYER_SPEED	40
# define PLAYER_TURN	300

// ****************************************************************************
// *                                   ENUMS                                  *
// ****************************************************************************

enum	e_bool
{
	FALSE = 0,
	TRUE = 1
};

enum	e_skyfloor
{
	SKY = 0,
	FLOOR = 1
};

enum	e_pane_id
{
	MINIMAP = 0,
	FULLSCREEN = 1,
	TOPHALF = 2,
	BOTHALF = 3,
	LWING = 4,
	RWING = 5
};

enum	e_screen_mapping
{
	X = 0,
	Y = 1,
	WIDTH = 2,
	HEIGHT = 3
};

enum	e_texture_paths
{
	NORTH,
	SOUTH,
	WEST,
	EAST
};

enum	e_orientation
{
	PORT = 0,
	STARBOARD = 1
};

enum	e_axis
{
	TOP,
	BOT,
	LEFT,
	RIGHT
};

enum	e_game_state
{
	MENU,
	PLAY,
	PAUSE,
	END	
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
# define STR_SET_SCREEN "Setting up screen data..."
# define STR_SET_SCREEN_S "Successfully screen setup!"
# define STR_SET_SCREEN_F "Failed to create screen configuration."
# define STR_SET_PANE "Splitting screen into panes..."
# define STR_SET_PANE_S "Successfuly assembling of panes!"
# define STR_SET_PANE_F "Failed to properly assemble panes."
# define STR_SET_UI "Configuring the game's UI elements..."
# define STR_SET_UI_S "Successfully configured the game's UI!"
# define STR_SET_UI_F "Failed to configure the UI."
# define STR_SET_WINDOW "Preparing to launch the game window..."
# define STR_SET_WINDOW_S "Successfully launched the game window!"
# define STR_SET_WINDOW_F "Failed to launch the game window."

// ****************************************************************************
// *                                  STRUCTS                                 *
// ****************************************************************************

typedef struct s_rayhit
{
	char	wall;
	double	distance;
	char	*filter;
}	t_rayhit;

typedef struct s_ray
{
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		hit_flag; // needed?
	int		map[2];
	int		step[2];
	double	sideDist[2];
	double	rayDir[2];
	double	deltaDist[2];
	double	perp_wall_dist;
	t_rayhit	hit;
}	t_ray;

typedef struct s_info
{
	int		size[2];
	int		pos[2];
	int		color;
	int		length;
	double	radians;
	double	dir[2];
}	t_info;

typedef struct s_pane
{
	int				min_bounds[2];
	int				max_bounds[2];
	int				offset[2];
	int				size[2];
	double			scale;
	char			*name;
	struct s_screen	*screen;
	struct s_game	*game;
}	t_pane;

typedef struct	s_ui
{
	int		minimap_box_size;
	double	minimap_scale;
}	t_ui;

typedef struct	s_screen
{
	int		bpp;
	int		len;
	int		endian;
	int		size[2];
	char	*addr;
	void	*img;
}	t_screen;


typedef struct s_map
{
	int		trgb[2];
	int		size[2];
	char	*inst_rot;
	char	**map;
	char	**tex_path;
	int		*start_pos;
}	t_map;

typedef struct s_cam
{	
	int		axis[4];
	int		orientation[2];
	int		fov; // probably deprecated
	int		fov_half; // probably deprecated
	double	fov_increment; // probably deprecated
	double	plane[2];
	double	cameraX;
}	t_cam;

typedef struct s_object
{
	char	tag;
	double	rotation;
	double	speed;
	double	turn_rate;
	double	collision;
	double	pos[2];
	double	dir[2];
}	t_obj;

typedef struct s_instance
{
	t_cam	*cam;
	t_obj	*obj;
}	t_inst;

typedef struct s_game
{
	char		enable_parallax;
	int			total_insts;
	int			state;
	double		degtorad;
	void		*mlx;
	void		*win;
	t_ui		*ui;
	t_map		*mapdata;
	t_inst		*inst;
	t_screen	*screen;
	t_pane		**pane;
}	t_game;

// ****************************************************************************
// *                                FUNCTIONS                                 *
// ****************************************************************************

/* Memory and data handlers */

const void	**config_table_builder(void);
void		init_handler(t_game *game);
void		clear_handler(t_game *game, int i);

int			data_init(t_game *game);
void		data_clear(t_game *game);
void		safe_exit(t_game *game);

int			inst_init(t_game *game);
void		inst_clear(t_game *game);
void		set_cam_data(t_game *game, t_inst *inst);
void		set_obj_data(t_game *game, t_inst *inst, int i);

int			map_init(t_game *game);
void		map_clear(t_game *game);

int			screen_init(t_game *game);
void		screen_clear(t_game *game);

int			pane_init(t_game *game);
void		pane_clear(t_game *game);

int			ui_init(t_game *game);
void		ui_clear(t_game *game);

int			window_init(t_game *game);
void		window_clear(t_game *game);
void		setup_controls(t_game *game);


/* Logging */

void		print_log(int n, ...);
int			assert_log(char test, char *str_true, char *str_false);
void		header_log(char *header, char *message, char *color);


/* Drawing */

int			check_bounds(int *pos, int *min, int *max);
void		draw_line_r(t_pane *pane, t_info *info);
void		draw_line_dir(t_pane *pane, t_info *info);
void		draw_rect(t_screen *idata, int *size, int *pos, int color);
void		draw_pixel(t_screen *idata, int *pos, int color);



/* Vectors */

void		vector2(int i, int j, int *target_i, int *target_j);


/* Game Controls */

int			keyboard_onpress(int key, t_game *game);
int			keyboard_onrelease(int key, t_game *game);
int			mouse_onpress(int key, int x, int y, t_game *game);
int			mouse_onrelease(int key, int x, int y, t_game *game);
int			mouse_move(int x, int y, t_game *game);
int			window_onclose(t_game *game);
int			window_onresize(t_game *game);

char		*get_key_name(int value);
int			get_key_value(char* name);


/* Commands */

void		cmd_chdir_two(t_game *game, int key, char pressed);
void		cmd_chdir_four(t_game *game, int key, char pressed);
void		cmd_chrot(t_game *game, int key, char pressed);


/* Behaviours */
void		player_move_rot(t_game *game, t_inst *inst);


/* Pane System */

t_pane		*create_pane(t_game *game, char *name);
void		pane_setdata(t_pane *pane, int *size, int *offset);
void		pane_setdata_ratio(t_pane *pane, int *size,	double ratio_x,
				double ratio_y);

/* UI */

double		get_minimap_scale(t_game *game, t_pane *pane);
void		map_topixel(t_pane *pane, int *pos, int *pixel);
int			map_getpixel_x(t_pane *pane, int x);
int			map_getpixel_y(t_pane *pane, int y);


/* Rendering */

int			render_game(t_game *game);
void		render_fov(t_game *game);
void		render_skyfloor(t_game *game);
void		render_minimap(t_game *game);

/* Raycasting */

t_rayhit	*ray(t_game *game, t_inst *inst, t_pane *pane, double cameraX, int w);
t_rayhit	*ray2(t_game *game, t_inst *inst, t_pane *pane);


/* Other */

int			loop_handler(t_game *game);

#endif