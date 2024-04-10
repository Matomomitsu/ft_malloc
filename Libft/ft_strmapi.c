/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 03:52:57 by mtomomit          #+#    #+#             */
/*   Updated: 2022/04/27 22:24:23 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	strlens;
	size_t	i;
	char	*str;

	i = 0;
	strlens = ft_strlen(s);
	str = (char *)malloc((strlens + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[strlens] = '\0';
	while (i < strlens)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
