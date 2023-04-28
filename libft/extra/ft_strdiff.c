/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdiff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 08:14:57 by tde-souz          #+#    #+#             */
/*   Updated: 2023/02/23 08:14:57 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strdiff(char *src, char sep)
{
	if (!src)
		return (0);
	return (ft_strlen(src) - ft_strlen(ft_strchr(src, sep)));
}
