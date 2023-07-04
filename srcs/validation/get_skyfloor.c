/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_skyfloor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:37:31 by tde-souz          #+#    #+#             */
/*   Updated: 2023/06/05 13:37:31 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	debug_colors(t_game *game, int sf)
{
	printf("Red: %d\n", (game->mapdata->trgb[sf] >> 16) & 0xFF);
	printf("Green: %d\n", (game->mapdata->trgb[sf] >> 8) & 0xFF);
	printf("Blue: %d\n", (game->mapdata->trgb[sf]) & 0xFF);
}

static int	search_errors(char **arr)
{
	int	i;
	int	j;

	i = -1;
	while (arr[++i])
	{
		j = -1;
		while (arr[i][++j])
		{
			if (!ft_isdigit(arr[i][j]))
				return (1);
		}
	}
	return (0);
}

int	get_skyfloor(t_game *game, char **arr, int sf)
{
	char	**values;

	if (ft_strarr_size(arr) != 2)
		return (error_log("Too many arguments for TRGB input"));
	if (game->mapdata->valid_skyfloor[sf])
		return (error_log("Double attempt on writing TRGB"));
	arr[1][ft_strlen(arr[1]) - 1] = 0;
	values = ft_split(arr[1], ',');
	if (values == NULL)
		return (error_log("Failed allocation for TRGB processing"));
	if (ft_strarr_size(values) != 3 || search_errors(values))
	{
		ft_free_arr((void **)values);
		return (error_log("TRGB expects 3 values and only digits"));
	}
	game->mapdata->valid_skyfloor[sf] = 1;
	game->mapdata->trgb[sf] += ft_atoi(values[0]) << 16;
	game->mapdata->trgb[sf] += ft_atoi(values[1]) << 8;
	game->mapdata->trgb[sf] += ft_atoi(values[2]);
	ft_free_arr((void **)values);
	return (0);
}
