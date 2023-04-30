/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:47:22 by tde-souz          #+#    #+#             */
/*   Updated: 2023/02/02 11:47:22 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char **array, void (*f)())
{
	size_t	i;

	if (array == NULL || *array == NULL)
		return ;
	i = -1;
	while (*(array + ++i))
		f(*(array + i));
}
