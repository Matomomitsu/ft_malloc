/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:07:33 by mtomomit          #+#    #+#             */
/*   Updated: 2022/04/25 20:01:15 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*elem_new_lst;

	if (!lst)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		elem_new_lst = ft_lstnew(f(lst->content));
		if (!elem_new_lst)
		{
			ft_lstclear(&elem_new_lst, del);
			return (NULL);
		}
		else
			ft_lstadd_back(&new_lst, elem_new_lst);
		lst = lst->next;
	}
	return (new_lst);
}
