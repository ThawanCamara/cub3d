/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:59:08 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/29 14:59:08 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	open_file(char *raw_name)
{
	int	fd;

	fd = open(raw_name, O_RDONLY);
	return (fd);
}

int	map_loader(t_game *game, char *mapname)
{
	int	fd;
	int	ret;

	if (map_setup_memory(game))
		return (1);
	fd = open_file(mapname);
	if (fd < 0)
		return (error_log(ERR_MAPREAD));
	ret = map_read_loop(game, fd);
	close(fd);
	return (ret);
}
