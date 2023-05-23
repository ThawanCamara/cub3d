/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 01:20:48 by tde-souz          #+#    #+#             */
/*   Updated: 2023/04/29 01:20:48 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

const char **get_map(void)
{
	// static const char *map[] = 
	// {
	// 	"11111",
	// 	"10001",
	// 	"1N011",
	// 	"10011",
	// 	"11111",
	// 	NULL
	// };
	// static const char *map[] = 
	// {
	// 	"1111111111",
	// 	"1000000001",
	// 	"1000N00101",
	// 	"1000000001",
	// 	"1000000001",
	// 	"1000000001",
	// 	"1000000001",
	// 	"1000000001",
	// 	"1000000001",
	// 	"1111111111",
	// 	NULL
	// };
	static const char *map[] = 
	{
		"111111111111111111111111111111111111111111111111",
		"100000000000000000000000000000000000000000000001",
		"100100000000000000000000000000000000000000001001",
		"1000000000000000000N0000000000000000000000000001",
		"100100000000000000000000000000000000000000001001",
		"100000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000001",
		"100100000000000000000000000000000000000000001001",
		"100100000000000000000000000000000000000000001001",
		"100100000000000000000000000000000000000000001001",
		"100100000000000000000000000000000000000000001001",
		"100100000000000000000000000000000000000000001001",
		"100100000000000000000000000000000000000000001001",
		"100100000000000000000000000000000000000000001001",
		"100100000000000000000000000000000000000000001001",
		"100100000000000000000000000000000000000000001001",
		"100100000000000000000000000000000000000000001001",
		"100100000000000000000000000000000000000000001001",
		"100100000000000000000000000000000000000000001001",
		"100100000000000000000000000000000000000000001001",
		"100100000000000000000000000000000000000000001001",
		"100100000000000000000000000000000000000000001001",
		"100100000000000000000000000000000000000000001001",
		"100100000000000000000000000000000000000000001001",
		"100100000000000000000000000000000000000000001001",
		"100100000000000000000000000000000000000000001001",
		"100100000000000000000000000000000000000000001001",
		"100100000000000000000000000000000000000000001001",
		"100100000000000000000000000000000000000000001001",
		"100100000000000000000000000000000000000000001001",
		"100100000000000000000000000000000000000000001001",
		"100100000000000000000000000000000000000000001001",
		"100100000000000000000000000000000000000000001001",
		"111111111111111111111111111111111111111111111111",
		NULL
	};
	return ((const char **)map);
}
static int	validate_textures(char **textures)
{
	return (textures[NORTH] &&
		textures[SOUTH] &&
		textures[WEST] &&
		textures[EAST]);
}

int	map_init(t_game *game)
{
	header_log("Initialization", "Map", B_ORANGE);
	print_log(1, STR_BUILD_MAP);
	game->mapdata = (t_map *)malloc(sizeof(t_map));
	if (game->mapdata)
		game->mapdata->tex_path = (char **)malloc(sizeof(char *) * 5);
	if (!game->mapdata || !game->mapdata->tex_path)
		return (assert_log(0, STR_BUILD_MAP_S, STR_BUILD_DATA_F));
	/* Inicialização temporaria */
	game->mapdata->tex_path[NORTH] = ft_strdup("assets/textures/darkcube2d_3.xpm");
	game->mapdata->tex_path[SOUTH] = ft_strdup("path_to_south");
	game->mapdata->tex_path[WEST] = ft_strdup("path_to_west");
	game->mapdata->tex_path[EAST] = ft_strdup("path_to_east");
	game->mapdata->tex_path[4] = NULL;
	game->mapdata->inst_rot = ft_strdup("EW");
	game->mapdata->trgb[SKY] = 0x00505065;
	game->mapdata->trgb[FLOOR] = 0x00666666;

	game->mapdata->map = (char **)get_map();
	game->mapdata->size[X] = ft_strlen(game->mapdata->map[0]);
	game->mapdata->size[Y] = ft_strarr_size(game->mapdata->map);
	game->mapdata->start_pos = (int *)malloc(sizeof(int) * (2 * game->total_insts));
	// game->mapdata->start_pos[X] = 19;
	// game->mapdata->start_pos[Y] = 3;
	game->mapdata->start_pos[X] = 6;
	game->mapdata->start_pos[Y] = 6;
	if (game->total_insts > 1)
	{
		game->mapdata->start_pos[X + 2] = 5;
		game->mapdata->start_pos[Y + 2] = 4;
	}
	/*  */
	assert_log(validate_textures(game->mapdata->tex_path),
		STR_BUILD_MAP_S, STR_BUILD_DATA_F);
	return (game->mapdata != NULL);
}

void	map_clear(t_game *game)
{
	header_log("Clear", "Map", B_YELLOW);
	//free(game->mapdata->map);
	ft_free_arr((void **)game->mapdata->tex_path);
	free(game->mapdata->inst_rot);
	free(game->mapdata->start_pos);
	free(game->mapdata);
}
