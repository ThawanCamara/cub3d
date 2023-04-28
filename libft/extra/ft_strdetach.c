/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdetach.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:53:18 by tde-souz          #+#    #+#             */
/*   Updated: 2023/02/26 14:53:18 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_detach(char	*str, int start, int end)
{
	char	*ret;
	int		i;

	if (str == NULL)
		return (NULL);
	if ((end - start + 1) <= 0)
		return (str);
	ret = (char *)malloc(sizeof(char) * ft_strlen(str) - (end - start + 1) + 1);
	i = -1;
	while (*(str + ++i))
	{
		if (i < start || i > end)
		{
			*ret = *(str + i);
			ret++;
		}
	}
	*ret = 0;
	return (ret - (ft_strlen(str) - (end - start + 1)));
}
