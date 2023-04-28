/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_expand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:27:02 by tde-souz          #+#    #+#             */
/*   Updated: 2023/02/22 13:27:02 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strarr_expand(char **array, char *new)
{
	char	**ret;
	size_t	len;
	int		i;

	len = ft_strarr_size(array);
	ret = (char **)malloc(sizeof(char *) * (len + 2));
	i = len + 1;
	*(ret + i) = NULL;
	*(ret + --i) = ft_strdup(new);
	while (i-- > 0)
		*(ret + i) = ft_strdup(*(array + i));
	return (ret);
}
