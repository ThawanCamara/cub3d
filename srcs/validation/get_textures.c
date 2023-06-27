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

/* 
 * The first 'if' of tex_path is checking if it was already written, the
 * second checks if the memory allocation was successful.
 */

int	get_textures(t_game *game, char **arr)
{
	const char	*tab[] = {"NO\0", "SO\0", "WE\0", "EA\0", 0};
	int			i;

	i = -1;
	while (*(tab + ++i))
	{
		if (ft_strncmp(arr[0], tab[i], 3) == 0)
		{
			if (game->mapdata->texture[i].img != NULL)
				return (1);
			// for (size_t i = 0; i < ft_strlen(arr[1]); i++)
			// 	ft_printf("%d ", arr[1][i]);
			// ft_printf("\n");

			arr[1][ft_strlen(arr[1]) - 1] = 0; // Extraindo o carriage return

			// Debug
			// for (size_t i = 0; i < ft_strlen(arr[1]); i++)
			// 	ft_printf("%d ", arr[1][i]);
			// ft_printf("\n");
			// game->mapdata->texture[i] = ft_strdup(arr[1]);
			game->mapdata->texture[i].img = mlx_xpm_file_to_image(game->mlx,
				arr[1],&game->mapdata->texture[i].size[X],
				&game->mapdata->texture[i].size[Y]);
			game->mapdata->texture[i].addr = mlx_get_data_addr(game->mapdata->texture[i].img, &game->mapdata->texture[i].bpp, &game->mapdata->texture[i].len, &game->mapdata->texture[i].endian);
			// printf("size: %s\n", game->mapdata->texture[i]->addr);
			
			printf("%d>> %d\n", i, game->mapdata->texture[i].img == NULL);
			if (game->mapdata->texture[i].img == NULL || game->mapdata->texture[i].addr == NULL)
				return (1);
			return (0);
		}
	}
	return (0);
}