/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:59:53 by mtomomit          #+#    #+#             */
/*   Updated: 2022/04/27 22:24:40 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	verificationchar(char const *str, char character)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (character == str[i])
			return (0);
		else
		i++;
	}
	return (1);
}

static size_t	countstr(char const *set, unsigned int *start, char const *s1)
{
	size_t	end;
	size_t	i;

	i = 0;
	while (verificationchar(set, s1[i]) != 1)
		i++;
	*start = i;
	end = ft_strlen(s1) - 1;
	while (verificationchar(set, s1[end]) != 1)
		end--;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			end;
	size_t			len;
	char			*new;
	size_t			i;

	start = 0;
	i = 0;
	end = countstr(set, &start, s1);
	len = end - start + 1;
	if (len == ft_strlen(s1))
	{
		new = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
		while (i <= ft_strlen(s1))
		{
			new[i] = s1[i];
			i++;
		}
		return (new);
	}
	else
		return (ft_substr(s1, start, len));
}
