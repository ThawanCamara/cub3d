/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:24:24 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/30 15:24:24 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	retrieve_addr(t_screen *tex);

/* 
 * The first 'if' of tex_path is checking if it was already written, the
 * second checks if the memory allocation was successful.
 */

int	get_textures(t_game *game, char **arr)
{
	const char	*tab[] = {"NO\0", "SO\0", "WE\0", "EA\0", 0};
	const t_map	*map = game->mapdata;
	int			i;

	i = -1;
	arr[1][ft_strlen(arr[1]) - 1] = 0;
	while (*(tab + ++i))
	{
		if (ft_strncmp(arr[0], tab[i], 3) == 0)
		{
			if (game->mapdata->texture[i].img != NULL)
				return (error_log("Duplicated texture information."));
			map->texture[i].img = mlx_xpm_file_to_image(game->mlx,
					arr[1], &game->mapdata->texture[i].size[X],
					&game->mapdata->texture[i].size[Y]);
			if (map->texture[i].img == NULL)
				return (error_log("Unable to retrieve texture file."));
			if (retrieve_addr(&map->texture[i]))
				return (error_log("Unable to retrieve texture content."));
			return (0);
		}
	}
	return (error_log("Invalid texture information."));
}

static int	retrieve_addr(t_screen *tex)
{
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->len, &tex->endian);
	return (tex->addr == NULL);
}
