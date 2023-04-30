/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:52:15 by tde-souz          #+#    #+#             */
/*   Updated: 2023/02/26 14:52:15 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Always return a m'allocated string or NULL
char	*ft_strinsert(char	*dst, char *graft, unsigned int start)
{
	char			*ret;
	unsigned int	len[2];
	unsigned int	i;

	if (dst == NULL)
		return (NULL);
	len[0] = ft_strlen (dst);
	if (graft == NULL)
		return (ft_strdup(dst));
	if (len[0] <= start)
		return (ft_strjoin(dst, graft));
	len[1] = ft_strlen (graft);
	ret = (char *)malloc(sizeof(char) * (len[0] + len[1] + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (*(dst + i))
	{
		if (i >= start && *graft != 0)
			*ret++ = *graft++;
		else
			*ret++ = *(dst + i++);
	}
	*ret = 0;
	return (ret - (len[0] + len[1]));
}
