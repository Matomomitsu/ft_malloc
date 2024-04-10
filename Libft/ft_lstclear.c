/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:08:21 by mtomomit          #+#    #+#             */
/*   Updated: 2022/04/25 19:42:39 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list	**lst, void (*del)(void *))
{
	t_list	*templst;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		templst = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = templst;
	}
	*lst = NULL;
}
