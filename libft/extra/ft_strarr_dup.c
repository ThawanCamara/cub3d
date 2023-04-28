/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:33:53 by tde-souz          #+#    #+#             */
/*   Updated: 2023/02/22 13:33:53 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strarr_dup(char **arr)
{
	char	**ret;
	int		i;

	if (arr == NULL || *arr == NULL)
		return (NULL);
	i = 0;
	while (arr[i] != NULL)
		i++;
	ret = (char **)malloc(sizeof(char *) * ++i);
	ret[--i] = NULL;
	while (--i >= 0)
		ret[i] = ft_strdup(arr[i]);
	return (ret);
}
