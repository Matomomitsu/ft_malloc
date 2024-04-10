/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:16:50 by mtomomit          #+#    #+#             */
/*   Updated: 2022/04/05 21:43:11 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	strlen_dst;

	i = 0;
	strlen_dst = ft_strlen(dst);
	if (size <= strlen_dst)
		return (size + ft_strlen(src));
	while (size > strlen_dst + 1 + i && src[i] != '\0')
	{
		dst[strlen_dst + i] = src[i];
		i++;
	}
	dst[strlen_dst + i] = '\0';
	return (strlen_dst + ft_strlen(src));
}
