/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:52:23 by mtomomit          #+#    #+#             */
/*   Updated: 2022/04/05 19:12:17 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	o;

	i = 0;
	if (little[i] == '\0')
	{
		return ((char *)&big[i]);
	}
	while (big[i] != '\0' && i < len)
	{
		o = 0;
		while (little[o] == big[i + o] && (i + o) < len)
		{
			if (little[o + 1] == '\0')
			{
				return ((char *)&big[i]);
			}
			o++;
		}
		i++;
	}
	return (NULL);
}
