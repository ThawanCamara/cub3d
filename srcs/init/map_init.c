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

const char **get_map()
{
	static const char *map[7] = 
	{
		"1111111111111111",
		"1000000000000001",
		"1001000000001001",
		"10000000N0000001",
		"1001000000001001",
		"1000000000000001",
		"1111111111111111"
	};
	return ((const char **)map);
}

int	map_init(t_game *game)
{
	header_log("Initialization", "Map", B_ORANGE);
	print_log(1, STR_BUILD_MAP);
	game->mapdata = (t_map *)malloc(sizeof(t_map));
	if (!game->mapdata)
		return (0);
	game->mapdata->tex_path = (char **)malloc(sizeof(char *) * 5);
	if (!game->mapdata->tex_path)
		return (0);

	/* Inicialização temporaria */
	game->mapdata->tex_path[NORTH] = ft_strdup("assets/textures/darkcube2d_3.xpm");
	game->mapdata->tex_path[SOUTH] = ft_strdup("path_to_south");
	game->mapdata->tex_path[WEST] = ft_strdup("path_to_west");
	game->mapdata->tex_path[EAST] = ft_strdup("path_to_east");
	game->mapdata->tex_path[4] = NULL;
	game->mapdata->inst_rot = ft_strdup("NW");
	condition_log(game->mapdata->tex_path[NORTH] &&
		game->mapdata->tex_path[SOUTH] &&
		game->mapdata->tex_path[WEST] &&
		game->mapdata->tex_path[EAST],
		STR_BUILD_MAP_S, STR_BUILD_DATA_F);
	game->mapdata->map = (char **)get_map();
	return (game->mapdata != NULL);
}

void	map_clear(t_game *game)
{
	header_log("Clear", "Map", B_YELLOW);
	//free(game->mapdata->map);
	ft_free_arr((void **)game->mapdata->tex_path);
	free(game->mapdata->inst_rot);
	free(game->mapdata);
	(void)game;
}
