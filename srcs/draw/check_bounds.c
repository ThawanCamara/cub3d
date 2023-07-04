/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bounds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:11:19 by tde-souz          #+#    #+#             */
/*   Updated: 2023/04/30 16:11:19 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	check_bounds(int *pos, int *min, int *max)
{
	return (pos[X] >= min[X]
		&& pos[X] < max[X]
		&& pos[Y] >= min[Y]
		&& pos[Y] < max[Y]);
}

int	check_mapbounds(int *pos, int *bounds)
{
	return (pos[X] >= 0
		&& pos[X] < bounds[X]
		&& pos[Y] >= 0
		&& pos[Y] < bounds[Y]);
}
