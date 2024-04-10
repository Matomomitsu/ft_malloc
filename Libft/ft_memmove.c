/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:54:01 by mtomomit          #+#    #+#             */
/*   Updated: 2022/04/17 21:52:29 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tempsrc;
	unsigned char	*tempdest;

	tempsrc = (unsigned char *)src;
	tempdest = (unsigned char *)dest;
	i = 1;
	if (tempsrc < tempdest)
	{
		while (i <= n)
		{
			tempdest[n - i] = tempsrc[n - i];
			i++;
		}
	}
	else
		ft_memcpy(dest, tempsrc, n);
	return (dest);
}
