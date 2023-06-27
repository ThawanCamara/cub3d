/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:55:59 by tde-souz          #+#    #+#             */
/*   Updated: 2023/06/27 15:57:37 by tde-souz         ###   ########.fr       */
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
# define MAP_BORDERS	"1 \0"
# define MAP_CONTENT	"10NSWE \0"

/* Size of the boxes drawn by mapdata measured in pixels */
# define BOX_SIZE		16
# define PLAYER_SPEED	20
# define PLAYER_TURN	60

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

enum	e_ray_face
{
	FACE_WEST = 0,
	FACE_EAST =	2,
	FACE_NORTH = 4,
	FACE_SOUTH = 6
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
# define ERR_MAPREAD "An error occurred while reading the map."

// ****************************************************************************
// *                                  STRUCTS                                 *
// ****************************************************************************

typedef struct s_rayhit
{
	int		side;
	int		face;
	int		flag;
	double	distance;
	double	rad;
	double	pos[2];
	double	start[2];
	double	dir[2];
}	t_rayhit;

typedef struct s_ray
{
	int		side;
	int		face;
	int		line_height; //not
	int		draw_start; //not
	int		draw_end; //not
	int		hit_flag; // needed?
	int		map[2];
	int		step[2];
	double	perp_wall_dist; //not
	double	sideDist[2];
	double	dir[2];
	double	deltaDist[2];
	char	*col;
	double	*p;
	int		*f;
	t_rayhit hit;
}	t_ray;

typedef struct s_iray
{
	double	max_len;
	double	rad;
	double	dir[2];
	double	start[2];
	char	*filter;
}	t_iray;

typedef struct s_idraw
{
	int		size[2];
	int		pos[2];
	int		color;
	int		length;
	double	rad;
	double	dir[2];
}	t_idraw;

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
	char	valid_skyfloor[2];
	int		trgb[2];
	int		size[2];
	int		tex_size[4][2];
	char	inst_rot[2];
	char	**map;
	t_screen	*texture;
	int		*start_pos;
}	t_map;

typedef struct s_cam
{	
	int		axis[4];
	int		orientation[2];
	int		fov; // probably deprecated
	int		fov_half; // probably deprecated
	int		fov_sc_half; // probably deprecated
	double	fov_increment; // probably deprecated
	double	view_increment;
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
	char		*mapname;
	void		*mlx;
	void		*win;
	float		zoom;
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
int			error_log(char *msg);


/* Drawing */

int			check_bounds(int *pos, int *min, int *max);
int			check_mapbounds(int *pos, int *bounds);
void		draw_line_r(t_pane *pane, t_idraw *info);
void		draw_line_dir(t_pane *pane, t_idraw *info);
void		draw_rect(t_screen *idata, int *size, int *pos, int color);
void		draw_pixel(t_screen *idata, int *pos, int color);
void		draw_column(t_pane *pane, t_idraw *info);


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
void		render_textures(t_game *game, t_rayhit *hit, int screen_x);


/* Raycasting */

void		ray2(t_game *game, t_iray *iray, t_rayhit *hit);
t_rayhit	*ray(t_game *game, t_inst *inst, t_pane *pane, double camera_x, int w, double view, int color);


/* Debugging */

void		debug_ray(t_game *game, t_rayhit *hit, int color);


/* Validation */

int			check_args(t_game *game, int argc, char *argv[]);
int			map_loader(t_game *game, char *mapname);
int			map_setup_memory(t_game *game);
double		get_rotation(char rot);
int			map_read_loop(t_game *game, int fd);
int			get_textures(t_game *game, char **input);
int			get_skyfloor(t_game *game, char **arr, int sf);
int			build_map(t_game *game, int fd);
int			map_checker(t_game *game);


/* Other */

int			loop_handler(t_game *game);

#endif