/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:18:54 by tde-souz          #+#    #+#             */
/*   Updated: 2023/02/22 18:18:54 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ctoa(char c)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * 2);
	if (ret == NULL)
		return (NULL);
	ret[0] = c;
	ret[1] = 0;
	return (ret);
}
