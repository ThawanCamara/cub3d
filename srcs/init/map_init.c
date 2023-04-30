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

int	map_init(t_game *game)
{
	header_log("Initialization", "Map", B_ORANGE);
	print_log(1, STR_BUILD_MAP);
	/* APLICAR A FUNÇÂO DO CUELHO */
	game->mapdata = malloc(sizeof(t_map));

	/* Inicialização temporaria */
	game->mapdata->path_no = ft_strdup("path_to_north");
	game->mapdata->path_so = ft_strdup("path_to_south");
	game->mapdata->path_we = ft_strdup("path_to_west");
	game->mapdata->path_ea = ft_strdup("path_to_east");
	game->mapdata->inst_rot = ft_strdup("NWWS");


	condition_log(game->mapdata != NULL, STR_BUILD_MAP_S, STR_BUILD_DATA_F);
	return (game->mapdata != NULL);
}

void	map_clear(t_game *game)
{
	header_log("Clear", "Map", B_YELLOW);
	//free(game->mapdata->map);
	free(game->mapdata->path_no);
	free(game->mapdata->path_so);
	free(game->mapdata->path_we);
	free(game->mapdata->path_ea);
	free(game->mapdata->inst_rot);
	free(game->mapdata);
	(void)game;
}
