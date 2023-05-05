/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 21:11:41 by tde-souz          #+#    #+#             */
/*   Updated: 2023/05/04 21:11:41 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	draw_pixel(t_imgdata *idata, int *pos, int color)
{
	char	*dst;

	dst = idata->addr + (pos[Y] * idata->len + pos[X] * (idata->bpp / 8));
	*(unsigned int*)dst = color;
}
