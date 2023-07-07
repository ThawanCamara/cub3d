/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:21:22 by tde-souz          #+#    #+#             */
/*   Updated: 2023/07/04 19:21:22 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	ray_get_face(int step, int side)
{
	if (side == 0)
	{
		if (step == -1)
			return (WEST);
		else
			return (EAST);
	}
	else
	{
		if (step == -1)
			return (NORTH);
		else
			return (SOUTH);
	}
}
