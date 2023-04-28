/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:55:59 by tde-souz          #+#    #+#             */
/*   Updated: 2023/04/28 08:30:59 by tde-souz         ###   ########.fr       */
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
# include "colortag.h"

// ****************************************************************************
// *                                  DEFINES                                 *
// ****************************************************************************

//# ifndef TITLE
//#  define TITLE			"SILENT VIRAS"
//# endif
# define SCREEN_WIDTH	800
# define SCREEN_HEIGHT	600

// ****************************************************************************
// *                                  STRUCTS                                 *
// ****************************************************************************

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
}	t_map;

typedef struct s_cam
{
	double	rotation;

}	t_cam;

/* Separar Render entre Game e Instance, Instance ficando responsavel pela gestão de dados de cada janela */
typedef struct s_render
{
	void		*mlx;
	void		*win;
	void		*nwin;
	int			screen_width;
	int			screen_height;
	const char*	title;
}	t_render;

typedef struct s_game
{
	t_render	*render;
	t_map		*map;
	t_cam		*cam;
}	t_game;

const void	**config_table_builder(void);
void	init_handler(t_game *game);

int		data_init(t_game *game);
void	data_clear(t_game *game);
void	safe_exit(t_game *game);

int		render_init(t_game *game);
void	render_clear(t_game *game);

#endif