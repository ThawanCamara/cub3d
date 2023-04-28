/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:24:53 by tde-souz          #+#    #+#             */
/*   Updated: 2023/02/22 13:24:53 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strarr_size(char **array)
{
	size_t	size;
	int		i;

	if (array == NULL)
		return (0);
	size = 0;
	i = -1;
	while (*(array + ++i))
		size++;
	return (size);
}
