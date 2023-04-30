/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:41:55 by tde-souz          #+#    #+#             */
/*   Updated: 2023/02/22 14:41:55 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	array_has_target(char **array, char *target);

char	**ft_strarr_remove(char **array, char *target)
{
	char	**ret;
	size_t	len;
	int		i;
	int		j;

	if (!array || !target || array_has_target(array, target) == 0)
		return (array);
	if (ft_strarr_size(array) == 1)
		return (NULL);
	len = ft_strlen(target);
	ret = (char **)malloc(sizeof(char *) * ft_strarr_size(array));
	i = -1;
	j = 0;
	while (*(array + ++i))
	{
		if (ft_strncmp(target, *(array + i), len) != 0)
		{
			*(ret + j) = ft_strdup(*(array + i));
			j++;
		}
	}
	*(ret + j) = NULL;
	return (ret);
}

static int	array_has_target(char **array, char *target)
{
	int		i;
	size_t	len;

	i = -1;
	len = ft_strlen(target);
	while (*(array + ++i))
		if (ft_strncmp(target, *(array + i), len) == 0)
			return (1);
	return (0);
}
