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


// 0 - esq
// 2 - dir
// 4 - cima
// 6 - baixo

int	ray_get_face(int step, int side)
{

	if (side == 0)
	{
		// x
		if (step == -1) //
			return (WEST);
			// 0
		else
			return (EAST);
		// if (step == 1)
			// 2
	}
	else
	{
		// y
		if (step == -1)
			return (NORTH);
			// 4
		else
			return (SOUTH);
		// if (step == 1)
			// 6
	}
	// if (side == 1)
}