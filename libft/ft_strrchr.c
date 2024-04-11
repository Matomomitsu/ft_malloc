/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:30:00 by mtomomit          #+#    #+#             */
/*   Updated: 2022/04/21 04:55:37 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;
	long int	o;
	char		chr;

	o = -1;
	i = 0;
	chr = (char) c;
	while (s[i] != '\0')
	{
		if (s[i] == chr)
			o = i;
		i++;
	}
	if (s[i] == chr)
		return ((char *)&s[i]);
	if (o == -1)
		return (NULL);
	else
		return ((char *)&s[o]);
}
