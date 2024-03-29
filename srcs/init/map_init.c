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

const char	**get_map(void)
{
	static const char	*map[] = {
		"111111111111111111111111111111111111111111111111",
		"100000000000000000000000000000000000000000000001",
		"100100000000000000000000000000000000000000001001",
		"1000000000000000000N0000000000000000000000000001",
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

int	map_init(t_game *game)
{
	char	valid;

	header_log("Initialization", "Map", B_ORANGE);
	print_log(1, STR_BUILD_MAP);
	game->mapdata = NULL;
	valid = map_loader(game, game->mapname);
	assert_log(game->mapdata->texture && valid == 0,
		STR_BUILD_MAP_S, STR_BUILD_DATA_F);
	return (game->mapdata != NULL && valid == 0);
}

void	map_clear(t_game *game)
{
	size_t	i;

	header_log("Clear", "Map", B_YELLOW);
	ft_free_arr((void **)game->mapdata->map);
	if (game->mapdata)
	{
		i = 0;
		while (i < 4)
		{
			if (game->mapdata->texture[i].img != NULL)
				mlx_destroy_image(game->mlx, game->mapdata->texture[i].img);
			i++;
		}
		free(game->mapdata->texture);
		free(game->mapdata->start_pos);
	}
	free(game->mapdata);
}
