/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:13:08 by tde-souz          #+#    #+#             */
/*   Updated: 2023/03/01 15:13:08 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_straddchar(char *src, char c)
{
	char	*ret;
	size_t	len;

	if (c == 0)
		return (src);
	len = ft_strlen(src);
	ret = (char *)malloc(sizeof(char) * (len + 2));
	ft_strlcpy(ret, src, len + 1);
	ret[len] = c;
	ret[len + 1] = 0;
	return (ret);
}
