/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:52:53 by mtomomit          #+#    #+#             */
/*   Updated: 2024/05/08 21:46:14 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*malloc(size_t __size)
{
	void	*mem;

	ft_putstr_fd("malloc\n", 1);
	(void) __size;
	mem = NULL;
	if (mem == (void *) -1)
	{
		return (NULL);
	}
	else
	{
		return (mem);
	}
	ft_putstr_fd("malloc\n", 1);
}
