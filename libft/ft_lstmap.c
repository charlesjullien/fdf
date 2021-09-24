/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:55:14 by cjullien          #+#    #+#             */
/*   Updated: 2021/09/15 17:50:51 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dest;
	t_list	*element;

	dest = NULL;
	while (lst && f)
	{
		element = ft_lstnew(f(lst->content));
		if (!element)
		{
			ft_lstclear(&dest, del);
			break ;
		}
		ft_lstadd_back(&dest, element);
		lst = lst->next;
	}
	return (dest);
}
