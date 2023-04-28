/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:02:34 by tde-souz          #+#    #+#             */
/*   Updated: 2023/02/14 20:08:47 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*new_node;
	void	*temp;

	if (!f)
		return (0);
	new_head = 0;
	while (lst)
	{
		temp = f(lst->content);
		new_node = ft_lstnew(temp, lst->value);
		if (!new_node)
		{
			ft_lstclear(&new_head, del);
			del(temp);
			return (0);
		}
		ft_lstadd_back(&new_head, new_node);
		lst = lst->next;
	}
	return (new_head);
}
